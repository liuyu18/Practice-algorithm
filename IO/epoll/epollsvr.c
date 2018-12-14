#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static int create_and_bind(char *port);
static int set_socket_non_block(int sfd);

#define MAX_EVENTS 64
#define BUF_SIZE 1024

static int nio_write(int fd,char *buf,int len){
    int write_pos = 0;
    int left_len = len;
    while(left_len > 0){
        int write_len = 0;
        if((write_len = write(fd,buf + write_pos,left_len)) <= 0){
            if(errno == EAGAIN){
                write_len = 0;
            }else{
                return -1;
            }
        }
        left_len -= write_len;
        write_pos += write_len;
    }
    return len;
}

static int create_and_bind(char *port){
    struct addrinfo hint,*result;
    int res,sfd;
    memset(&hint,0,sizeof(struct addrinfo));
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;
    hint.ai_flags = AI_PASSIVE;
    res = getaddrinfo(NULL,port,&hint,&result);
    if(res == -1){
        perror("error : can not get address info!\n");
        exit(1);
    }
    sfd = socket(result->ai_family,result->ai_socktype,result->ai_protocol);
    if(sfd == -1){
        perror("error : can not get socket descriptor\n");
        exit(1);
    }
    res = bind(sfd,result->ai_addr,result->ai_addrlen);
    if(res == -1){
        perror("error : can not bind the socket\n");
        exit(1);
    }
    freeaddrinfo(result);
    return sfd;
}
static int set_socket_non_block(int sfd){
    int flag,res;
    flag = fcntl(sfd,F_GETFL);
    if(flag == -1){
        perror("error : cannot get socket flags!\n");
        exit(1);
    }
    flag |= 0_NONBLOCK;
    res = fcntl(sfd,F_SETFL,flag);
    if(res == -1){
        perror("error : cannot set socket flags!\n");
        exit(1);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int sfd, res,epoll,cnt,i,sd;
    struct epoll_event event,events[MAX_EVENTS];
    if(argc != 2{
        perror("usage : port\n");
        exit;
    }
    sfd = create_and_bind(argv[1]);
    if(sfd == -1){
        perror("error : can not create socket\n");
        exit(1);
    }
    res = set_socket_non_block(sfd);
    if(res == -1){
        perror("error : can not set flag\n");
        exit(1);
    }
    res = listen(sfd,SOMAXCONN);
    if(res == -1){
        perror("error : cannot listen\n");
        exit(1);
    }
    epoll = epoll_create(1);
    if(epoll == -1){
        perror("error : cannot create epoll\n");
        exit(1);
    }
    event.events = EPOLLIN | EPOLLOUT | EPOLLET;
    event.data.fd = sfd;
    res = epoll_ctl(epoll,EPOLL_CTL_ADD,sfd,&event);
    if(res == -1){
        perror("error : can not add event to epoll!\n");
        exit(1);
    }
    while(1){
        cnt = epoll_wait(epoll,events,MAX_EVENTS,-1);
        for(i = 0; i< cnt;i++){
            if ((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP)
                || !(events[i].events & EPOLLIN)){
                perror("error : socket fd error!\n");
                close(events[i].data.fd);
                continue;
            }else if(events[i].data.fd == sfd){
                while(1){
                    struct sockaddr client_addr;
                    int addrlen = sizeof(struct sockaddr);
                    sd = accept(sfd, &client_addr, &addrlen);
                    if(sd == -1){
                        if(errno == EAGAIN || errno == EWOULDBLOCK){
                            break;
                        }else{
                            perror("error : cannot accpet new socket\n");
                            continue
                        }
                    }
                    res = set_socket_non_block(sd);
                    if(res == -1){
                        perror("error : cannot set flags!\n");
                        exit(1);
                    }
                    event.data.fd = sd;
                    event.events = EPOLLET | EPOLLIN;
                    res = epoll_ctl(epoll,EPOLL_CTL_ADD,sd,&event);
                    if(res == -1){
                        perror("error : cannot add the epoll\n");
                        exit(1);
                    }
                }
            }else{
                int cnt;
                char buf[BUF_SIZE] = {0};
                while(1){
                    memset(buf,0,sizeof(buf));
                    cnt = read(events[i].data.fd,buf,BUF_SIZE);
                    if(cnt == -1){
                        if(errno == EAGAIN){
                            break;
                        }
                        perror("error : read error\n");
                        exit(1);
                    }else if(cnt == 0){
                        close(events[i].data.fd);
                    }

                    printf("receive client data : %s\n", buf);
                    nio_write(events[i].data.fd, buf, strlen(buf));
                    break;
                }
            }
        }
    }
    close(fd);
    return 0;
}


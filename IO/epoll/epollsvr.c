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
    
}
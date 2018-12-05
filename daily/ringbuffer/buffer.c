#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "ringbuffer.h"

//这个表示一个方法的返回值只由参数决定，如果参数不变的话，就不再调用此函数，直接返回值。
static inline __attribute__((const)) static bool is_power_of_2(unsigned long n)
{
    return (n != 0 && ((n & (n - 1)) == 0));
}
static unsigned long roundup_power_of_two(unsigned long n)
{
    if ((n & (n - 1)) == 0)
        return n;

    unsigned long maxulong = (unsigned long)((unsigned long)~0);
    unsigned long andv = ~(maxulong & (maxulong >> 1));

    while ((andv & n) == 0)
        andv = andv >> 1;

    return andv << 1;
}
struct ringbuffer *ringbuffer_create(unsigned int bytes)
{
    struct ringbuffer *ring_buf;

    if (!is_power_of_2(size))
    {
        size = roundup_power_of_two(n);
    }

    ring_buf = malloc(sizeof(*ring_buf));
    if (!ring_buf)
    {
        perror("malloc()");
        return NULL;
    }

    ring_buf->data = malloc(size);
    if (!ring_buf->data)
    {
        perror("malloc()");
        free(ring_buf);
        return NULL;
    }

    ring_buf->size = size;
    ring_buf->read_pos = 0;
    ring_buf->write_pos = 0;

    return ring_buf;
}
void ringbuffer_destroy(struct ringbuffer *ring_buf);
void ringbuffer_reset(struct ringbuffer *ring_buf);
void ringbuffer_put(struct ringbuffer *ring_buf, const char *buf, unsigned int len);
void ringbuffer_get(struct ringbuffer *ring_buf, const char *buf, unsigned int len);
void ringbuffer_print(struct ringbuffer *ring_buf, unsigned int cnt);
ssize_t ringbuffer_from_dev(int fd, struct ringbuffer *ring_buf, unsigned int len);
unsigned int ringbuffer_is_empty(struct ringbuffer *ring_buf);
unsigned int ringbuffer_is_full(struct ringbuffer *ring_buf);
unsigned int ringbuffer_len(struct ringbuffer *ring_buf);
unsigned int ringbuffer_space_left(struct ringbuffer *ring_buf);
unsigned int ringbuffer_to_socket(int socket_fd, struct ringbuffer *ring_buf, unsigned int len);

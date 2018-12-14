
#ifndef _ASYNC_QUEUE_INTERLER_H_
#define _ASYNC_QUEUE_INTERLER_H_

#include "queue.h"

#include <pthread.h>


typedef struct async_queue{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int waiting_threads;
    queue_t *queue;
    int quit;
    int efd;
    int epollfd;
    long long tasked;
}async_queue_t;

typedef struct async_cond_op{
    const char* name; // such as cond, eventfd, lock free and so on.
    async_queue_t* (*create)(int size);
    BOOL  (*push)(async_queue_t* queue, task_t* t);
    task_t* (*pop)(async_queue_t* queue, int timeout);
    void  (*free)(async_queue_t* q);
    BOOL  (*empty)(async_queue_t* q);
    BOOL  (*destory)(async_queue_t* q);
}async_cond_op_t;
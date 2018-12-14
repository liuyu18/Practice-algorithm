#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <pthread.h>
#include "async_queue_interner.h"
#include "glo_def.h"


#define MAX_THREAD_POOL_SIZE  128
#define MAX_QUEUE_SIZE        65536

typedef struct threadpool {
  pthread_t* threads;
  const async_queue_op_t* qop;
  async_queue_t* queue;
  int qsize;
  int tsize;
  int shutdown;
  int started;
}threadpool_t;

typedef enum
{
    threadpool_cond_type     = 0,
    threadpool_eventfd_type  = 1
}threadpool_type_t;

typedef enum
{
    threadpool_invalid        = -1,
    threadpool_lock_failure   = -2,
    threadpool_queue_full     = -3,
    threadpool_shutdown       = -4,
    threadpool_thread_failure = -5,
    threadpool_memory_error   = -6
} threadpool_error_t;

typedef enum
{
    immediate_shutdown = 1,
    graceful_shutdown  = 2
} threadpool_shutdown_t;

typedef enum
{
    threadpool_graceful       = 1
} threadpool_destroy_flags_t;

#ifdef __cplusplus
extern "C" {
#endif

BOOL threadpool_config(threadpool_type_t type);
threadpool_t* threadpool_create(int thread_count, int queue_size, int flags);
int threadpool_add(threadpool_t *pool, void* (*routine)(void *), void *arg);
int threadpool_destroy(threadpool_t *pool, int flags);
#ifdef __cplusplus
}
#endif


#endif


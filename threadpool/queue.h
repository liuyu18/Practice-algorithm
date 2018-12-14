

typedef struct queue_task{
    void* (*run)(void *);
    void* argv;
}task_t;

typedef struct queue{
    int head;
    int tail;
    int size;
    int capcity;
    task_t* tasks;
}queue_t;


queue_t *queue_create(int size);
BOOL queue_is_full(queue_t *q);
BOOL queue_is_empty(queue_t *q);
BOOL queue_push_tail(queue_t *q);
task_t *queue_pop_head(queue_t *q);
void queue_free(queue_t);
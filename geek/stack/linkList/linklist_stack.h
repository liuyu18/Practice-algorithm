

typedef struct _linkliststack
{
	int data;
	struct _linkliststack *next;
}linklist_stack;


#define stack_is_empty(liststack) (liststack->next == NULL)

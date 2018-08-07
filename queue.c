#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct QUEUE queue;

struct QUEUE
{
	int current_size;
	int head;
	int tail;
	int numbers[MAX_SIZE];
};

queue* create_q()
{
	queue* new_q=(queue*) malloc(sizeof(queue));
	new_q->current_size = 0;
	new_q->head = 0;
	new_q->tail = MAX_SIZE-1;
	return new_q; 
}
void enqueue(queue * queue,int element)
{
	if(queue->current_size >= MAX_SIZE) printf("Overflow\n");
	else
	{
		queue->tail = (queue->tail+1) % MAX_SIZE;
		queue->numbers[queue->tail] = element;
		queue->current_size++;
	}
}
int is_empty(queue *head)
{
	return (head == NULL);
}
int dequeue(queue *queue)
{
	int dequeue;
	if(is_empty(queue))
	{
		printf("Underflow\n");
	}
	else
	{
		dequeue = queue->numbers[queue->head];
		queue->head = (queue->head +1) % MAX_SIZE;
		queue->current_size--;
		return dequeue;
	}
}
int main(int argc, char const *argv[])
{
	queue* queue = create_q();
	int *elements,i,size;
	scanf("%d",&size);
	elements = malloc(size * (sizeof(int)));
	for(i=0; i < size;i++)
	{
		scanf("%d",&elements[i]);
		enqueue(queue,elements[i]);
	}
	for(i=0;i < size;i++)
	{
		printf("%d\n",dequeue(queue));
	}
	return 0;
}
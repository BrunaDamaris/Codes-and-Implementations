#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct PQUEUE priority_q;
typedef struct NODE node;
struct NODE
{
    int element;
    int priority;
    node* next;
};
struct PQUEUE
{
    node* head;
};
priority_q* create_p_q()
{
    priority_q* p_q = (priority_q*) malloc(sizeof(priority_q));
    node *new = (node*) malloc(sizeof(node));
    new->priority = 0;
    p_q->head = new;
    return p_q;
}
void enqueue(priority_q* priority_queue,int element,int pr)
{
    node *new = (node*) malloc(sizeof(node));
    new->element = element;
    new->priority = pr;
    if((priority_queue->head != NULL) && (pr > priority_queue->head->priority))
    {
        new->next = priority_queue->head;
        priority_queue->head = new;
    }
    else
    {
        node* now = priority_queue->head;
        while((now->next != NULL) && (now->next->priority > pr))
        {
            now = now->next;
        }
        new->next = now->next;
        now->next = new;
    }
}
node* dequeue(priority_q* priority_queue)
{
    if((priority_queue->head == NULL))
    {
        printf("Underflow\n");
        return NULL;
    }
    else{
        node* aux = priority_queue->head;
        priority_queue->head = priority_queue->head->next;
        aux->next = NULL;
        return aux;
    }
}
int maximum(priority_q* priority_queue)
{
    if(priority_queue->head == NULL)
    {
        printf("Undeflow\n");
        return -1;
    }
    else{
        return priority_queue->head->element;
    }
}
int main()
{
    priority_q* p_q = create_p_q();
    int num=0,i,size,pr;
    scanf("%d",&size);
    for(i=0;i < size;i++)
    {
        scanf("%d%d",&num,&pr);
       enqueue(p_q,num,pr);
    }
    printf("%d!!\n",maximum(p_q));
    return 0;
}
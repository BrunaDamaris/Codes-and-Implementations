#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10000

typedef struct LIST list;
typedef struct GRAPH graph;
typedef struct QUEUE queue;
struct LIST
{
    int item;
    list *next;
};

struct GRAPH
{
    int visited[MAX_SIZE];
    list* vertices[MAX_SIZE];
};

struct QUEUE
{
    int head;
    int tail;
    int size;
    int numbers[MAX_SIZE];
};

list* create_list(int item)
{
    list* new_list = (list*) malloc(sizeof(list));
    new_list->item = item;
    new_list->next = NULL;
    return new_list;
}
graph* create_graph()
{
    int i;
    graph* gr = (graph*) malloc(sizeof(graph));
    for(i = 0 ;i < MAX_SIZE; i++)
    {
        gr->vertices[i] = NULL;
        gr->visited[i] = 0;
    }
    return gr;

}
queue* create_queue()
{
    queue* q = (queue*) malloc(sizeof(queue));
    q->head = 0;
    q->tail = MAX_SIZE - 1;
    q->size = 0;
    return q;
}

int is_empty(queue* queue)
{
    if(queue->size == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void enqueue(queue * queue,int element)
{
	if(queue->size >= MAX_SIZE) printf("Overflow\n");
	else
	{
		queue->tail = (queue->tail+1) % MAX_SIZE;
		queue->numbers[queue->tail] = element;
		queue->size++;
	}
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
		queue->size--;
		return dequeue;
	}
}
void addtoedge(graph* gr,int item1,int item2)
{
    list *new_vertex = create_list(item2);
    new_vertex->next = gr->vertices[item1];
    gr->vertices[item1] = new_vertex;
    new_vertex = create_list(item1);
    new_vertex->next = gr->vertices[item2];
    gr->vertices[item2] = new_vertex;
}

void dfs(graph* gr,int begin)
{
    gr->visited[begin] = 1;
    printf("%d\n",begin);
    list* new_list = gr->vertices[begin];
    while(new_list != NULL)
    {
        if(gr->visited[new_list->item] != 1)
        {
            dfs(gr,new_list->item);
        }
        new_list = new_list->next;
    }
}

void bfs(graph* gr,int begin)
{
    queue* queue = create_queue();
    int deq;
    list* new_list = gr->vertices[begin];
    while(!(is_empty(queue)))
    {
        deq = dequeue(queue);
        new_list = gr->vertices[deq];
        while(new_list != NULL)
        {
            if(!(gr->visited[new_list->item]))
            {
               printf("%d\n",new_list->item);
                gr->visited[new_list->item] = 1;
                enqueue(queue,new_list->item);
            }
            new_list = new_list->next;
        }
    }
}

/*void print_graph(graph* gr)
{
    list* new_list = gr->visited
}*/
int main()
{
    graph* graph = create_graph();
    int i=0,size=0,num,num1;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        scanf("%d%d",&num,&num1);
        addtoedge(graph,num,num1);
    }
    return 0;
}
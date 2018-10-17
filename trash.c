//683(DFS)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct LIST list;
typedef struct GRAPH graph;
typedef struct DIC dictionary;

struct LIST
{
    char item[MAX_SIZE];
    list *next;
};

struct GRAPH
{
    int visited[MAX_SIZE];
    list* vertices[MAX_SIZE];
};

struct DIC{
    char d[MAX_SIZE];
};

list* create_list(char item[])
{
    list* new_list = (list*) malloc(sizeof(list));
    strcpy(new_list->item,item);
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

dictionary* create_dictionary()
{
    dictionary* d = (dictionary*) malloc(sizeof(dictionary));
    int i = 0 , j = 0;
    char c;
    for(i = 48,j = 0; i <=90 ;i++,j++)
    {
        c = i;
        d->d[j] = c;
    }
    return d;
}

int getindex(char item[],dictionary* d)
{
    int i,j;
    int index = 0;
    if(strlen(item) >= 4)
    {
        for(i = 0; i < 3;i++)
        {
            for(j = 0;j < 43;j++)
            {
                if(item[i] == d->d[j]) 
                {
                    index += j;
                }
            }   
        }
        int numbers = 0;
        for(i = 3;i < strlen(item);i++)
        {
            numbers = numbers*10 +(item[i] - '0');
        }
        //printf("%d\\",numbers);
        index += numbers;  
    }
    else{
        for(i = 0; i < strlen(item);i++)
        {
            for(j = 0;j < 43;j++)
            {
                if(item[i] == d->d[j]) 
                {
                    index += j;
                }
            }   
        }
    }
    //printf("%d\n",index); 
    return index;
}

void addtoedge(graph* gr,char item1[],char item2[],dictionary* d)
{
    list *new_vertex = create_list(item2);
    int item1ind = getindex(item1,d);
    new_vertex->next = gr->vertices[item1ind];
    gr->vertices[item1ind] = new_vertex;
    new_vertex = create_list(item1);
    int item2ind = getindex(item2,d);
    new_vertex->next = gr->vertices[item2ind];
    gr->vertices[item2ind] = new_vertex;
}

void dfs(graph* gr,char begin[],dictionary* d)
{
    int index = getindex(begin,d);
    gr->visited[index] = 1;
    printf("%s\n",begin);
    list* new_list = gr->vertices[index];
    while(new_list != NULL)
    {
        int index1 = getindex(new_list->item,d);
        if(gr->visited[index1] != 1)
        {
            dfs(gr,new_list->item,d);
        }
        new_list = new_list->next;
    }
}

void print_graph(graph* gr)
{
    int i = 0;
    while(i < MAX_SIZE)
	{
		if(gr->vertices[i] != NULL)
		{
			//printf("%d -> ",i);
			printf("%s -> ",gr->vertices[i]->item);
			if(gr->vertices[i]->next != NULL)
			{
				while(gr->vertices[i]->next != NULL)
				{	
					printf("%s -> ",gr->vertices[i]->next->item);
					gr->vertices[i]->next = gr->vertices[i]->next->next;
				}
				i++;
			}
			else{
				i++;
			}
			printf("\\\n");
		}
		else
		{
			//printf("%d -> \\\n",i);
			i++;
		}
}
}

int main()
{
    int i=0,size=0,num,num1;
    char str[MAX_SIZE],str1[MAX_SIZE];
    dictionary* d = create_dictionary();
    while(scanf("%d",&size) != EOF)
    {
        graph* graph = create_graph();
        while(size--)
        {
            getchar();
            scanf("%s",str);
            scanf("%s",str1);
            addtoedge(graph,str,str1,d);
        }
        print_graph(graph);
        //dfs(graph,str,d);
    }
    return 0;
}
//221(tarzan)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
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

void dfs(graph* gr,int begin,int prev,int *max)
{
    int current  = 0;
    gr->visited[begin] = 1;
    printf("%d\n",begin);
    list* new_list = gr->vertices[begin];
    while(new_list != NULL)
    {
        if(gr->visited[new_list->item] != 1)
        {
            current = prev + ;
            dfs(gr,new_list->item,current,max);
        }
        new_list = new_list->next;
        if ((*max) < current) *max = current;  
        current = 0; 
    }
}
  
int longestCable(graph* gr,int n) 
{
    int max_len = INT_MIN; 

    for (int i=0; i<n; i++) 
    { 
        gr->visited[i] = 0; 
        dfs(gr, i, 0, &max_len); 
    } 
    return max_len; 
} 

int main()
{
    graph* graph = create_graph();
    int reach=0,cases=0,num,num1,i,yes= 0;
    int cont = 0;
    scanf("%d%d",&cases,&reach);
    int go = cases;
    while(cases--)
    {
        scanf("%d%d",&num,&num1);
        addtoedge(graph,num,num1);
    }
    cont = longestCable(graph,go);
    printf("Cont: %d\n",cont);
    if(cont >= reach) printf("S\n");
    else printf("N\n");
    return 0;
}

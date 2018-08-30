#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100000

typedef struct HEAP heap;
struct HEAP 
{
    int size;
    int items[MAX_SIZE];
};

heap* create_h();

void enqueue(heap *heap, int element);

int dequeue(heap* heap);

void printf_heap(heap* heap);

int get_parent_i(heap* heap,int i);

int get_left_i(heap* heap,int i);

int get_right_i(heap* heap,int i);

void max_hfy(heap* heap,int i);

int element_of(heap* heap,int i);

void heapsort(heap* heap);

int main()
{
    heap* heap = create_h();
    int size,num,i;
    scanf("%d",&size);
    for(i=0;i < size;++i)
    {
        scanf("%d",&num);
        enqueue(heap,num);

    }
    heapsort(heap);
    return 0;
}
heap* create_h()
{
    heap* h = (heap*) malloc(sizeof(heap));
    h->size = 0;
    int i;
    for(i = 1;i <= MAX_SIZE;++i)
    {
        h->items[i] = INT_MIN;
    }
    return h;
}
void enqueue(heap *heap, int element)
{
    if(heap->size >= MAX_SIZE)
    {
        printf("Overflow\n");
    }
    else
    {
        heap->items[++heap->size] = element;

        int key_i = heap->size;
        int parent_i = get_parent_i(heap,heap->size);
        while(parent_i > 0 && heap->items[key_i] > heap->items[parent_i])
        {
            int aux = heap->items[key_i];
            heap->items[key_i] = heap->items[parent_i];
            heap->items[parent_i] = aux;
            key_i = parent_i;
            parent_i = get_parent_i(heap,key_i);
        }
    }
}
int dequeue(heap* heap)
{
    if(heap == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        int element = heap->items[1];
        heap->items[1] = heap->items[heap->size];
        heap->size--;
        max_hfy(heap,1);
        return element;
    }
}
void printf_heap(heap* heap)
{
    int i;
    for(i = 1;i <= heap->size;++i)
    {
        printf("%d\n",heap->items[i]);
    }
}
int get_parent_i(heap* heap,int i)
{
    int result = i/2;
    return result;
}
int get_left_i(heap* heap,int i)
{
    int result = 2*i;
    return result;
}
int get_right_i(heap* heap,int i)
{
    int result = (2*i) + 1;
    return result;
}
void max_hfy(heap* heap,int i)
{
    int largest,left_index,right_index,aux;
    left_index = get_left_i(heap,i);
    right_index = get_right_i(heap,i);
    if((left_index <= heap->size) && (heap->items[i] < heap->items[left_index]))
    {
        largest = left_index;
    }
    else
    {
        largest = i;
    }
    if((right_index <= heap->size) && (heap->items[i] < heap->items[right_index]))
    {
        largest = right_index;
    }
    if(heap->items[i] != heap->items[largest])
    {
        aux = heap->items[i];
        heap->items[i] = heap->items[largest];
        heap->items[largest] = aux;
        max_hfy(heap,largest);
    }
}
int element_of(heap* heap,int i)
{
    return heap->items[i];
}
void heapsort(heap* heap)
{
    int i;
    for(i = heap->size;i >= 2;i--)
    {
        int aux = heap->items[1];
        heap->items[1] = heap->items[i];
        heap->items[i] = aux;
        heap->size--;
        max_hfy(heap,1);
    }
}
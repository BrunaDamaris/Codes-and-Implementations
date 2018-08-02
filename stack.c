#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

typedef struct stack
{
	int current_size;
	int items[MAX_STACK_SIZE];
}stack;

stack* create_stack();
int is_empty(stack *stack);
void push(stack *stack,int item);
int pop(stack *stack);
int peek(stack *stack);

int main(int argc, char const *argv[])
{
	stack* stk = create_stack();
	int *elements,i,size;
	scanf("%d",&size);
	elements = malloc(size * sizeof(int));
	for(i=0;i < size;i++)
	{
		scanf("%d",&elements[i]);
		push(stk,elements[i]);
	}
	for(i=0;i < size;i++)
	{
		printf("%d\n",pop(stk));
	}
	return 0;
}

stack* create_stack()
{
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->current_size = 0;
	return new_stack;
}
void push(stack *stack,int item)
{
	if(stack->current_size == MAX_STACK_SIZE)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		stack->items[stack->current_size++] = item;
	}
}
int is_empty(stack *stack)
{
	return (stack == NULL);
}
int pop(stack *stack)
{
	if(is_empty(stack)) 
	{
		printf("Stack Overflow\n");
		return -1;
	}
	else
	{
		return stack->items[--stack->current_size];
	}
}
int peek(stack *stack)
{
	if(is_empty(stack))
	{
		printf("Stack Overflow\n");
		return -1;
	}
	else
	{
		return stack->items[stack->current_size - 1];
	}
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

STACK* Create_stack();

NODE* create_node(int element);

int IS_EMPTY(STACK* stack);

int POP(STACK* stack);

void PUSH(STACK* stack, int element);

void result(STACK* stack, char operation);

void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* stk = Create_stack();
   	int i,size,num;
   	scanf("%d",&size);
   	for(i=0;i < size;i++)
   	{
   		scanf("%d",&num);
   		PUSH(stk,num);
   	}
   	for(i=0;i < size;i++)
   	{
   		printf("%d\n",POP(stk));
   	}

}
STACK* Create_stack()
{
	STACK *new_stack = (STACK*) malloc(sizeof(STACK));
	new_stack->head = NULL;
	return new_stack;
}
NODE* create_node(int element)
{
	return NULL;
}
int IS_EMPTY(STACK* stack)
{
	return (stack == NULL);
}
int POP(STACK* stack)
{
	NODE *new_head = (NODE*) malloc(sizeof(NODE));
	int value;
	if(IS_EMPTY(stack)) 
	{
		printf("Stack Overflow\n");
		return -1;
	}
	else
	{
		new_head = stack->head;
		value = new_head->element;
		stack->head = stack->head->next;
		free(new_head);
	}
	return value;
}

void PUSH(STACK* stack, int element)
{
	NODE *new_head = (NODE*) malloc(sizeof(NODE));
	new_head->element = element;
	new_head->next = stack->head;
	stack->head = new_head;
}

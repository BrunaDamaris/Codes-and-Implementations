#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE node;
typedef struct STACK stack;
struct NODE
{
	int element;
	node* next;
	node* down;
};
struct STACK
{
	node* head;
	node* down;
};
node* create_list()
{
	return NULL;
}
node* create_node(int element)
{
	node* new_node = (node*) malloc(sizeof(new_node));
	new_node->next = NULL;
	new_node->down = NULL;
	new_node->element = element;
	return new_node;
}
void* addtolist(node* head,int element)
{
	// node* mynode = create_node(element);
	// node* aux = head;
	// while(aux->next != NULL)
	// {
	// 	printf("COISO\n");
	// 	aux = aux->next;
	// }
	// aux->next = mynode;
	// return aux;
	node* mynode = create_node(element);
	mynode->next =  head;
	return mynode;
}
stack* create_stack()
{
	stack* pilha = (stack*) malloc(sizeof(stack));
	pilha->head = NULL;
	pilha->down = NULL;
	return pilha;
}
void print_list(node* head)
{
	node* aux = head;
	while(aux != NULL)
	{
		printf("(%d)",aux->element);
		aux = aux->next;
	}
}
void push(stack* stack)
{
	int item;
	char trash;
	if(stack == NULL)
	{
		printf("EMPTY STACK");
	}
	else
	{
		node* list = create_list();
		while(scanf("%d%c",&item,&trash))
		{
			list = addtolist(list,item);
			if(trash == '\n')
			{
				break;
			}
		}
		stack->head = list;
		// stack->head->down = stack->head->next;
		// //print_list(stack->head);
		// //printf("\n");
		// stack->down = stack->head->down;
	}
}
void pop(stack* stack)
{
	if(stack == NULL)
	{
		printf("EMPTY STACK");
	}
	else
	{
		print_list(stack->head);
		printf("\n");
		// stack->head = stack->head->down;
	}
	printf("saiu\n");
}
int main(int argc, char const *argv[])
{
	stack* stk = create_stack();
	char command[256];
	int i;
	while(scanf("%s",command) != EOF)
	{
		if(strcmp(command,"PUSH") == 0)
		{
			push(stk);
		}
		else if(strcmp(command,"POP") == 0)
		{
			pop(stk);
		}
	}
	return 0;
}
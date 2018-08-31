#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE node;

struct NODE {
	int item;
	node *next;
};

node* create_linked_list()
{
	return NULL;
}
node* addtolist(node *head,int item)
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = head;
	return new_node;
}
node* addintheend(node*head,int item)
{
    if(head == NULL)
    {
        node* new_node = (node*) malloc(sizeof(node));
	    new_node->item = item;
	    new_node->next = NULL;
        head = new_node;
		return head;
    }
    else if(head != NULL)
    {
		//printf("...\n");
        node* new_node = (node*) malloc(sizeof(node));
	    new_node->item = item;
	    new_node->next = NULL;
        node *aux = head;
        while(aux->next != NULL)
        {
            aux = aux->next;
        }
        if(aux->next == NULL)
        {
            aux->next = new_node;
        }
		return head;
    }
}
node* search(node *head,int item)
{
	while(head != NULL)
	{
		if(head->item == item) return head;
		head = head->next;
	}
	return NULL;
}
node *removefromlist(node *head,int item)
{
	node* previous = NULL;
	node* current = head;
	while(current != NULL && current->item != item)
	{
		previous = current;
		current = current->next;
	}
	if(current == NULL) return head;
	if(previous == NULL) head = current->next;
	else
	{
		previous->next = current->next;
	}
	free(current);
	return head;
}
int is_empty(node *head)
{
	return (head == NULL);
}
void print_linked_list(node *head)
{
	node* current = head;
	while(current != NULL)
	{
		printf("%d!\n",current->item);
		current = current->next;
	}
}
int main(int argc, char const *argv[])
{
	node* list = create_linked_list();
	int *elements,size,i;
	scanf("%d",&size);
	elements = malloc(size * (sizeof(int)));
	for(i=0;i < size;i++)
	{
		scanf("%d",&elements[i]);
		list = addintheend(list,elements[i]);
	}
	print_linked_list(list);
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE node;

struct NODE {
	char item;
	node *next;
	node *previous;
};


node* create_doubly_linked_list()
{
	return NULL;
}
node* addtolist(node *head,char item)
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = head;
	new_node->previous = head;
	if(head != NULL) head->previous = new_node;
	return new_node;
}
int is_empty(node *head)
{
	return (head == NULL);
}
void print_doubly_linked_list(node *head)
{
	if(head != NULL)
	{
		printf("%c\n",head->item);
		print_doubly_linked_list(head->next);
	}
}
void check(node *head)
{
	int count[100],index=0,num=0,biggerseq=0,j_index=0,k_index=0;
	int first=0,last=0;
	//node *previous = NULL;
	node *next = NULL;
	while(head->next != NULL)
	{
		//printf("sss\n");
		//num=0;
		//printf("%c\n",head->item);
		if(head->item == '1')
		{
			head = head->next;
			num++;
		}
		//previous = head->previous;
		if(head->item == '0')
		{
			count[index] = num;
			index++;
		}
		next = head->next;
		if(next->item == '0')
		{
			num++;
		}
		if(next->item == '1')
		{
			count[index] = num;
			index++;
		}
		num++;
		head = head->next;
	}
	for(j_index=0;j_index < index;j_index++)
	{
		printf("%d!\n",count[j_index]);
	}
	biggerseq = count[1] - count[0];
	for(j_index=0; j_index < index;j_index++)
	{
		if(count[j_index+1]-count[j_index] >= biggerseq)
		{
			biggerseq = count[j_index+1] - count[j_index];
			first = count[j_index];
			last = count[j_index+1];
		}
		j_index++;
	}
	printf("%d %d\n",first,last);
	index=j_index=first=last=0;
}
int main(int argc, char const *argv[])
{
	node* list = create_doubly_linked_list();
	int size,i,numberof[10000];
	char str[10000];
	for(;scanf("%s",str);)
	{
		size = strlen(str);
		if(size == 1 && str[0] == '0')
		{
			break;
		}
		for(i=size-1;i >= 0;i--)
		{
			list = addtolist(list,str[i]);
		}
		//print_doubly_linked_list(list);
		check(list);
	}
	return 0;
}
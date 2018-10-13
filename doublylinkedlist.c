#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct dlist node;

struct dlist{
    int element;
    node* next;
    node* previous;
};

node* create_dlist(){
    return NULL;
}

node* add_to_dlist(node* mydlist,int element){
    node* new = (node*) malloc(sizeof(node));
    new->element = element;
    new->next = mydlist;
    new->previous = NULL;
    if(mydlist != NULL) mydlist->previous = new;
    return new; 
}

node* remove_from(node *head, int item)
{
    node *current = head;
    while (current != NULL && current->element != item) current = current->next;
    if (current == NULL) return head;
    if (head == current) head = current->next;
    else {
        current->previous->next = current->next;
    }
    if (current->next != NULL) current->next->previous = current->previous;
    free(current);
    return head;
}

void print_doubly_linked_list_backward(node *tail)
{
    if (tail != NULL) {
        printf("%d\n", tail->element);
        print_doubly_linked_list_backward(tail->next);
    }
}


int main()
{
    node* newlist = create_dlist();
    int cases,number;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&number);
        newlist = add_to_dlist(newlist,number);
    }
    print_doubly_linked_list_backward(newlist);
    return 0;
}
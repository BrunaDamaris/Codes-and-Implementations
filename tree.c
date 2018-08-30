#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TREE binary_tree;

struct TREE
{
    int element;
    binary_tree *right;
    binary_tree *left;
};


binary_tree* create_empty_binary_tree()
{
    return NULL;
}
binary_tree* create_binary_tree(int element, binary_tree *left,binary_tree *right)
{
    binary_tree* binarytree = (binary_tree*) malloc(sizeof(binary_tree));
    binarytree->element = element;
    binarytree->right = right;
    binarytree->left = left;
    return binarytree;
}

int is_empty(binary_tree *bt)
{
    if(bt == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print_in_order(binary_tree *bt)
{
    if(!is_empty(bt))
    {
        print_in_order(bt->left);
        printf("%d",bt->element);
        print_in_order(bt->right);
    }
}

void print_pre_order(binary_tree *bt)
{
    if(!is_empty(bt))
    {
        printf("%d",bt->element);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}

void print_post_order(binary_tree *bt)
{
    if(!is_empty(bt))
    {
        print_post_order(bt->left);
        print_post_order(bt->right);
        printf("%d",bt->element);
    }
}

binary_tree* binary_search(binary_tree *bt,int element)
{
    if(bt == NULL)
    {
        return bt;
    }
    else if(bt->element > element)
    {
        return binary_search(bt->left,element);
    }
    else
    {
        return binary_search(bt->right,element);
    }
}
binary_tree* add(binary_tree *bt,int element)
{
    if(bt == NULL)
    {
        bt = create_binary_tree(element,NULL,NULL);
    }
    else if(bt->element > element)
    {
        bt->left = add(bt->left,element);
    }
    else
    {
        bt->right = add(bt->right,element);
    }
    return bt;
}

int main()
{
    binary_tree *bt = create_binary_tree(6,create_binary_tree(4, NULL, NULL),create_binary_tree(9,create_binary_tree(1, NULL, NULL),create_binary_tree(2, NULL, NULL)));;
    print_pre_order(bt);
    printf("\n");
    print_in_order(bt);
    printf("\n");
    print_post_order(bt);
    printf("\n");
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TREE binary_tree;

struct TREE
{
    int element;
    int height;
    binary_tree *right;
    binary_tree *left;
};

binary_tree* create_empty_binary_tree()
{
    return NULL;
}
binary_tree* create_binary_tree(int element, binary_tree *left, binary_tree *right)
{
    binary_tree* binarytree = (binary_tree*) malloc(sizeof(binary_tree));
    binarytree->element = element;
    binarytree->right = right;
    binarytree->left = left;
    binarytree->height = 0;
    return binarytree;
}

int max(int a,int b)
{
    return (a > b) ? a : b;
}
int height(binary_tree *binarytree)
{
    if(binarytree == NULL)
    {
        return -1;
    }
    else{
        return 1 + max(height(binarytree->left),height(binarytree->right));
    }
}

int is_empty(binary_tree *binarytree)
{
    if(binarytree == NULL)  return 1;
    else 
    {
        return 0;
    }
}

int balance_factor(binary_tree *binarytree)
{
    if(binarytree == NULL) return 0;
    else if((binarytree->right != NULL) && (binarytree->left != NULL)) return(binarytree->left->height - binarytree->right->height);
    else if((binarytree->right == NULL) && (binarytree->left != NULL)) return (1 + binarytree->left->height);
    else {
    return (-binarytree->right->height-1);
    } 
}

int is_balanced(binary_tree *binarytree)
{
    int balancefactor;
    balancefactor = height(binarytree->left) - height(binarytree->right);
    return ((-1 <= balancefactor) && (balancefactor <= 1));
}
binary_tree* rotate_left(binary_tree *binarytree)
{
    binary_tree* subtree = NULL;
    if(binarytree != NULL && binarytree->right != NULL)
    {
        subtree = binarytree->right;
        binarytree->right = subtree->left;
        subtree->left = binarytree;
    }
    subtree->height = height(subtree);
    binarytree->height = height(binarytree);
    return subtree;
}

binary_tree* rotate_right(binary_tree *binarytree)
{
    binary_tree* subtree = NULL;
    if(binarytree != NULL && binarytree->left != NULL)
    {
        subtree = binarytree->left;
        binarytree->left = subtree->right;
        subtree->right = binarytree;
    }
    subtree->height = height(subtree);
    binarytree->height = height(binarytree);
    return subtree;
}

binary_tree* add(binary_tree *binarytree, int element)
{
    if(binarytree == NULL) 
    {
        return create_binary_tree(element,NULL,NULL);
    }
    else if(binarytree->element > element){
        binarytree->left = add(binarytree->left,element);
    }
    else{
        binarytree->right = add(binarytree->right,element);
    }

    binarytree->height = height(binarytree);
    binary_tree *child = NULL;
    if(balance_factor(binarytree) == 2 || balance_factor(binarytree) == -2)
    {
        if(balance_factor(binarytree) == 2)
        {
            child = binarytree->left;
            if(balance_factor(child) == -1)
            {
                binarytree->left = rotate_left(child);
            }
            binarytree = rotate_right(binarytree);
        }
        else if(balance_factor(binarytree) == -2)
        {
            child = binarytree->right;
            if(balance_factor(child) == 1)
            {
                binarytree->right = rotate_right(child);
            }
            binarytree = rotate_left(binarytree);
        }
    }
    return binarytree;
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
        printf("%d ",bt->element);
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
int main()
{
    binary_tree* bt = create_empty_binary_tree();
    int i, number, size;
    scanf("%d",&size);
    for(i = 0;i < size;++i)
    {
        scanf("%d",&number);
        bt = add(bt,number);
    }
    print_pre_order(bt);
    printf("\n");
}
// 10 20 30 5 15 2;

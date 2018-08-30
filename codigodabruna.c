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

void print_pre_order(binary_tree *bt)
{
    if(!is_empty(bt))
    {
        printf("( %d  ",bt->element);
        print_pre_order(bt->left);
        if(bt->left == NULL)
        {
            printf("() () )");
        }
        if(bt->right == NULL)
        {
            printf("() () )");
        }
        print_pre_order(bt->right);
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
    	printf("( %d () () )",element);
        bt = create_binary_tree(element,NULL,NULL);
    }
    else if(bt->element > element)
    {
        print_pre_order(bt);
        bt->left = add(bt->left,element);
        printf(" () )\n");
    }
    else
    {
        print_pre_order(bt);
        bt->right = add(bt->right,element);
        printf(" )\n");
    }
    return bt;
}

int main()
{
	binary_tree *binarytree = create_empty_binary_tree();
    int numbers[10000],i=0;
    while(scanf("%d",&numbers[i]) != EOF)
    {
        printf("----\n");
        printf("ADICIONANDO: %d\n",numbers[i]);
    	binarytree = add(binarytree,numbers[i]);
    	printf("\n");
    	i++;
    }
    return 0;
}
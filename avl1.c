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

binary_tree* create_empty_binary_tree();

binary_tree* create_binary_tree(int element, binary_tree *left, binary_tree *right);

int max(int a,int b);

int height(binary_tree *binarytree);

int is_empty(binary_tree *binarytree);

int balance_factor(binary_tree *binarytree);

int is_balanced(binary_tree *binarytree);

binary_tree* add1(binary_tree *bt,int element);

binary_tree* rotate_left(binary_tree *binarytree);

binary_tree* rotate_right(binary_tree *binarytree);

binary_tree* add(binary_tree *binarytree, int element);


void print_pre_order(binary_tree *bt);


int main()
{
	//printf("....\n");
    binary_tree* bt = create_empty_binary_tree();
    int numbers[100000],i=0,aux,j = 0,k;
    while(scanf("%d",&numbers[i]) != EOF)
    {
    	binary_tree* btaux = create_empty_binary_tree();
    	printf("----\n");
    	printf("Adicionando %d\n",numbers[i]);
    	bt = add(bt,numbers[i]);
    	btaux = add1(btaux,numbers[i]);
    	if(is_balanced(btaux))
    	{
    		printf("Continuou AVL...\n");
    		printf("  ");
    		print_pre_order(bt);
    		printf("\n");
    	}
    	else
    	{
    		printf("Antes de ajustar balanceamento...\n");
    		printf("  ");
    		print_pre_order(btaux);
    		printf("\n");
    		printf("Depois de ajustar balanceamento...\n");
    		printf("  ");
    		print_pre_order(bt);
    		printf("\n");
    		btaux = create_empty_binary_tree();
    		for(k=0;k <= i;k++)
    		{
    			btaux = add(btaux,numbers[j]);
    		}
    	}
    	i++;
    }
    return 0;
}

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


binary_tree* add1(binary_tree *bt,int element)
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

void print_pre_order(binary_tree *bt)
{
	printf(" (");
    if(!is_empty(bt))
    {
        printf("%d ",bt->element);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
    printf(") ");
}


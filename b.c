#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TREE binary_tree;

struct TREE
{
    int element;
    int previous;
    int next;
    binary_tree *right;
    binary_tree *left;
};

int totalsize = 0,ind = 0;
int preorder[1000],posorder[1000],inorder[10000];

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
    binarytree->previous = -1;
    binarytree->next = -1;
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
        inorder[ind] = bt->element;
    	ind++;
        print_in_order(bt->right);
    }
}

void print_pre_order(binary_tree *bt)
{
    if(!is_empty(bt))
    {
    	preorder[ind] = bt->element;
    	ind++;
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
        posorder[ind] = bt->element;
    	ind++;
    }
}

binary_tree* walk(binary_tree* bt,int arvore[][2],int no,int altura)
{
	if(no == -1)
	{
		return NULL;
	}
	else
	{
		totalsize++;
		bt = create_binary_tree(no,NULL,NULL);
		bt->left = walk(bt,arvore,arvore[no][0],altura+1);
		bt->right = walk(bt,arvore,arvore[no][1],altura+1);
	}
}

int main(int argc, char const *argv[])
{
	int cases,raiz = 0;
	scanf("%d",&cases);
	int arvore[cases][2],i = 0,j = 0;
	binary_tree* bt = create_empty_binary_tree();
	binary_tree* aux = create_empty_binary_tree();
	for(i=0;i < cases;i++)
	{
		for(j=0;j < 2;j++)
		{
			scanf("%d",&arvore[i][j]);
		}
	}
	scanf("%d",&raiz);
	bt = walk(bt,arvore,raiz,0);
	aux = bt;
	print_pre_order(bt);
	ind = 0;
	bt = aux;
	print_in_order(bt);
	ind = 0;
	bt = aux;
	print_post_order(bt);
	ind = 0;
	bt = aux;
	printf("Pre Order:\n");
	for(i = 0;i < totalsize;i++)
	{
		printf("Node %d: ",i);
		if(i == raiz) 
		{
			printf("previous = -1 ");
			printf("next = %d\n",preorder[j+1]);
		}
		else if(i == totalsize-1)
		{
			for(j = 0;j < totalsize;j++)
			{
				if(preorder[j] == i) {
					printf("previous = %d ",preorder[j-1]);
					printf("next = -1\n");
				}
			}
		}
		else if(i < totalsize){
			for(j = 0;j < totalsize;j++)
			{
				if(preorder[j] == i) {
					printf("previous = %d ",preorder[j-1]);
					printf("next = %d\n",preorder[j+1]);
				}
			}
		}
	}
	printf("In Order\n");
	for(i = 0;i < totalsize;i++)
	{
		printf("Node %d: ",i);
		if(i == inorder[0]){
			printf("previous = -1 ");
			printf("next = %d\n",inorder[1]);
		}
		else if(i == totalsize-1)
		{
			for(j = 0;j < totalsize;j++)
			{
				if(inorder[j] == i) {
					printf("previous = %d ",inorder[j-1]);
					printf("next = -1\n");
				}
			}
		}
		else if(i < totalsize){
			for(j = 0;j < totalsize;j++)
			{
				if(inorder[j] == i) {
					printf("previous = %d ",inorder[j-1]);
					printf("next = %d\n",inorder[j+1]);
				}
			}
		}
	}
	printf("Pos Order\n");
	for(i = 0;i < totalsize;i++)
	{
		printf("Node %d: ",i);
		if(i == posorder[0]){
			printf("previous = -1 ");
			printf("next = %d\n",posorder[1]);
		}
		else if(i == totalsize-1)
		{
			for(j = 0;j < totalsize;j++)
			{
				if(inorder[j] == i) {
					printf("previous = %d ",posorder[j-1]);
					printf("next = -1\n");
				}
			}
		}
		else if(i < totalsize){
			for(j = 0;j < totalsize;j++)
			{
				if(inorder[j] == i) {
					printf("previous = %d ",posorder[j-1]);
					printf("next = %d\n",posorder[j+1]);
				}
			}
		}
	}
	return 0;
}

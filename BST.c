#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TREE btree;

struct TREE
{
    int height;
    int element;
    btree* right;
    btree* left;
};

int totalsize = 0;

btree* create_btree(int element,btree* right, btree* left,int height)
{
    btree* mytree = (btree*) malloc(sizeof(btree));
    mytree->element = element;
    mytree->right = right;
    mytree->left = left;
    mytree->height = height;
    return mytree;
}

btree* addtotree(btree* mytree,int element,int height)
{
    totalsize++;
    if(mytree == NULL) 
    {
        mytree = create_btree(element,NULL,NULL,height);
        printf("%d\n",mytree->height);
    }
    else if(mytree->element == element){
        printf("%d\n",mytree->height);
        return mytree;
    }
    else if(mytree->element > element){
        mytree->left = addtotree(mytree->left,element,height+1);
    } 
    else if(mytree->element < element){
        mytree->right = addtotree(mytree->right,element,height+1);
    }
    return mytree;
}


btree* min(btree* mytree)
{
    if(mytree->right == NULL) return mytree;
    return min(mytree->right);
}

btree* removefromtree(btree* mytree,int element)
{
    if(mytree == NULL)
    {
        printf("-1\n");
        return NULL;
    }
    if(mytree->element == element){
        if((mytree->left == NULL) && (mytree->right == NULL))
        {
            printf("%d\n",mytree->height);
            (totalsize)--;
            mytree = NULL;
        }
        else if( mytree->left == NULL || mytree->right == NULL){
            if(mytree->left != NULL)
            {
                mytree = mytree->left;
                mytree->height = mytree->height-1;
                (totalsize)--;
                printf("%d\n",mytree->height);
                return mytree;
            }
            if(mytree->right != NULL)
            {
                mytree = mytree->right;
                mytree->height = mytree->height-1;
                (totalsize)--;
                printf("%d\n",mytree->height);
                return mytree;
            }
        }
        else if((mytree->left !=NULL) && (mytree->right != NULL)){
            btree* aux = min(mytree->left);
            mytree->element = aux->element;
            mytree->left = removefromtree(mytree->left,aux->element);
            (totalsize)--;
            printf("%d\n",mytree->height);
        }
    }
    else if(mytree->element > element)
    {
        mytree->left = removefromtree(mytree->left,element);
    }
    else if(mytree->element < element)
    {
        mytree->right = removefromtree(mytree->right,element);
    }
    return mytree;
}

void max(btree* mytree, int element,int *go,int x)
{
    if(mytree != NULL)
    {
        max(mytree->left,element,go,x);
        if(mytree->element > x) (*go)++;
        max(mytree->right,element,go,x);
    }
}

int element_of(btree* mytree,int index,int *flag)
{
    if(mytree != NULL)
    {
        if(mytree->height == index) 
        {
            printf("%d\n",mytree->element);
            return mytree->element;
        }
        element_of(mytree->left,index,flag);
        //element_of(mytree->right,index,flag);
    }
}

void print_pre_order(btree *bt)
{
    if(bt != NULL)
    {
        printf("%d,%d#",bt->element,bt->height);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}

int main(){
    int cases,numberofop,op,num;
    int size,h;
    int *go = malloc(sizeof(int));
    *go = 0;
    int *flag = malloc(sizeof(int));
    *flag = 0;
    scanf("%d",&cases);
    while(cases--)
    {
        btree* mytree = NULL;
        btree* aux = NULL;
        scanf("%d",&numberofop);
        while(numberofop--)
        {
            scanf("%d%d",&op,&num);
            if(op == 1){
                mytree = addtotree(mytree,num,0);
            }
            else if(op == 2){
                aux = removefromtree(mytree,num);
            }
            else if(op == 3){
                max(mytree,num,go,num);
                printf("%d\n",*go);
                *go = 0;
            }
            else if(op == 4){
                if(totalsize == 1)
                {
                    if(num == 1) num = 0;
                }
                element_of(mytree,num,flag);
            }
        }
        totalsize = 0;
        printf("\n");
        free(mytree);
    }
}

#include <stdio.h>
#include <stdlib.h>

int aux_que_marca[10000];
int auxqueconta = 0;

int i = 0, j = 0, aux_array_cont = 1, gobalauxlixiar = 0;

typedef struct binary_tree
{
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
} binary_tree;

int is_empty(binary_tree *bt)
{
    return(bt == NULL);
}

binary_tree *create_empty_binary_tree()
{
    return NULL;
}

binary_tree *create_binary_tree(int item, binary_tree* left, binary_tree *right)
{
    binary_tree* new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
    new_binary_tree -> item = item;
    new_binary_tree -> left = left;
    new_binary_tree -> right = right;

    return new_binary_tree;
}

/*binary_tree *add(binary_tree *bt, int item)
{
    if (bt == NULL)
    {
        bt = create_binary_tree(item, NULL, NULL);
    } else if (bt -> item > item)
    {
        bt -> left = add(bt -> left, item);
    } else
    {
        bt -> right = add(bt -> right, item);
    }
    else
    {
        bt =
    }

    return bt;
} */

binary_tree *add_non_binary(binary_tree *bt)
{

    if (aux_que_marca[i] != -1)
    {
       bt = create_binary_tree(aux_que_marca[i], NULL, NULL);
       i ++;
       bt -> left = add_non_binary(bt -> left);
       bt -> right = add_non_binary(bt -> right);
    }else
    {
        i ++;
        return NULL;
    }
    return bt;
}

int check(binary_tree *bt, int item)
{
    //printf("Entrei\n");
    if (bt -> item == item)
    {
        gobalauxlixiar = item;
        auxqueconta ++;
        return 1;
    }
    if (bt -> left != NULL)
    {
        //printf("(%d)%d\n",bt -> left -> item,item );
        if (bt -> left -> item == item)
        {
            aux_array_cont = 0;
            gobalauxlixiar = item;
            return 1;
        }else
        {
            auxqueconta ++;
            check(bt -> left, item);
        }
    }

    if (bt -> right != NULL)
    {
        //printf("(%d!)%d\n",bt -> right -> item,item );
        //auxqueconta = 0;
        if (bt -> right -> item == item)
        {
            gobalauxlixiar = item;
            //aux_array_cont = 0;
            return 1;
        }else
        {
            auxqueconta ++;
            check(bt -> right, item);
        }
    }
}

binary_tree *search(binary_tree *bt, int item)
{
    if ((bt == NULL) || (bt -> item == item))
    {   
        return bt;
    } else if (bt -> item > item)
    {
        return search(bt -> left, item);
    } else
    {
        return search(bt -> right, item);
    }
}

void print_in_order(binary_tree *bt)
{  
    if (!is_empty(bt)) 
    {
        print_in_order(bt -> left);
        printf("%d ", bt -> item);
        print_in_order(bt -> right);
    }
}

void print_pre_order(binary_tree *bt)
{
    if (!is_empty(bt))
    {
        printf("%d ", bt -> item);
        print_pre_order(bt -> left);
        print_pre_order(bt -> right);
    }
}

void print_post_order(binary_tree *bt)
{
    if (!is_empty(bt))
    {
        print_post_order(bt -> left);
        print_post_order(bt -> right);
        printf("%d ", bt -> item);
    }
}

void main()
{
    binary_tree *arvore = create_empty_binary_tree();
    int num_to_convert_pos = 0;
    char aux_array[1000];
    char stringui[1000];

    gets(stringui);   
    //int tam = strlen(stringui);
    for (i = 0; stringui[i] != '\0'; i ++)
    {
        if (stringui[i] != ' ' && stringui[i] != '(' && stringui[i] != ')')
        {
            while (stringui[i] != ' ' && stringui[i] != '(' && stringui[i] != ')')
            {
                aux_array[num_to_convert_pos] = stringui[i];
                num_to_convert_pos ++;
                i ++;
            }

            aux_array[num_to_convert_pos] = '\0';
            aux_que_marca[j] = atoi(aux_array);
            j ++;
            num_to_convert_pos = 0;     
        }

        /*if (stringui[i] == '(' || stringui[i] == ')')
        {
            push(pila, stringui[i]);
        }*/

        if (stringui[i] == '(' && stringui[i + 1] == ')')
        {
            //push(pila, stringui[i]);
            aux_que_marca[j] = -1;
            j ++;
            i ++;
        }
    }
    i = 0;
    int item, aux;
    scanf("%d", &item);
    arvore = add_non_binary(arvore);
    aux = check(arvore, item);
    /*printf("%d\n", aux);
    printf("%d\n", auxqueconta);
    printf("Sou a Global Auxiliar: %d\n", gobalauxlixiar);*/
    if (gobalauxlixiar)
    {
        printf("ESTA NA ARVORE\n");
        if ( auxqueconta % 2 == 0 )
            printf("%d\n", auxqueconta/2);
        else
            printf("%d\n", (auxqueconta/2) + 1);

    }else
    {
        printf("NAO ESTA NA ARVORE\n-1\n");
    }
    //print_pre_order(arvore);

  

}
//(5(3(1(0()())(2()()))(4()()))(9(6()(7()()))(8()()))
//8

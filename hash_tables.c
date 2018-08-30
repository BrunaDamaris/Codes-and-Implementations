#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 7

typedef struct ITEM element;
typedef struct HASH hash_table;

struct ITEM
{
	int key;
	int value;
	element* next;
};

struct HASH
{
	int lenght;
	element *table[max];
};

hash_table* create_hash()
{
	hash_table* new_hash = (hash_table*) malloc(sizeof(hash_table));
	new_hash->lenght = 0;
	int i;
	for(i = 0; i < max;i++)
	{
		new_hash->table[i] = NULL;
	}
	return new_hash;
}
// avoiding colisions
void put(hash_table *ht,int key,int value)
{
	int k = key % max;
	while(ht->table[k] != NULL)
	{
		if(ht->table[k]->key == key)
		{
			ht->table[k]->value = value;
			break;
		}
		k = (k+1) % max;
	}
	if(ht->table[k] == NULL)
	{
		element *new_element = (element*) malloc(sizeof(element));
		new_element->key = key;
		new_element->value = value;
		ht->table[k] = new_element;
	}
	ht->lenght++;
}
// puting in the end of lists
void put1(hash_table *ht,int key,int value)
{
	int k = key % max;
	if(ht->table[k] == NULL)
	{
		element *new_element = (element*) malloc(sizeof(element));
		new_element->key = key;
		new_element->value = value;
		new_element->next = NULL;
		ht->table[k] = new_element;
	}
	else if(ht->table[k] != NULL)
	{
		element *new_element = (element*) malloc(sizeof(element));
		new_element->key = key;
		new_element->value = value;
		new_element->next = NULL;
		element* aux = ht->table[k];
		while(aux->next != NULL)
		{
			aux =  aux->next;
		}
		if(aux->next == NULL)
		{
			aux->next = new_element;
		}
	}
	ht->lenght++;
}
//puting at the beginning of lists
void put2(hash_table *ht,int key,int value)
{
	int k = key % max;
	if(ht->table[k] == NULL)
	{
		element *new_element = (element*) malloc(sizeof(element));
		new_element->key = key;
		new_element->value = value;
		new_element->next = NULL;
		ht->table[k] = new_element;
	}
	else if(ht->table[k] != NULL)
	{
		element *new_element = (element*) malloc(sizeof(element));
		new_element->key = key;
		new_element->value = value;
		new_element->next = ht->table[k];
        ht->table[k] = new_element;
    }
	ht->lenght++;
}
int get(hash_table *ht,int key)
{
	int k = key % max;
	while(ht->table[k] != NULL)
	{
		if(ht->table[k]->key == key)
		{
			return ht->table[k]->value;
		}
		k = (k+1) % max;
	}
	return -100;
}

void removefrom(hash_table *ht,int key)
{
	int k = key % max;
	while(ht->table[k] != NULL)
	{
		if(ht->table[k]->key == key)
		{
			free(ht->table[k]);
			ht->table[k] = NULL;
		}
		k = (k+1) % max;
	}
}
void print_hash(hash_table *ht)
{
	int i=0;
	while(i < max)
	{
		if(ht->table[i] != NULL)
		{
			printf("%d -> ",i);
			printf("%d -> ",ht->table[i]->value);
			if(ht->table[i]->next != NULL)
			{
				while(ht->table[i]->next != NULL)
				{	
					printf("%d -> ",ht->table[i]->next->value);
					ht->table[i]->next = ht->table[i]->next->next;
				}
				i++;
			}
			else{
				i++;
			}
			printf("\\\n");
		}
		else
		{
			printf("%d -> \\\n",i);
			i++;
		}
	}
}
int main(int argc, char const *argv[])
{
	hash_table* hash = create_hash();
	int element;
	int i,size;
	scanf("%d",&size);
	for(i=0;i < size;i++)
	{
		scanf("%d",&element);
		put2(hash,element,element);
	}
	print_hash(hash);	
	return 0;
}

//
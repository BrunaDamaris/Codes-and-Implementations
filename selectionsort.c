#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define lint long int

void selection(lint *array,lint size)
{
	lint i,j,min,aux;
	for(i=0;i < size;i++){
		min=i;
		for(j=i+1;j < size;j++){
			if(array[j] < array[min])min=j;
		}
		aux=array[i];
		array[i]=array[min];
		array[min]=aux;
	}
}

int main(int argc, char const *argv[])
{
	lint *array,size,i;
	scanf("%ld",&size);
	array = malloc(size * sizeof(long int));
	for(i=0;i < size;i++)
	{
		scanf("%ld\n",&array[i]);
	}
	selection(array,size);
	for(i=0;i < size;i++)
	{
		printf("%ld\n",array[i]);
	}
	return 0;
}
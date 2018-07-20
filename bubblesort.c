#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define lint long int

void bubble(lint *array,lint size)
{
	lint i,j,aux,cont=0;
	for(i=size-1;i >= 0;i--){
		for(j=0;j < i;j++){
			if(array[j] > array[j+1]){
				aux=array[j];
				array[j]=array[j+1];
				array[j+1]=aux;
			}
		}
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
	bubble(array,size);
	for(i=0;i < size;i++)
	{
		printf("%ld\n",array[i]);
	}
	return 0;
}
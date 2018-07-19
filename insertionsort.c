#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define lint long int

void insertion(lint *array,lint size)
{
	lint i,j,key,k;
	for(i=1;i <= size;i++)
	{
		key=array[i];
		j=i-1;
		while((j >= 0) && (array[j] > key))
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=key;
	}
}

int main(int argc, char const *argv[])
{
	lint *array,size,i;
	scanf("%ld",&size);
	array = malloc(size * sizeof(long int));
	for(i=1;i <= size;i++)
	{
		scanf("%ld\n",&array[i]);
	}
	insertion(array,size);
	for(i=1;i <= size;i++)
	{
		printf("%ld\n",array[i]);
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define lint long int

void quick_s(lint *array,lint left,lint right)
{
	lint pivot,l,r,aux,mid;
	mid=(left+right)/2;
	pivot=array[mid];
	l=left;
	r=right;
	while(l <= r)
	{
		while(l <= right && array[l] < pivot) l++;
		while(r >= left && array[r] > pivot) r--;
		if(l <= r)
		{
			aux=array[l];
			array[l]=array[r];
			array[r]=aux;
			l++;
			r--;
		}
	}
	if(r > left) quick_s(array,left,r);
	if(l < right)quick_s(array,l,right);
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
	quick_s(array,0,size);
	for(i=0;i < size;i++)
	{
		printf("%ld\n",array[i]);
	}
	return 0;
}
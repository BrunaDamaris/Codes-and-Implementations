#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define lint long int

lint search(lint *pointer,lint size,lint number)
{
	lint begin=0,end=size-1,middle,num,numberresult[size],last=0,i=0;
	while(begin <= end)
	{
		middle=(begin+end)/2;
		if(pointer[middle] < number) begin=middle+1;
		else if(pointer[middle] > number) end=middle-1;
		else
		{
		    i=middle;
			while(pointer[i] == number)
			{
				last=i;
				i--;
				num++;
			}
			return last;
		} 
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	lint *array,size,i,number;
	scanf("%ld",&size);
	scanf("%ld",&number);
	array = malloc(size * sizeof(long int));
	for(i=1;i <= size;i++)
	{
		scanf("%ld\n",&array[i]);
	}
	printf("%ld\n",search(array,size,number));
	return 0;
}
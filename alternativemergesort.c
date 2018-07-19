#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define lint long int
void Merge(lint *pointer,lint begin, lint middle, lint end)
{
	lint num1,num2;
	num1=middle-begin+1;
	num2=end-middle;
	lint i,j,k,left[num1+1],right[num2+1];
	
	
	for(i=1;i <= num1;i++){
		left[i]=pointer[begin+i-1];
	}
	


	for(j=1;j <= num2;j++){
		right[j]=pointer[middle+j];
	}
	
	left[num1+1]=INT_MIN;
	

	right[num2+1]=INT_MIN;
	

	i=j=1;
	
	for(k=begin;k <= end;k++){
		if(left[i] >= right[j]){
			pointer[k]=left[i];
			i++;
		}
		else{
			pointer[k]=right[j];
			j++;
		}
	}
	
}

void Merge_s(lint *pointer, lint begin, lint end)
{
	lint middle;
   	if(begin < end){
  	 	middle=(begin+end)/2;
   		Merge_s(pointer,begin,middle);
   		Merge_s(pointer,middle+1,end);
   		Merge(pointer,begin,middle,end);
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

	Merge_s(array,1,size);
	for(i=1;i <= size;i++)
	{
		printf("%ld\n",array[i]);
	}
	return 0;
}

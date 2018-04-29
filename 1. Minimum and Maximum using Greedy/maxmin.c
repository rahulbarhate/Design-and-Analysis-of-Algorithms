#include <stdio.h>
#include <stdlib.h>

int min;
int max;
int elements[50];

int main(void)
{
	int i=0;
	int n=0;
	
	printf("\nEnter num of elements in array");
	scanf("%d",&n);
	
	for(i=1;i<n+1;i++)
		scanf("%d",&elements[i]);
	
	find(1,n);
	
	printf("Min is:%d\nMax is:%d",min,max);
	return 0;
}

void find(int first,int last)
{
	int middle;
	int max1,min1;
	
	if(first==last)      //Only one element
	{
		min = elements[first];
		max = elements[first];
		printf("Max = Min : %d\n",max);
	}
	
	else if(first==(last-1)) //Two elements
	{
		if(elements[first]>elements[last])
		{
			max = elements[first];
			min = elements[last];
		}
		
		else
		{
			min = elements[first];
			max = elements[last];
		}

		printf("Max : %d\n",max);
		printf("Min : %d\n",min);
	}
	
	else
	{

		middle = (first+last)/2;

		f(first,middle);
		
		max1 = max;
		printf("Max1 : %d\n",max1);
		min1 = min;
		printf("Min1 : %d\n",min1);

		find(middle+1,last);
		
		if(min1<min)
			min=min1;
		
		if(max1>max)
			max=max1;

	}
}

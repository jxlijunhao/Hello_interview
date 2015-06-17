/************************************************************************/
/* 给定一个数组，建立最大堆(自己实现)                                               */
/************************************************************************/

#include<stdio.h>

void swap(int &a,int &b)
{
	a=a^b;
	b=a^b;
	a=a^b;
}


//不断下滤的过程
void adjustMaxHeap(int *array, int start,int end)
{
	int current=start;
	int lChild=2*current+1;
	int tmp=array[current];

	while (lChild<=end)
	{
		if (lChild<=end && array[lChild]<array[lChild+1])
			lChild++;

		if (tmp>=array[lChild])
			break;
		else
		{
			array[current]=array[lChild];
			current=lChild;
			lChild=2*current+1;
		}
	}
	array[current]=tmp;
}


void buildMaxHeap(int *array,int len)
{
	if (array==NULL || len<1)
		return;

	for (int i=len/2-1;i>=0;--i)
		adjustMaxHeap(array,i,len-1);
}

void printMaxHeap(int *array,int len)
{
	for (int i=0;i<len;i++)
		printf("%d ",array[i]);
	printf("\n");
}

void HeapSort(int *array,int len)
{
	if (array==NULL ||len<1)
		return;
	 for (int i=len/2-1;i>=0;i--)
		buildMaxHeap(array,len);

	for (int i=len-1;i>0;i--)
	{	 
		swap(array[0],array[i]);		 
		buildMaxHeap(array,i-1);		 
	}
}



//int main()
//{
//	int a[]={130,20,30,90,40,70,110,60,10,100,50,80};
//	int len=sizeof(a)/sizeof(a[0]);
//	//buildMaxHeap(a,len-1);
//
//	//printMaxHeap(a,len);
//
//	HeapSort(a,len);
//	printMaxHeap(a,len);
//	return 0;
//}
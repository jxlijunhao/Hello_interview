/************************************************************************/
/* 实现最大堆排序（网上）                                                 */
/************************************************************************/

#include<stdio.h>

void swap1(int &a,int &b)
{
	a=a^b;
	b=a^b;
	a=a^b;
}

void BigRootHeapAdjust(int *array,int low,int high)
{
	int lChild;
	int cur=low;

	int temp=array[cur];

	for (lChild=2*cur+1; lChild<=high ; lChild=2*lChild+1)
	{
		if (lChild<high && array[lChild]<array[lChild+1])
			lChild++;

		if (temp>=array[lChild])
			break;
		else
		{
			array[cur]=array[lChild];
			cur=lChild;
		}
	}
	array[cur]=temp;
}

void BigRootHeapSort(int *array,int len)
{
	if (array==NULL || len<1)
		return;
	for (int i=len/2-1;i>=0;--i)
		BigRootHeapAdjust(array,i,len-1);

	for (int i=len-1;i>0;--i)
	{
		swap1(array[0],array[i]);
		BigRootHeapAdjust(array,0,i-1);
	}
}

void printMaxHeap1(int *array,int len)
{
	for (int i=0;i<len;i++)
		printf("%d ",array[i]);
	printf("\n");
}

//int main()
//{
//	int a[]={130,20,30,90,40,70,110,60,10,100,50,80};
//	int len=sizeof(a)/sizeof(a[0]);
//	BigRootHeapSort(a,len);
//	printMaxHeap1(a,len);
//}
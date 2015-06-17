/************************************************************************/
/* 归并排序                                                              */
/************************************************************************/

#include<iostream>
using namespace std;

//两个已排序的子数组进行合并的过程
void SubMergeSort(int *inputArray,int* tempArray, int low,int mid,int high)
{
	int index1=low;
	int index2=mid+1;
	int destIndex=low;

	while(index1<=mid && index2<=high)
	{
		if (inputArray[index1] < inputArray[index2])
		{
			tempArray[destIndex++]=inputArray[index1++];
		}
		else
		{
			tempArray[destIndex++]=inputArray[index2++];
		}
	}

	while (index2<=high)
	{
		tempArray[destIndex++]=inputArray[index2++];
	}

	while (index1<=mid)
	{
		tempArray[destIndex++]=inputArray[index1++];
	}

	for (int i=low;i<=high;i++)
		inputArray[i]=tempArray[i];
}

//分治过程
void MergeSort(int *inputArray, int *tempArray, int low,int high)
{
	if (low<high)
	{
		int mid=(low+high)>>1;
		MergeSort(inputArray,tempArray,low,mid);
		MergeSort(inputArray,tempArray,mid+1,high);
		SubMergeSort(inputArray,tempArray,low,mid,high);
	}
}



void MERGESORT(int *inputArray,int len)
{
	int *tempArray= new int[len];
	MergeSort(inputArray,tempArray,0,len-1);
	delete []tempArray;
}

//int main()
//{
//	int inputArray[10]={2,1,3,4,6,5,8,7,9,10};
//	MERGESORT(inputArray,10);
//
//	for (int i=0;i<10;i++)
//	{
//		cout<<inputArray[i]<<" ";
//	}
//	return 0;
//}

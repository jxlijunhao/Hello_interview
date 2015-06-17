/************************************************************************/
/* 统计逆序对的个数                                                       */
/************************************************************************/

#include<iostream>
using namespace std;

int SubMergeSort1(int *inputArray,int* tempArray, int low,int mid,int high)
{
	int index1=low;
	int index2=mid+1;
	int destIndex=low;
	int count=0;

	while(index1<=mid && index2<=high)
	{
		if (inputArray[index1] < inputArray[index2])
		{
			tempArray[destIndex++]=inputArray[index1++];
		}
		else
		{
			tempArray[destIndex++]=inputArray[index2++];
			count+=mid-index1+1;
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

	return count;
}

//分治过程
int MergeSort1(int *inputArray, int *tempArray, int low,int high)
{
	int count=0;
	if (low<high)
	{
		int mid=(low+high)>>1;
		count+=MergeSort1(inputArray,tempArray,low,mid);
		count+=MergeSort1(inputArray,tempArray,mid+1,high);
		count+=SubMergeSort1(inputArray,tempArray,low,mid,high);
	}
	return count;
}



int MERGESORT1(int *inputArray,int len)
{
	int *tempArray= new int[len];
	int count=MergeSort1(inputArray,tempArray,0,len-1);
	
	delete []tempArray;
	return count;
}

//int main()
//{
//	int inputArray[]={1,2,4,3};
//	int count=MERGESORT1(inputArray,sizeof(inputArray)/sizeof(int));
//	cout<<count<<endl;
//	for (int i=0;i<sizeof(inputArray)/sizeof(int);i++)
//	{
//		cout<<inputArray[i]<<" ";
//	}
//	return 0;
//}
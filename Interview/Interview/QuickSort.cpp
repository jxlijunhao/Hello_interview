/************************************************************************/
/* 快速排序                                                              */
/************************************************************************/

//主要介绍两种partition函数

#include<stdio.h>

void mySwap(int &a,int &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}


int partition_1(int *arr,int low,int high)
{
	int pivotData = arr[low];
	int littleInd = low;
	int highInd = high;

	while (littleInd < highInd )
	{
		while (littleInd < highInd && arr[highInd] >= pivotData)
			--highInd;

		if (littleInd < highInd)
			arr[littleInd++] = arr[highInd];

		while (littleInd < highInd && arr[littleInd] <= pivotData)
			++littleInd;

		if (littleInd < highInd)
			arr[highInd--] = arr[littleInd];
	}

	arr[highInd] = pivotData;
	return highInd;
}


int partition_2(int *arr, int low, int high)

{

	int pivot = arr[high];//选最后一个元素作为枢纽元

	int location = low-1;//location指向比pivot小的元素段的尾部

	for(int i = low; i < high; i++)//比枢纽元小的元素依次放在前半部分

    if(arr[i] < pivot)
		mySwap(arr[i], arr[++location]);

	mySwap(arr[high], arr[location+1]);

	return location+1;
}




void myquickSort (int *arr,int low ,int high)
{
	if ( arr == NULL)
		return;

	 
	if (low < high)
	{
		int pivotData = partition_2(arr,low ,high);
		myquickSort(arr,low,pivotData-1);
		myquickSort(arr,pivotData+1,high);
	}

}

//int main()
//{
//	int arr[10]={2,1,3,4,6,5,8,7,9,10};
//	myquickSort(arr,0,9);
//
//	for (int i = 0;i < 10; i++)
//		printf("%2d ",arr[i]);
//}
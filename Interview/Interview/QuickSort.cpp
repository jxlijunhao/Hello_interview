/************************************************************************/
/* ��������                                                              */
/************************************************************************/

//��Ҫ��������partition����

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

	int pivot = arr[high];//ѡ���һ��Ԫ����Ϊ��ŦԪ

	int location = low-1;//locationָ���pivotС��Ԫ�ضε�β��

	for(int i = low; i < high; i++)//����ŦԪС��Ԫ�����η���ǰ�벿��

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
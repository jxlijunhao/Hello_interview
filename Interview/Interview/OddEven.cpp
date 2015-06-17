/************************************************************************/
/* 奇偶调序                                                             */
/************************************************************************/

#include<iostream>
using namespace std;

//void OddEven(int *arr,int len)
//{
//	if (arr==NULL || len<1)
//		return;
//
//	int low=0;
//	int high=len-1;
//
//	while (low<high)
//	{
//		//同为偶数时
//		if (arr[low]%2==0 && arr[high]%2==0)
//			high--;
//		//同为奇数时
//		if (arr[low]%2!=0 && arr[high]%2!=0)
//			low++;
//		//一偶一奇
//		if (arr[low]%2==0 && arr[high]%2!=0)
//		{
//			swap(arr[low],arr[high]);
//			low++;
//			high--;
//		}
//		if (arr[low]%2!=0 && arr[high]%2==0)
//		{
//			low++;
//			high--;
//		}
//	}
//}

void OddEven(int *arr,int len)
{
	if (arr==NULL || len<1)
		return;

	int low=0;
	int high=len-1;

	while (low<high)
	{
		if ((arr[low]&1)==1)
			low++;
		else if ((arr[high]&1)!=1)
		    high--;
		else
		{
			swap(arr[low],arr[high]);	
			low++;
			high--;
		}
	}
}



//int main()
//{
//	int arr[6]={1,2,3,4,5,6};
//	OddEven(arr,6);
//	for (int i=0;i<6;i++)
//		cout<<arr[i]<<" ";
//	cout<<endl;
//	return 0;
//}
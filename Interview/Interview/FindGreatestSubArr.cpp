/************************************************************************/
/* 最大连续子数组和                                                       */
/************************************************************************/

#include<iostream>
using namespace std;

int FindGreatestSubArr(int *arr,int length,int *pBegin,int *pEnd)
{
	if (arr==NULL || length<0)
		return 0;

	int curSum=0,maxSum=0;
	int j=0,k=0;
	
	for (int i=0;i<length;i++)
	{
		if (curSum<=0)
		{
			curSum=arr[i];
			*pBegin=i;
		}
		else
		{
			curSum=curSum+arr[i];
			*pEnd=i;
		}

		if (curSum>=maxSum)
			maxSum=curSum;
	}
	return maxSum;
}

void printArr(int *arr,int pBegin,int pEnd)
{
	for (int i=pBegin;i<pEnd;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//int main()
//{
//	int a[]={1,-2,3,10,-4,7,2,-5};
//	int pBegin=0,pEnd=0;
//	int maxSum=FindGreatestSubArr(a,8,&pBegin,&pEnd);
//    cout<<maxSum<<endl;
//	printArr(a,pBegin,pEnd);
//	return 0;
//}
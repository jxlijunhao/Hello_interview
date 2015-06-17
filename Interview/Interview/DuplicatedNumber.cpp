/************************************************************************/
/* 找出数组中唯一的重复元素                                               */
/************************************************************************/
//问题描述：1-1000放在含有1001个元素的数组中，只有唯一的一个元素值重复，其它均只出现一次


#include<iostream>
using namespace std;

int DuplicatedNumber(int *inputArray,int len)
{
	if (inputArray==NULL || len<1)
		return 0;
	long long SUM=0;
	long long realSUM=0;

	for (int i=0;i<len;i++)
	{
		SUM+=inputArray[i];
		realSUM+=i;
	}

	return SUM-realSUM;
}

int DuplicatedNumber_new(int *inputArray,int len)
{
	if (inputArray==NULL || len<1)
		return 0;
	int XOResult_new=0;//用来保存这个实际数组中每个数字的异或的结果
	int XOResult_old=0;//用来保存无重复数组中每个数字的异或的结果
	for (int i=0;i<len;i++) 
	{
		XOResult_new^=inputArray[i];
		XOResult_old^=i;
	}
	return XOResult_old^XOResult_new;

}


//int main()
//{
//	int inputArray[6]={1,2,3,3,4,5};
//	cout<<DuplicatedNumber_new(inputArray,6);
//	return 0;
//	
//}
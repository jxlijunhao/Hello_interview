/************************************************************************/
/* 寻找和为定值的两个数                                                   */
/************************************************************************/

//解题思路：设定两个指针pBegin,pEnd分别指向这个数组的第一个位置及最后一个位置，
//         当data[*pBegin]+data[*pEnd]>sum,pEnd--,
//         当data[*pBegin]+data[*pEnd]<sum,pBegin++,
//         当data[*pBegin]+data[*pEnd]==sum,return pBeign,pEnd

//解题技巧：当要返回两个，或者多个变量时，要在输入参数中设定多个指针，通过指针来返回

#include<iostream>
using namespace std;

//这种写法只能返回一对满足条件的值
bool FindNumberWithSum1(int *data,int length,int sum,int *num1,int *num2)
{
	bool isFound=false;
	if (data==NULL || num1==NULL || num2==NULL)
		return isFound;

	int pBegin=0;
	int pEnd=length-1;

	while(pBegin<pEnd)
	{
		long long curSum=data[pBegin]+data[pEnd];
		if (curSum==sum)
		{
			*num1=pBegin;
			*num2=pEnd;
			isFound=true;
			break;
		}
		else if (curSum>sum)
		{
			pEnd--;
		}
		else
		{
			pBegin++;
		}
	}
	return isFound;
}

bool FindNumberWithSum2(int *data,int length,int sum)
{
	bool isFound=false;
	if (data==NULL )
		return isFound;

	int pBegin=0;
	int pEnd=length-1;

	while(pBegin<pEnd)
	{
		long long curSum=data[pBegin]+data[pEnd];
		if (curSum==sum)
		{			 
			isFound=true;
			if (isFound)
			{
				cout<<*(data+pBegin)<<" "<<*(data+pEnd)<<endl;
				pBegin++;
				pEnd--;
			}
			continue;
		}
		else if (curSum>sum)
		{
			pEnd--;
		}
		else
		{
			pBegin++;
		}
	}
	return isFound;
}

//int main()
//{
//	int data[7]={1,2,4,7,8,11,15};
//	int num1,num2;
//	bool isFound=FindNumberWithSum(data,7,15,&num1,&num2);
//	if (isFound)
//	{
//		cout<<data[num1]<<" "<<data[num2]<<endl;
//	}
//	else
//	{
//		cout<<"Not Found"<<endl;
//	}
//	return 0;
//}


//int main()
//{
//	int data[7]={1,2,4,7,8,11,15};
//	
//	bool isFound=FindNumberWithSum2(data,7,15);
//	 
//	return 0;
//}
/************************************************************************/
/* Ѱ�Һ�Ϊ��ֵ��������                                                   */
/************************************************************************/

//����˼·���趨����ָ��pBegin,pEnd�ֱ�ָ���������ĵ�һ��λ�ü����һ��λ�ã�
//         ��data[*pBegin]+data[*pEnd]>sum,pEnd--,
//         ��data[*pBegin]+data[*pEnd]<sum,pBegin++,
//         ��data[*pBegin]+data[*pEnd]==sum,return pBeign,pEnd

//���⼼�ɣ���Ҫ�������������߶������ʱ��Ҫ������������趨���ָ�룬ͨ��ָ��������

#include<iostream>
using namespace std;

//����д��ֻ�ܷ���һ������������ֵ
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
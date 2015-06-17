/************************************************************************/
/* �ҳ�������Ψһ���ظ�Ԫ��                                               */
/************************************************************************/
//����������1-1000���ں���1001��Ԫ�ص������У�ֻ��Ψһ��һ��Ԫ��ֵ�ظ���������ֻ����һ��


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
	int XOResult_new=0;//�����������ʵ��������ÿ�����ֵ����Ľ��
	int XOResult_old=0;//�����������ظ�������ÿ�����ֵ����Ľ��
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
/************************************************************************/
/* �ϲ������Ѿ���������飬����һ���������������һ������                     */
/************************************************************************/

#include<iostream>
using namespace std;

void MergeSortedArr(int *longArr,int *shortArr,int llen,int slen)
{
	if (longArr==NULL || shortArr==NULL || llen<slen ||llen<0)
	{
		return;
	}
	int longEnd=llen-slen-1; //��������Ч����ĩβλ��
	int shortEnd=slen-1;
	int k=llen-1;


	while (longEnd>=0 && shortEnd>=0)
	{
		if (longArr[longEnd]>shortArr[shortEnd])
		{
			longArr[k--]=longArr[longEnd--];
		}
		else
		{
			longArr[k--]=shortArr[shortEnd--];
		}
	}

	//��ĳһ�������Ƚ���ʱ
	while (longEnd>=0)
	{
		longArr[k--]=longArr[longEnd--];
	}

	while (shortEnd>=0)
	{
		longArr[k--]=shortArr[shortEnd--];
	}
}

//int main()
//{
//	int a[10]={1,2,3,4,6};
//	int b[5]={5,7,8,9,10};
//	MergeSortedArr(a,b,10,5);
//
//	for (int i=0;i<10;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
//	return 0;
//}
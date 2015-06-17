/************************************************************************/
/* ������������                                                          */
/************************************************************************/

//����˼·��0������0��1��2�ֱ�����ʾ�������ɫ��
//	       1���趨����ָ�룬pBegin,pEnd,�Լ���һ��pCurrent,����������������ɨ����������
//	       2�� a.��pCurrentָ���Ϊ0ʱ��˵��Ҫ������ŵ�ǰ��ȥ����pBegin���н�����pBegin++,pCurrent++; 
//             b.��pCurrentָ���Ϊ1ʱ��˵��Ҫ������ŵ��м䣬���ǲ�������pCurrent++;
//             c.��pCurrentָ���Ϊ2ʱ��˵��Ҫ������ŵ�����ȥ������������pEnd���н�����pEnd--,��ʱ���ص�a


//��Ŀ���Σ�
//����һ��array of character��������digits�� lower case char and upper case char�� 
//��β��ܰ�����sort������digits��ǰ�� ����lower case���м䣬 upper case �����

#include<iostream>
#include<ctype.h>
using namespace std;

void DutchFlags_digits(int *inputArray,int len)
{
	if (inputArray==NULL || len<1)
		return;

	int pBegin=0;
	int pEnd=len-1;
	int pCurrent=0;

	while (pCurrent<=pEnd)
	{
		if (inputArray[pCurrent]==0)
		{
			swap(inputArray[pCurrent],inputArray[pBegin]);
			pCurrent++;
			pBegin++;
		} else if (inputArray[pCurrent]==2)
		{
			swap(inputArray[pCurrent],inputArray[pEnd]);
			pEnd--;
		}else
		{
			pCurrent++;
		}
	}
}

void DutchFlags_char(char *inputArray,int len)
{
	if (inputArray==NULL || len<1)
		return;

	int pBegin=0;
	int pEnd=len-1;
	int pCurrent=0;

	while (pCurrent<=pEnd)
	{
		if (inputArray[pCurrent]=='R')
		{
			swap(inputArray[pCurrent],inputArray[pBegin]);
			pCurrent++;
			pBegin++;
		} else if (inputArray[pCurrent]=='B')
		{
			swap(inputArray[pCurrent],inputArray[pEnd]);
			pEnd--;
		}else
		{
			pCurrent++;
		}
	}
}

void DutchFlags_charDigits(char *inputArray,int len)
{
	if (inputArray==NULL || len<1)
		return;

	int pBegin=0;
	int pEnd=len-1;
	int pCurrent=0;

	while (pCurrent<=pEnd)
	{
		if (isdigit(inputArray[pCurrent]))
		{
			swap(inputArray[pCurrent],inputArray[pBegin]);
			pBegin++;
			pCurrent++;
		}else if (isupper(inputArray[pCurrent]))
		{
			swap(inputArray[pCurrent],inputArray[pEnd]);
			pEnd--;
		}else
			pCurrent++;		
	}
}





//int main()
//{
//	int inputArr[]={0,1,2,0,1,2,1};
//	DutchFlags_digits(inputArr,sizeof(inputArr)/sizeof(int));
//
//	for (int i=0;i<sizeof(inputArr)/sizeof(int);i++)
//	{
//		cout<<inputArr[i]<<" ";
//	}
//	cout<<endl;
//
//	char inputChar[]="RGBBGRRRRBG";
//	int len=strlen(inputChar);
//	DutchFlags_char(inputChar,len);
//
//	for (int i=0;i<len;i++)
//	{
//		cout<<inputChar[i]<<" ";
//	}
//	cout<<endl;
//
//	char inputCharDigits[]="abcE123cdDBC09e";
//	int len1=strlen(inputCharDigits);
//	DutchFlags_charDigits(inputCharDigits,len1);
//
//	for (int i=0;i<len1;i++)
//	{
//		cout<<inputCharDigits[i]<<" ";
//	}
//	cout<<endl;
//
//
//	return 0;
//}
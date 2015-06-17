/************************************************************************/
/* 荷兰国旗问题                                                          */
/************************************************************************/

//解题思路：0）利用0，1，2分别来表示国旗的颜色；
//	       1）设定三个指针，pBegin,pEnd,以及另一个pCurrent,用来从左向右依次扫描整个数组
//	       2） a.当pCurrent指向的为0时，说明要把这个放到前面去，与pBegin进行交换，pBegin++,pCurrent++; 
//             b.当pCurrent指向的为1时，说明要把这个放到中间，我们不做处理，pCurrent++;
//             c.当pCurrent指向的为2时，说明要把这个放到后面去，我们让其与pEnd进行交换，pEnd--,此时返回到a


//题目变形：
//给你一个array of character，包括有digits， lower case char and upper case char， 
//如何才能把他们sort成所有digits在前， 所有lower case在中间， upper case 在最后

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
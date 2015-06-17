/************************************************************************/
/* 找到数组中单独出现的两个数字                                            */
/************************************************************************/

//问题1：
//数组中的除了两个数之外，其他的数都是两两出现的，找出它们，时间复杂度为O(n),空间复杂度为O(1)
//解题思路：异或的应用
//         1,先依次找从左到右对数组进行异或运算，得到最后的异或结果XOResult
//         2,找出XOResult中第一个是1的位置,记为N；
//         3,根据每个数字的第N位是否为1，将数组分成两部分，得到两个数组，然后分别对其进行异或，就可以得到最终的两个数字

//问题2：
//给你1-1000个连续自然数，然后从中随机去掉两个，再打乱顺序，要求只遍历一次，求出被去掉的两个数

#include<iostream>
using namespace std;

//找出一个二进位里面第一个出现为1的
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 32))
	{
		num = num >> 1;
		++ indexBit;
	}
	return indexBit;
}
//用来判断对应位置上是不是为1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}



void FindNumberAppearOnce(int *inputArray,int len,int &num1,int &num2)
{
	if (inputArray==NULL ||len<1)
		return;

	//得到整个数组的异或结果
	int XOResult=0;
	for (int i=0;i<len;i++)
		XOResult^=inputArray[i];

	//找出这个异或结果中第一个出现是1的位置N
	int N=FindFirstBitIs1(XOResult);

	num1=num2=0;
	for (int i=0;i<len;i++)
	{
		if (IsBit1(inputArray[i],N))
			num1^=inputArray[i];
		else
			num2^=inputArray[i];
	}

}

void FindNumberMissed(int *inputArray,int *inputArrayNew,int len,int &num1,int &num2)
{
	if (inputArray==NULL ||len<1)
		return;

	//得到整个数组的异或结果
	int XOResult_orginal=0;
	int XOResult_new=0;
	int XOR=0;//很用对上面的两个结果进行异或

	for (int i=0;i<len;i++)
		XOResult_orginal^=inputArray[i];

	for (int i=0;i<len-2;i++)
		XOResult_new^=inputArray[i];

	XOR=XOResult_orginal^XOResult_new;
	//找出这个异或结果中第一个出现是1的位置N
	int N=FindFirstBitIs1(XOR);
	//根据得到的N对原来的数组，以及新的数组进行划分
	int num1_orginal=0,num2_orginal=0;
	int num1_new=0,num2_new=0;

	//对原数组进行划分
	for (int i=0;i<len;i++)
	{
		if (IsBit1(inputArray[i],N))
			num1_orginal^=inputArray[i];
		else
			num2_orginal^=inputArray[i];
	}
	//对新数组进行划分
	for (int i=0;i<len-2;i++)
	{
		if (IsBit1(inputArrayNew[i],N))
			num1_new^=inputArrayNew[i];
		else
			num2_new^=inputArrayNew[i];
	}

	num1=num1_orginal^num1_new;
	num2=num2_orginal^num2_new;

}

//int main()
//{
//	int inputArray[]={1,1,2,3,5,5};
//	int num1,num2;
//	FindNumberAppearOnce(inputArray,sizeof(inputArray)/sizeof(int),num1,num2);
//	cout<<"num1= "<<num1<<endl<<"num2= "<<num2<<endl;
//	return 0;
//}

//int main()
//{
//	int inputArray[]={1,2,3,4,5,6,7,8,9,10};
//	int inputArray_new[]={2,3,4,5,6,7,8,9};
//	int num1,num2;
//	FindNumberMissed(inputArray,inputArray_new,sizeof(inputArray)/sizeof(int),num1,num2);
//	cout<<"num1= "<<num1<<endl<<"num2= "<<num2<<endl;
//	return 0;
//}

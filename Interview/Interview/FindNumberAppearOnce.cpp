/************************************************************************/
/* �ҵ������е������ֵ���������                                            */
/************************************************************************/

//����1��
//�����еĳ���������֮�⣬�������������������ֵģ��ҳ����ǣ�ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)
//����˼·������Ӧ��
//         1,�������Ҵ����Ҷ��������������㣬�õ����������XOResult
//         2,�ҳ�XOResult�е�һ����1��λ��,��ΪN��
//         3,����ÿ�����ֵĵ�Nλ�Ƿ�Ϊ1��������ֳ������֣��õ��������飬Ȼ��ֱ���������򣬾Ϳ��Եõ����յ���������

//����2��
//����1-1000��������Ȼ����Ȼ��������ȥ���������ٴ���˳��Ҫ��ֻ����һ�Σ������ȥ����������

#include<iostream>
using namespace std;

//�ҳ�һ������λ�����һ������Ϊ1��
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
//�����ж϶�Ӧλ�����ǲ���Ϊ1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}



void FindNumberAppearOnce(int *inputArray,int len,int &num1,int &num2)
{
	if (inputArray==NULL ||len<1)
		return;

	//�õ���������������
	int XOResult=0;
	for (int i=0;i<len;i++)
		XOResult^=inputArray[i];

	//�ҳ����������е�һ��������1��λ��N
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

	//�õ���������������
	int XOResult_orginal=0;
	int XOResult_new=0;
	int XOR=0;//���ö��������������������

	for (int i=0;i<len;i++)
		XOResult_orginal^=inputArray[i];

	for (int i=0;i<len-2;i++)
		XOResult_new^=inputArray[i];

	XOR=XOResult_orginal^XOResult_new;
	//�ҳ����������е�һ��������1��λ��N
	int N=FindFirstBitIs1(XOR);
	//���ݵõ���N��ԭ�������飬�Լ��µ�������л���
	int num1_orginal=0,num2_orginal=0;
	int num1_new=0,num2_new=0;

	//��ԭ������л���
	for (int i=0;i<len;i++)
	{
		if (IsBit1(inputArray[i],N))
			num1_orginal^=inputArray[i];
		else
			num2_orginal^=inputArray[i];
	}
	//����������л���
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

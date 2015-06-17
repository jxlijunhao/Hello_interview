/************************************************************************/
/*   寻找最小的k个数                                                     */
/************************************************************************/

//解题思路：因为不要求这k个数是排好序的，可以利用快速排序方法中partition方法，
//         找到一个主元位置，使得前面的数都要比其小


#include<iostream>
#include<string>
using namespace std;

int Partition(int array[],int low,int high)
{
	int pivotData=array[low];
	int litteInd=low;
	int highInd=high;

	while (litteInd<highInd)
	{
		while (litteInd<highInd && array[highInd]>=pivotData)
			--highInd;
		if (litteInd<highInd)
			array[litteInd++]=array[highInd];

		while (litteInd<highInd && array[litteInd]<=pivotData)
			++litteInd;
		if (litteInd<highInd)
			array[highInd--]=array[litteInd];
	}
	array[highInd]=pivotData;
	return highInd;
}

void GetLeastKNumbers(int inputArray[],int outputArray[],int k,int n)
{
	if (inputArray==NULL || outputArray==NULL || k<=0 || k>n)
		return;

	int Start=0;
	int End=n-1;

	int pivot=Partition(inputArray,Start,End);
	while (pivot!=k-1)
	{
		if (pivot>k-1) //说明还要向前找
		{
			End=pivot-1;
			pivot=Partition(inputArray,Start,End);
		}
		else
		{
			Start=pivot+1;
			pivot=Partition(inputArray,Start,End);
		}
	}

	for (int i=0;i<k;i++)
		outputArray[i]=inputArray[i];
}

//int main()
//{
//	int inputArray[]={4,5,1,6,2,7,3,8};
//	const int k=4;
//	int outputArray[k]={0};
//	GetLeastKNumbers(inputArray,outputArray,k,8);
//
//	for (int i=0;i<k;i++)
//		cout<<outputArray[i]<<" ";
//	cout<<endl;
//	return 0;
//}

//int main()
//{
//	string str[]={"A"};
//	string strArr1[]={"Trend","Micro","Soft"};
//	string *pStrArr1=new string[2];
//	pStrArr1[0]="US";
//	pStrArr1[1]="CN";
//
//	cout<<"sizeof(str)=="<<sizeof(str)<<endl;
//	cout<<"sizeof(strArr1)=="<<sizeof(strArr1)<<endl;
//	cout<<"sizeof(string)=="<<sizeof(string)<<endl;
//	cout<<"sizeof(strArr1)/sizeof(string)="<<sizeof(strArr1)/sizeof(string)<<endl;
//	cout<<"sizeof(pStrArr1)=="<<sizeof(pStrArr1)<<endl;
//	cout<<"sizeof(*pStrArr1)=="<<sizeof(*pStrArr1)<<endl;
//
//	for (int i=0;i<sizeof(strArr1)/sizeof(string);i++)
//		cout<<strArr1[i];
//
//	for (int j=0;j<sizeof(pStrArr1)/sizeof(string);j++)
//		cout<<pStrArr1[j];
//
//	return 0;
//}
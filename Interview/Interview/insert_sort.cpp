#include<iostream>
using namespace std;

void insert_sort(int inputArray[],int len)
{
	int i,j,k;
	for(i = 1; i < len ; i++)
	{
		for (j = i-1; j >=0 ;j--)
		{
			if (inputArray[j] < inputArray[i])
				break;
		}

		if (j != i-1)
		{
			int temp = inputArray[i];
			for (k = i-1; k>j ;k--)
			{				
				inputArray[k+1] = inputArray[k];
			}
			inputArray[k+1] = temp;
		}

	}
}

//int main()
//{
//	int inputArray[10]={2,1,3,4,6,5,8,7,9,10};
//	insert_sort(inputArray,10);
//
//	for (int i=0;i<10;i++)
//	{
//		cout<<inputArray[i]<<" ";
//	}
//	return 0;
//}
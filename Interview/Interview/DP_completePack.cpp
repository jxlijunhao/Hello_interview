//#include <iostream>
//#include <assert.h>
//using namespace std;
/*
f[i][v]:ǰi����Ʒ���뱳������Ϊv�ı�����õ��������

f[i][v] = max(f[i - 1][v],f[i - 1][v - k * Wi] + k * Vi,���� 1<=k<= v/Wi)

�߽�����
f[0][v] = 0;
f[i][0] = 0;
*/

//const int N = 3;
//const int V = 5;
//int weight[N + 1] = {0,3,2,2};
//int Value[N + 1] = {0,5,10,20};
//
//int f[N + 1][V + 1] = {0};
//
//int Completeknapsack()
//{
//	//�߽�����
//	for (int i = 0;i <= N;i++)
//	{
//		f[i][0] = 0;
//	}
//	for (int v = 0;v <= V;v++)
//	{
//		f[0][v] = 0;
//	}
//	//����
//	for (int i = 1;i <= N;i++)
//	{
//		for (int v = 1;v <= V;v++)
//		{
//			f[i][v] = 0;
//			int nCount = v / weight[i];
//			for (int k = 0;k <= nCount;k++)
//			{
//				f[i][v] = max(f[i][v],f[i - 1][v - k * weight[i]] + k * Value[i]);
//			}
//		}
//	}
//	return f[N][V];
//}
//
////int main()
////{
////	cout<<Completeknapsack()<<endl;
////	system("pause");
////	return 1;
////}

#include <iostream>
#include <assert.h>
using namespace std;

const int N = 3;
const int V = 5;
int weight[N + 1] = {0,3,2,2};
int Value[N + 1] = {0,5,10,20};

int f[N + 1][V + 1] = {{0}};

int completeSack()
{
	for (int i = 0;i <=N;i++)
		f[i][0]=0;

	for (int j =0; j<=V;j++)
		f[0][j]=0;

	
	for (int i = 1;i <=N;i++)
	{
		for (int j=weight[i];j<=V;j++)
		{
			 f[i][j] = max(f[i-1][j],f[i][j-weight[i]]+Value[i]);
		}
	}
	return f[N][V];
}

void printResut1()
{
	int i=N;
	int j=V;

	while (i)
	{
		if (f[i][j] == f[i][j-weight[i]]+Value[i])
		{
			cout<<i<<" ";
			j=j-weight[i];
		}
		i--;			
	}
}


//int main()
//{
//	cout<<completeSack()<<endl;	 
//	printResut1();
//	return 1;
//}
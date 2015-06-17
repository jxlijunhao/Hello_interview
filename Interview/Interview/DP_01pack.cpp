//#include <iostream>
//using namespace std;
//
//const int nPack=3; //物体个数
//const int nVol=5;  //背包容量
//
//int weights[nPack+1] = {0,3,2,2};
//int values[nPack+1] =  {0,5,10,20};
//
//int f[nPack+1][nVol+1] = {{0}};//二维数组进行存储
////int f[nVol+1] = {0};//一维数据进行存储，优化空间
//
//int label[nPack+1][nVol+1] = {{0}};//最优解追踪
//
//int knapsack_01()
//{
//	memset(f,0,sizeof(f));
//	memset(label,0,sizeof(label));
//
//	for (int i = 1; i <= nPack; i++) //枚举物品
//	{
//		for (int j = 1;j <=nVol; j++)
//		{
//			f[i][j] = f[i-1][j];
//			if (j >= weights[i] )
//			{
//				f[i][j] = max(f[i-1][j],f[i-1][j-weights[i]]+values[i]);
//			}
//		}
//	}
//	return f[nPack][nVol];
//}
//
//void printResut()
//{
//	int i=nPack;
//	int j=nVol;
//	
//	while (i)
//	{
//		if (f[i][j]==f[i-1][j-weights[i]]+values[i])
//		{
//			cout<<i<<" ";
//			j=j-weights[i];
//		}
//		i--;
//	}
//}
//
//
//int main()
//{
//	cout<<knapsack_01()<<endl;
//	printResut();
//	return 1;
//}


#include <iostream>
using namespace std;

const int nPack=3; //物体个数
const int nVol=5;  //背包容量

int weights[nPack+1] = {0,3,2,2};
int values[nPack+1] =  {0,5,10,20};
 
int f[nVol+1] = {0};//一维数据进行存储，优化空间
int label[nPack+1][nVol+1]={{0}};//解存储

int knapsack01()
{
	memset(f,0,sizeof(f));
	memset(label,0,sizeof(label));

	for (int i = 1;i <= nPack; i++) //枚举物品
	{
		for ( int j=nVol; j>=weights[i]; j--)
		{
			if (f[j] < f[j-weights[i]]+values[i])
			{
				f[j] = f[j-weights[i]]+values[i];
				label[i][j] = 1;
			}
			
		}
	}
	return f[nVol];
}

void printResult()
{
	int i = nPack;
	int j = nVol;

	while (i)
	{
		if (label[i][j] == 1)
		{
			cout<<i<<" ";
			j=j-weights[i];
		}
		i--;
	}
}

//int main()
//{
//	cout<<knapsack01()<<endl;
//	printResult();
//	return 1;
//}
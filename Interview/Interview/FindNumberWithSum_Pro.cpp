/************************************************************************/
/* 和为定值的连续多个数                                                   */
/************************************************************************/

//解题思路：初始化两个起始的数，pBegin=1,pEnd=2,
//         当pBegin+pEnd<sum,pEnd++,增加一个数
//         当pBegin+pEnd>sum,pBegin++，减少一个数

#include<iostream>
using namespace std;

void print(int pBeign,int pEnd)
{
	for(int i=pBeign;i<=pEnd;i++)
		cout<<i<<" ";
	cout<<endl;
}
void FindNumberWithSum_Pro(int sum)
{
	if (sum<3)
		return ;
	int pBegin=1;
	int pEnd=2;
	//能找到这一点很重要
	int middle=(1+sum)>>2;
	int curSum=pBegin+pEnd;
	while (pBegin<middle)
	{
		if (curSum==sum)
			print(pBegin,pEnd);
		while (curSum>sum && pBegin<middle)
		{
			curSum=curSum-pBegin;
			pBegin++;

			if (curSum==sum)
				print(pBegin,pEnd);
		}
		pEnd++;
		curSum+=pEnd;
	}
}



//int main()
//{
//	FindNumberWithSum_Pro(15);
//}
/************************************************************************/
/* ��Ϊ��ֵ�����������                                                   */
/************************************************************************/

//����˼·����ʼ��������ʼ������pBegin=1,pEnd=2,
//         ��pBegin+pEnd<sum,pEnd++,����һ����
//         ��pBegin+pEnd>sum,pBegin++������һ����

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
	//���ҵ���һ�����Ҫ
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
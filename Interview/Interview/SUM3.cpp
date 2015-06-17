/************************************************************************/
/* 3SUM：返回3个数相加等于0                                               */
/************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int BinarySearch1(int *Arr,int len,int key)
{
	if (Arr==NULL)
		return NULL;

	int Start=0;
	int End=len-1;
	int mid=0;

	while(Start<=End)
	{
		mid=(Start+End)>>1;
		if (Arr[mid]==key)
			return Arr[mid];
		else if (Arr[mid]<key)
			Start=mid+1;
		else
			End=mid-1;		
	}
	return NULL;
}

vector<vector<int>>* SUM_3(int *arr,int len)
{
	if (arr==NULL|| len<3)
		return NULL;

	vector<vector<int>> *pResult=new vector<vector<int>>();

	for (int i=0;i<len;i++)
	{
		int v1=arr[i];
		for (int j=i+1;j<len;j++)
		{
			int v2=arr[j];
			int v3=-v1-v2;
			//这样做出来的结果会包含重复的，如（-1，1，0） （0，1，-1），只不过是顺序不一样而已
			if (BinarySearch1(arr,len,v3))
			{
				vector<int>*pTriple=new vector<int>(3);
				vector<int>& triple=*pTriple;
				triple[0]=v1;
				triple[1]=v2;
				triple[2]=v3;
				sort(triple.begin(),triple.end());
				(*pResult).push_back(triple);
			}

		}
	}
	sort(pResult->begin(),pResult->end());
	pResult->erase(unique(pResult->begin(),pResult->end()),pResult->end());
	return pResult;
}

//int main()
//{
//	int arr[6]={-1,0,1,2,-1,-4};
//	vector<vector<int>> *p=SUM_3(arr,6);
//	 
//	for (vector<vector<int>>::iterator iter=p->begin();iter!=p->end();iter++) 
//	{
//		for (vector<int>::iterator it=iter->begin();it!=iter->end();it++)
//			cout<<*it<<" ";
//		cout<<endl;
//	}
//
//}
/************************************************************************/
/* top k: 堆                                                            */
/************************************************************************/

#include<iostream>
#include<time.h>
#include<assert.h>
using namespace std;

int randint(int l,int u)
{
	return 1+(RAND_MAX*rand()+rand())%(u-l+1);
}

const int size =10000;
int num[size];




//建立类
template<class T>
class CTopK
{
public:
	CTopK();
	~CTopK();
	T *m_data; //指向一个大数组
	int GetTopK(const char *sFile, int & nTop);//从文件中读取nTop个元素存入数组
private:
	void Clear();
	void HeapAdjust(int low,int high);
	void BuildHeap(int nLen);
};

template<class T>
CTopK<T>::CTopK()
{
	m_data=NULL;
}

template <class T>
void CTopK<T>::Clear()
{
	if (m_data=NULL)
	{
		delete [] m_data;
		m_data=NULL;
	}
}
template<class T>
CTopK<T>::~CTopK()
{
	Clear();
}



template <class T>
int CTopK<T>::GetTopK(const char *sFile, int &nTop)
{
	FILE *fp=NULL;
	T fData;
	int i;

	if (sFile==NULL || nTop<=0)
	{
		cout<<"error parameter"<<endl;
		return -1;
	}
	Clear();
	fp=fopen(sFile,"r");

	m_data= new T[nTop];
	if (m_data==NULL)
	{
		cout<<"error"<<endl;
		return -1;
	}

	//read
	for (i=0;i<nTop;i++)
	{
		if (EOF!=fscanf(fp,"%d",&fData))
		{
			m_data[i]=fData;
		}
		else
		{
			break;
		}
	}

	if (i<nTop)
	{
		nTop=i;
	}
	else
	{
		BuildHeap(nTop);
		while (EOF !=fscanf(fp,"%d",&fData))
		{
			if (fData>m_data[0])
			{
				m_data[0]=fData;
				HeapAdjust(0,nTop);
			}
		}
	}
	return 0;
}

template <class T>
void CTopK<T>::HeapAdjust(int low,int high)
{ 
	int lChild;
	int cur=low;

	int temp=m_data[cur];

	for (lChild=2*cur+1; lChild<=high ; lChild=2*lChild+1)
	{
		if (lChild<high && m_data[lChild]>m_data[lChild+1])
			lChild++;

		if (temp<=m_data[lChild])
			break;
		else
		{
			m_data[cur]=m_data[lChild];
			cur=lChild;
		}
	}
	m_data[cur]=temp;
}

template <class T>
void CTopK<T>::BuildHeap(int nLen)
{
	for (int i=nLen/2-1;i>=0;--i)
	{
		HeapAdjust(i,nLen-1);
	}
}


//int main()
//{
//	int i,j;
//	FILE *fp=fopen("data.txt","w");
//	assert(fp);
//
//	for (i=0;i<size;i++)
//		num[i]=i+1;
//
//	srand((unsigned)time(NULL));
//	for (i=0;i<size;i++)
//	{
//		j=randint(i,size-1);
//		int t=num[i];
//		num[i]=num[j];
//		num[j]=t;
//	}
//
//	for (i=0;i<size;i++)
//		fprintf(fp,"%d ",num[i]);
//	fclose(fp);
//
//}

//int main()
//{
//	char szFile[400]="C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\Interview\\Interview\\data.txt";
//	int nNum=0;
//	CTopK<int> objTopSum;
//	
//	nNum=10; 
//	objTopSum.GetTopK(szFile, nNum);  
//
//	int fSum = 0;  
//	for (int i = 0; i < nNum; i++)  
//	{  
//		cout<<objTopSum.m_data[i]<<" ";  
//		fSum += objTopSum.m_data[i];  
//	}  
//	cout << "\ntop " << nNum << " value = " << fSum << endl;  
//
//	return 0;  
//
//}
/************************************************************************/
/* ����                                                               */
/************************************************************************/

// i, 2*i+1, 2*i+2,��0��ʼ����

#include<stdio.h>
#include<stdlib.h>

//��������ĳ���
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

#define MaxLen 30
static int m_heap[MaxLen];
static int m_capacity=MaxLen; //�ѵ��������
static int m_size=0;          //�ѵ�ʵ�ʳ���

//����һ��data�������е�����

int get_index(int data)
{	 
	int i;
	for (i=0;i<m_size;i++)
	{
		if (data==m_heap[i])
			return i;
	}
	return -1;
}

//�������µ����㷨����Ҫ����ɾ�������ѵĸ����󣬽����������һ��Ԫ��
//�ŵ�����㣬Ȼ����� ���˹���

static void maxHeap_filterDown(int start,int end)
{
	int current=start;//��ǰ�ڵ��λ��
	int lChild=2*current+1;//���ӽ��
	int tmp=m_heap[current];//��ǰ���洢�����ݴ�С

	while (lChild<end)
	{
		//lChild+1: ��ʾ�Һ��ӽ��
		if (lChild<end && m_heap[lChild]<m_heap[lChild+1])
			lChild++; //�����ӻ����Һ��ӣ����н���

		if (tmp>=m_heap[lChild])
			break;
		else
		{
			m_heap[current]=m_heap[lChild];//���Һ����У��ϴ�Ĵ����丸��㣬������½�һ��
			current=lChild;               //���µ�ǰ�ڵ��λ��
			lChild=2*lChild+1;            
		}
	}
	m_heap[current]=tmp; 
}

//ɾ�������е�Ԫ��
int maxHeapRemove(int data)
{
	int index;
	//�����Ϊ�գ�����-1
	if (m_size==0)
		return -1;
	
	index=get_index(data);
	if (index==-1)
		return -1;
	//�����������һ��Ԫ�� �ŵ���ǰҪɾ��Ԫ�ص�λ�ã�Ȼ��ʼ���˲���
	m_heap[index]=m_heap[--m_size];
	maxHeap_filterDown(index,m_size-1);
	return 0;	
}

//����Ԫ�أ���Ҫ�����Ԫ�أ��ȷŵ����һ��λ�ã�Ȼ����� ���˲���

static void maxHeap_filterUp(int start)
{
	int current=start;
	int parent=(current-1)>>1;
	int tmp=m_heap[current];

	while (current>0)
	{
		if (m_heap[parent]>=tmp)
			break;
		else
		{
			m_heap[current]=m_heap[parent];
			current=parent;
			parent=(current-1)>>1;
		}	
	}
	m_heap[current]=tmp;
}

int maxHeapInsert(int data)
{
	if (m_size==m_capacity)
		return -1;

	m_heap[m_size]=data;
	maxHeap_filterUp(m_size);
	m_size++;
	return 0;
}

//��С�����µ����㷨����Ҫ����ɾ������С�ѵĸ����󣬽����������һ��Ԫ��
//�ŵ�����㣬Ȼ����� ���˹���

static void minHeap_filterDown(int start,int end)
{
	int current=start;        //��ǰ�ڵ��λ��
	int lChild=2*current+1;   //���ӽ��
	int tmp=m_heap[current];  //��ǰ���洢�����ݴ�С

	while (lChild<end)
	{
		//lChild+1:      ��ʾ�Һ��ӽ��
		if (lChild<end && m_heap[lChild]>m_heap[lChild+1])
			lChild++; //�����ӻ����Һ��ӣ����н���,ѡ�����н�Сһ��

		if (tmp<=m_heap[lChild])
			break;
		else
		{
			m_heap[current]=m_heap[lChild];//���Һ����У��ϴ�Ĵ����丸��㣬������½�һ��
			current=lChild;               //���µ�ǰ�ڵ��λ��
			lChild=2*lChild+1;            
		}
	}
	m_heap[current]=tmp; 
}
//ɾ����С���е�Ԫ��
int minHeapRemove(int data)
{
	int index;
	//�����Ϊ�գ�����-1
	if (m_size==0)
		return -1;

	index=get_index(data);
	if (index==-1)
		return -1;
	//�����������һ��Ԫ�� �ŵ���ǰҪɾ��Ԫ�ص�λ�ã�Ȼ��ʼ���˲���
	m_heap[index]=m_heap[--m_size];
	minHeap_filterDown(index,m_size-1);
	return 0;	
}


//����Ԫ�أ���Ҫ�����Ԫ�أ��ȷŵ����һ��λ�ã�Ȼ����� ���˲���

static void minHeap_filterUp(int start)
{
	int current=start;
	int parent=(current-1)>>1;
	int tmp=m_heap[current];

	while (current>0)
	{
		if (m_heap[parent]<=tmp)
			break;
		else
		{
			m_heap[current]=m_heap[parent];
			current=parent;
			parent=(current-1)>>1;
		}	
	}
	m_heap[current]=tmp;
}


int minHeapInsert(int data)
{
	if (m_size==m_capacity)
		return -1;

	m_heap[m_size]=data;
	minHeap_filterUp(m_size);
	m_size++;
	return 0;
}



void printHeap()
{
	for (int i=0;i<m_size;i++)
		printf("%d ",m_heap[i]);
	printf("\n");
}


//int main()
//{
//	/*int a[]={10, 40, 30, 60, 90, 70, 20, 50, 80};
//	int i,len=LENGTH(a);
//
//	printf("������ӣ�\n");
//	for (i=0;i<len;i++)
//	{
//	printf("%d ",a[i]);
//	maxHeapInsert(a[i]);
//	}
//	printf("\n");
//	printHeap();
//
//	maxHeapInsert(85);
//	printf("\n");
//	printHeap();
//
//	maxHeapRemove(90);
//	printf("\n");
//	printHeap();*/
//
//	int a[]={10, 40, 30, 60, 90, 70, 20, 50, 80};
//	int i,len=LENGTH(a);
//
//	printf("������ӣ�\n");
//	for (i=0;i<len;i++)
//	{
//		printf("%d ",a[i]);
//		minHeapInsert(a[i]);
//	}
//	printf("\n");
//	printHeap();
//
//	minHeapInsert(85);
//	printf("\n");
//	printHeap();
//
//	minHeapRemove(90);
//	printf("\n");
//	printHeap();
//	
//}
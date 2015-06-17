/************************************************************************/
/* 最大堆                                                               */
/************************************************************************/

// i, 2*i+1, 2*i+2,从0开始计数

#include<stdio.h>
#include<stdlib.h>

//计算数组的长度
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

#define MaxLen 30
static int m_heap[MaxLen];
static int m_capacity=MaxLen; //堆的最大容易
static int m_size=0;          //堆的实际长度

//返回一个data在数组中的索引

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

//最大堆向下调整算法，主要用于删除了最大堆的根结点后，将数组中最后一个元素
//放到根结点，然后进行 下滤过程

static void maxHeap_filterDown(int start,int end)
{
	int current=start;//当前节点的位置
	int lChild=2*current+1;//左孩子结点
	int tmp=m_heap[current];//当前结点存储的数据大小

	while (lChild<end)
	{
		//lChild+1: 表示右孩子结点
		if (lChild<end && m_heap[lChild]<m_heap[lChild+1])
			lChild++; //将左孩子换成右孩子，进行交换

		if (tmp>=m_heap[lChild])
			break;
		else
		{
			m_heap[current]=m_heap[lChild];//左右孩子中，较大的代替其父结点，父结点下降一层
			current=lChild;               //更新当前节点的位置
			lChild=2*lChild+1;            
		}
	}
	m_heap[current]=tmp; 
}

//删除最大堆中的元素
int maxHeapRemove(int data)
{
	int index;
	//如果堆为空，返回-1
	if (m_size==0)
		return -1;
	
	index=get_index(data);
	if (index==-1)
		return -1;
	//将数组中最后一个元素 放到当前要删除元素的位置，然后开始下滤操作
	m_heap[index]=m_heap[--m_size];
	maxHeap_filterDown(index,m_size-1);
	return 0;	
}

//插入元素，将要插入的元素，先放到最后一个位置，然后进行 上滤操作

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

//最小堆向下调整算法，主要用于删除了最小堆的根结点后，将数组中最后一个元素
//放到根结点，然后进行 下滤过程

static void minHeap_filterDown(int start,int end)
{
	int current=start;        //当前节点的位置
	int lChild=2*current+1;   //左孩子结点
	int tmp=m_heap[current];  //当前结点存储的数据大小

	while (lChild<end)
	{
		//lChild+1:      表示右孩子结点
		if (lChild<end && m_heap[lChild]>m_heap[lChild+1])
			lChild++; //将左孩子换成右孩子，进行交换,选择两中较小一个

		if (tmp<=m_heap[lChild])
			break;
		else
		{
			m_heap[current]=m_heap[lChild];//左右孩子中，较大的代替其父结点，父结点下降一层
			current=lChild;               //更新当前节点的位置
			lChild=2*lChild+1;            
		}
	}
	m_heap[current]=tmp; 
}
//删除最小堆中的元素
int minHeapRemove(int data)
{
	int index;
	//如果堆为空，返回-1
	if (m_size==0)
		return -1;

	index=get_index(data);
	if (index==-1)
		return -1;
	//将数组中最后一个元素 放到当前要删除元素的位置，然后开始下滤操作
	m_heap[index]=m_heap[--m_size];
	minHeap_filterDown(index,m_size-1);
	return 0;	
}


//插入元素，将要插入的元素，先放到最后一个位置，然后进行 上滤操作

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
//	printf("依次添加：\n");
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
//	printf("依次添加：\n");
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
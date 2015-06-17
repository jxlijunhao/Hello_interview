/************************************************************************/
/* 找到链表中倒数第k个数                                                  */
/************************************************************************/

//解题思路： 两个指针，一个指针先走k-1步，然后同另一个指针同时走，当先走的到达尾结点
//          时，另一个指针与其的间隔为k-1，那么这就是我们要找到的。
//要注意的地方：  1，要去判断k是否已经超出了链表长度；
//              2，先走k-1步，for(int i=0;i<k-1;i++) 不是k,否则找到的是倒数第k+1个



#include<iostream>
using namespace std;

//定义链表的结构体
typedef struct ListNode
{
	char data;
	struct ListNode *next;
}LIST,*pLIST;

//尾插法创建链表,不带空头节点的
void createList4(pLIST *head,char data)
{

	if ((*head)==NULL)
	{
		*head=(pLIST)malloc(sizeof(LIST));
		(*head)->data=data;
		(*head)->next=NULL;
	}
	else
	{
		LIST *p=(*head);
		LIST *newNode;
		while (p->next!=NULL)
		{
			p=p->next;
		}
		newNode=(LIST*)malloc(sizeof(LIST));
		newNode->next=NULL;
		newNode->data=data;
		p->next=newNode;
	}
}

ListNode* GetLastKNode(ListNode* pHead,int k)
{
	if (pHead==NULL|| k<0)
		return NULL;

	ListNode* p1=pHead;
	ListNode* p2=pHead;

	for (int i=0;i<k-1;i++)
	{
		//检测设定的k是否已经超过了总的链表长度
		if (p1->next!=NULL)
			p1=p1->next;
		else
			return NULL;	
	}

	while (p1->next!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	return p2;
}

//int main()
//{
//	char data[]="abcdefghi";
//	int len=strlen(data);
//	ListNode *head=NULL;
//
//	for (int i=0;i<len;i++)
//		createList4(&head,data[i]);
//
//	ListNode *p=GetLastKNode(head,2);
//	if (p!=NULL)
//		cout<<p->data<<endl;
//	else
//		cout<<"Error"<<endl;
//	return 0;
//
//}
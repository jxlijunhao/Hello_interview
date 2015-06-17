/************************************************************************/
/* 合并两个已经排序的链表，但不能创建第三个链表                              */
/************************************************************************/


#include<iostream>
using namespace std;

//定义链表的结构体
typedef struct ListNode
{
	char data;
	struct ListNode *next;
}LIST,*pLIST;

//尾插法创建链表,不带空头节点的
void createList3(pLIST *head,char data)
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

void printList3(LIST *pHead)
{
	LIST *p=pHead;
	while (p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

ListNode* MergeSortedList1(ListNode* phead1,ListNode* phead2)
{
	if (phead1==NULL || phead2==NULL)
		return NULL;

	ListNode* p1=phead1;
	ListNode* p2=phead2;
	 
	ListNode* cc=new ListNode;
	ListNode* tmp=cc;

	while (p1!=NULL && p2!=NULL)
	{		
		if (p1->data<p2->data)
		{
			 tmp=tmp->next=p1;
			 p1=p1->next;
		}
		else
		{
			tmp=tmp->next=p2;
			p2=p2->next;
		}

		if (p1)
			tmp->next=p1;
		else
			tmp->next=p2;
	}
	return cc;	
}

ListNode* MergeSortedList_iter(ListNode* pHead1,ListNode* pHead2)
{
	if (pHead1==NULL)
		return pHead2;
	else if (pHead2==NULL)
		return pHead1;

	ListNode* pMergeHead=NULL;

	if (pHead1->data<pHead2->data)
	{
		pMergeHead=pHead1;
		pMergeHead->next=MergeSortedList_iter(pHead1->next,pHead2);
	}
	else
	{
		pMergeHead=pHead2;
		pMergeHead->next=MergeSortedList_iter(pHead1,pHead2->next);
	}
	return pMergeHead;
}


void printList_reverse(ListNode* pHead)
{
	if (pHead->next!=NULL)
		printList_reverse(pHead->next);
	cout<<pHead->data<<" ";

}


//int main()
//{
//	char data1[]="4567";
//	int length1=strlen(data1);
//	pLIST phead1=NULL;	
//	for (int i=0;i<length1;i++)
//		createList3(&phead1,data1[i]);
//	printList3(phead1);
//	cout<<endl;
//	//逆序打印
//	printList_reverse(phead1);
//	cout<<endl;
//
//	char data2[]="12";
//	int length2=strlen(data2);
//	pLIST phead2=NULL;	
//	for (int i=0;i<length2;i++)
//		createList3(&phead2,data2[i]);
//	printList3(phead2);
//	cout<<endl;
//
//	/*ListNode*p=MergeSortedList1(phead1,phead2);
//	printList3(p->next);*/
//
//	ListNode*p=MergeSortedList_iter(phead1,phead2);
//	printList3(p);
//	cout<<endl;
//}
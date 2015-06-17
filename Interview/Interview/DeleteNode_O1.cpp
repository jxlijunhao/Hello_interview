/************************************************************************/
/* 在O（1）时间内删除一个非尾结点                                          */
/************************************************************************/

#include<iostream>
#include<cstdlib> 
using namespace std; 

//定义链表的结构体
typedef struct ListNode
{
	char data;
	struct ListNode *next;
}LIST,*pLIST;

//尾插法创建链表,不带空头节点的
void createList1(pLIST *head,char data)
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

void printList(LIST *pHead)
{
	LIST *p=pHead;
	while (p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

void DeleteNode_O1(LIST *pHead,LIST *p)
{
	//p不是尾结点
	if (p->next!=NULL)
	{
		p->data=p->next->data;
		LIST *tmp=p->next;
		p->next=p->next->next;
		free(tmp);
	}

}

//int main()
//{
//	char data[]="abcdefgh";
//	int length=strlen(data);
//
//	pLIST head=NULL;
//
//
//	for (int i=0;i<length;i++)
//		createList1(&head,data[i]);
//	printList(head);
//
//	LIST *p=head;
//	DeleteNode_O1(head,p) ;
//	cout<<endl;
//	printList(head);
//		
//
//	return 0;
//}
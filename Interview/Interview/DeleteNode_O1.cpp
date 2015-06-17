/************************************************************************/
/* ��O��1��ʱ����ɾ��һ����β���                                          */
/************************************************************************/

#include<iostream>
#include<cstdlib> 
using namespace std; 

//��������Ľṹ��
typedef struct ListNode
{
	char data;
	struct ListNode *next;
}LIST,*pLIST;

//β�巨��������,������ͷ�ڵ��
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
	//p����β���
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
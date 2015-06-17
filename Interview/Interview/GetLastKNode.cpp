/************************************************************************/
/* �ҵ������е�����k����                                                  */
/************************************************************************/

//����˼·�� ����ָ�룬һ��ָ������k-1����Ȼ��ͬ��һ��ָ��ͬʱ�ߣ������ߵĵ���β���
//          ʱ����һ��ָ������ļ��Ϊk-1����ô���������Ҫ�ҵ��ġ�
//Ҫע��ĵط���  1��Ҫȥ�ж�k�Ƿ��Ѿ������������ȣ�
//              2������k-1����for(int i=0;i<k-1;i++) ����k,�����ҵ����ǵ�����k+1��



#include<iostream>
using namespace std;

//��������Ľṹ��
typedef struct ListNode
{
	char data;
	struct ListNode *next;
}LIST,*pLIST;

//β�巨��������,������ͷ�ڵ��
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
		//����趨��k�Ƿ��Ѿ��������ܵ�������
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
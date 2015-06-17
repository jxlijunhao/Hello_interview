/************************************************************************/
/* 找出链表的第一个公共结点                                               */
/************************************************************************/
//解题思路1：利用栈，分别将两条链表入栈，然后出栈，当它们下一个出栈元素不一样时，当说明
//          当前元素是第一个公共结点。（浪费空间）


//解题思路2：分别遍历两链表，得到链表长度a,b,长链表先走abs(a-b)步，然后同时走，当它们的
//          指向的下一一个元素相同时，当说明找到了第一个公共结点


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
void createList2(pLIST *head,char data)
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

void printList2(LIST *pHead)
{
	LIST *p=pHead;
	while (p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

LIST* FirstCommonNode(LIST* phead1,LIST* phead2)
{
	if (phead1==NULL || phead2==NULL)
		return NULL;

	LIST* p1=phead1;
	LIST* p2=phead2;

	int len1=0,len2=0;
	int step=0;
	//分别遍历两条链表，得到链表的长度
	while (p1!=NULL)
	{
		len1++;
		p1=p1->next;
	}

	while (p2!=NULL)
	{
		len2++;
		p2=p2->next;
	}
	//长的链表要先长的步数
	step=len1>len2? (len1-len2):(len2-len1);
	p1=phead1;
	p2=phead2;

	if (len1>len2)
	{
		for (int i=0;i<step;++i)
			p1=p1->next;		
	}
	else
	{
		for (int i=0;i<step;++i)
			p2=p2->next;
	}

	while (p1->data!=p2->data)
	{
		p1=p1->next;
		p2=p2->next;
	}

	return p1;

}

//int main()
//{
//	char a[]="abcdefgh";
//	int len1=strlen(a);
//
//	char b[]="addefgh";
//	int len2=strlen(b);
//
//	pLIST head1=NULL;
//	pLIST head2=NULL;
//
//	for (int i=0;i<len1;i++)
//		createList2(&head1,a[i]);
//
//	for (int i=0;i<len2;i++)
//		createList2(&head2,b[i]);
//
//	printList2(head1);
//	cout<<endl;
//	printList2(head2);
//    cout<<endl;
//	LIST *common=FirstCommonNode(head1,head2);
//	if (common!=NULL)
//		cout<<common->data;
//	else
//		cout<<"NULL"<<endl;
//	return 0;
//
//
//}
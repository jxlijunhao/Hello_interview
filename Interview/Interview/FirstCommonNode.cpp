/************************************************************************/
/* �ҳ�����ĵ�һ���������                                               */
/************************************************************************/
//����˼·1������ջ���ֱ�����������ջ��Ȼ���ջ����������һ����ջԪ�ز�һ��ʱ����˵��
//          ��ǰԪ���ǵ�һ��������㡣���˷ѿռ䣩


//����˼·2���ֱ�����������õ�������a,b,����������abs(a-b)����Ȼ��ͬʱ�ߣ������ǵ�
//          ָ�����һһ��Ԫ����ͬʱ����˵���ҵ��˵�һ���������


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
	//�ֱ�������������õ�����ĳ���
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
	//��������Ҫ�ȳ��Ĳ���
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
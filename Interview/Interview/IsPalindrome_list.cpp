//�ж�һ�����������Ƿ�Ϊ�����ġ�

//����1�� ʹ�ÿ���ָ���ջ��Ҫע���ж������ȵ���ż��
//       ����ָ��ָ��NULLʱ������ǰ��ָ������ջ��ջ�����бȽ�

//����2�� ʹ�ÿ���ָ�룬����ָ��ΪNULLʱ����ת���������Ȼ������ת��ĸ�ǰ��ν��бȽ�

#include<iostream>
#include<cstdlib>
#include<stack>
#include<string.h>
using namespace std;

//��������Ľṹ��
typedef struct ListNode
{
	char data;
	struct ListNode *next;
}LIST,*pLIST;

//β�巨��������,����ͷ�ڵ��
//void createList(pLIST head,char data)
//{
//	LIST *p=head;
//	LIST *newNode;
//    while (p->next!=NULL)
//	{
//		p=p->next;
//	}
//
//	newNode=(LIST*)malloc(sizeof(LIST));
//	newNode->next=NULL;
//	newNode->data=data;
//	p->next=newNode;
//}

//bool IsPalindrome_list(pLIST head)
//{
//	LIST *slow=head->next;
//	LIST *fast=head->next;
//
//	bool flag=false; //�ж��Ƿ�Ϊ������true����ż������(false)
//	stack<char> s;
//
//	while (fast!=NULL)
//	{
//		s.push(slow->data);
//		slow=slow->next;
//		fast=fast->next;
//
//		//��ָ��������
//		if (fast!=NULL)
//			fast=fast->next;
//		else
//			flag=true;
//
//	}
//	//��������Ϊ����ʱ��Ҫ���м�λ�õĳ�ջ��
//	if (flag==true)
//		s.pop();
//
//	//��ʼ���� ��ָ����ջ��Ԫ�ؽ��бȽ�
//	while (slow!=NULL && !s.empty())
//	{
//		if (s.top()!=slow->data)
//		{
//			return false;
//		}
//		slow=slow->next;
//		s.pop();
//	}
//	return true;
//}


//β�巨��������,������ͷ�ڵ��
void createList(pLIST *head,char data)
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

LIST *ReversedList(pLIST pHead)
{
   LIST *pReversedHead=NULL;
   LIST *pNode=pHead;
   LIST *pPrev=NULL;

   while (pNode!=NULL)
   {
	   LIST *pNext=pNode->next;
	   if (pNext==NULL)
		   pReversedHead=pNode;

	   pNode->next=pPrev;
	   pPrev=pNode;
	   pNode=pNext;
   }
   return pReversedHead;
}


bool IsPalindrome_list(pLIST head)
{
	LIST *slow=head;
	LIST *fast=head;

	bool flag=false; //�ж��Ƿ�Ϊ������true����ż������(false)
	stack<char> s;

	while (fast!=NULL)
	{
		s.push(slow->data);
		slow=slow->next;
		fast=fast->next;

		//��ָ��������
		if (fast!=NULL)
			fast=fast->next;
		else
			flag=true;
		 
	}
	//��������Ϊ����ʱ��Ҫ���м�λ�õĳ�ջ��
	if (flag==true)
		s.pop();

	//��ʼ���� ��ָ����ջ��Ԫ�ؽ��бȽ�
	while (slow!=NULL && !s.empty())
	{
		if (s.top()!=slow->data)
		{
			return false;
		}
		slow=slow->next;
		s.pop();
	}
	return true;
}

bool IsPalindrome_list2(pLIST head)
{
	LIST *slow=head;
	LIST *fast=head;
	LIST *p=head;

	while (fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
		if (fast!=NULL)
			fast=fast->next;
	}

	LIST *pReversedHead=ReversedList(slow);

	while(pReversedHead!=NULL && p!=NULL)
	{
		if (pReversedHead->data!=p->data)
			return false;
		pReversedHead=pReversedHead->next;
		p=p->next;
	}
	
	return true;
}



//int main()
//{
//	char data[]="madama";
//	int length=strlen(data);
//
//	pLIST head=NULL;
//	
//	
//	for (int i=0;i<length;i++)
//		createList(&head,data[i]);
//	if (IsPalindrome_list2(head))
//		cout<<data<<" is palindrome"<<endl;
//	else
//		cout<<data<<" is not palindrome"<<endl;
//	return 0;
//}
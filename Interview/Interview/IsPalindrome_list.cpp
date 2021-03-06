//判断一个单向链表是否为“回文”

//方法1： 使用快慢指针和栈，要注意判断链表长度的奇偶性
//       当快指针指到NULL时，将当前慢指针与入栈的栈顶进行比较

//方法2： 使用快慢指针，当快指针为NULL时，逆转后半条链表，然后再逆转后的跟前半段进行比较

#include<iostream>
#include<cstdlib>
#include<stack>
#include<string.h>
using namespace std;

//定义链表的结构体
typedef struct ListNode
{
	char data;
	struct ListNode *next;
}LIST,*pLIST;

//尾插法创建链表,带空头节点的
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
//	bool flag=false; //判断是否为奇数（true）或偶数长度(false)
//	stack<char> s;
//
//	while (fast!=NULL)
//	{
//		s.push(slow->data);
//		slow=slow->next;
//		fast=fast->next;
//
//		//快指针走两步
//		if (fast!=NULL)
//			fast=fast->next;
//		else
//			flag=true;
//
//	}
//	//当链表长度为奇数时，要把中间位置的出栈顶
//	if (flag==true)
//		s.pop();
//
//	//开始利用 慢指针与栈顶元素进行比较
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


//尾插法创建链表,不带空头节点的
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

	bool flag=false; //判断是否为奇数（true）或偶数长度(false)
	stack<char> s;

	while (fast!=NULL)
	{
		s.push(slow->data);
		slow=slow->next;
		fast=fast->next;

		//快指针走两步
		if (fast!=NULL)
			fast=fast->next;
		else
			flag=true;
		 
	}
	//当链表长度为奇数时，要把中间位置的出栈顶
	if (flag==true)
		s.pop();

	//开始利用 慢指针与栈顶元素进行比较
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
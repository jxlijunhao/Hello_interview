#include<iostream>
#include<string.h>
using namespace std;

//��ֵ��p,qֻ��a,b�ĸ�����p,qȷʵ�ǽ����ˣ��������Ǿֲ�����������Ӱ�쵽�������е�a,b
//��swap1���н�����p,q ��ջ�б�ɾ��
void swap1(int p,int q)
{
	int temp;
	temp=p;
	p=q;
	q=temp;
}

//�������ͨ�������������Ǳ���ԭ���� tmpʹ��ǰδ��ʼ��
void swap2(int *p,int *q)
{
	int *tmp=NULL; 
	*tmp=*p;//����ģ������߼���tmpδ����ʼ��
	*p=*q;
	*q=*tmp;
}

//���ܽ�����������ԭ���� p,q���ս�����ֻ��ʹ�� pָ����b,qָ����a,��δʹ��a,b��ֵ�����仯
//              ����������p,q��ʧ
void swap3(int *p,int *q)
{
	int *tmp;
	tmp=p;
	p=q;
	q=tmp;
}

//��ȷ��д��
void swap4(int *p,int *q)
{
	int tmp;
	tmp=*p;
	*p=*q;
	*q=tmp;
}

void swap5(int &p,int &q)
{
	int tmp;
	tmp=p;
	p=q;
	q=tmp;
}

char *getMemory(char *p,int num)
{
	p=(char*)malloc(sizeof(char)*num);
	return p;
}




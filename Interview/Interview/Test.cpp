#include<iostream>
#include<string.h>
using namespace std;

//传值，p,q只是a,b的副本，p,q确实是交换了，但它们是局部变量，不会影响到主函数中的a,b
//当swap1运行结束后，p,q 在栈中被删除
void swap1(int p,int q)
{
	int temp;
	temp=p;
	p=q;
	q=temp;
}

//编译可以通过，但是运行是报错，原因是 tmp使用前未初始化
void swap2(int *p,int *q)
{
	int *tmp=NULL; 
	*tmp=*p;//错误的，不合逻辑，tmp未被初始化
	*p=*q;
	*q=*tmp;
}

//不能交换！！！，原因是 p,q最终交换后，只是使得 p指向了b,q指向了a,并未使得a,b的值发生变化
//              函数结束后，p,q消失
void swap3(int *p,int *q)
{
	int *tmp;
	tmp=p;
	p=q;
	q=tmp;
}

//正确的写法
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




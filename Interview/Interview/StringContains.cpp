/************************************************************************/
/* 给定两个分别由字母组成的字符串A和字符串B，字符串B的长度比字符串A短。
  请问，如何最快地判断字符串B中所有字母是否都在字符串A里？                                                            */
/************************************************************************/

#include<iostream>
#include<string>
using namespace std;

bool StringContains(const string &a,const string &b)
{
	int myHash=0;
	//为字符串 a 生成一个数字签名
	for (int i=0;i<a.length();i++)
	{
		myHash |=(1<<(a[i]-'A'));
	}

	for (int i=0;i<b.length();i++)
	{
		if (myHash &(1<<(b[i]-'A'))==0)
		{
			return false;
		}
	}
	return true;
}



//int main()
//{
//	string a="ABCD";
//	string b="BCD";
//	if (StringContains(a,b))
//		cout<<"a contains b"<<endl;
//	else
//		cout<<"a doesn't contain b"<<endl;
//	return 0;
//}

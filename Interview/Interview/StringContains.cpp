/************************************************************************/
/* ���������ֱ�����ĸ��ɵ��ַ���A���ַ���B���ַ���B�ĳ��ȱ��ַ���A�̡�
  ���ʣ���������ж��ַ���B��������ĸ�Ƿ����ַ���A�                                                            */
/************************************************************************/

#include<iostream>
#include<string>
using namespace std;

bool StringContains(const string &a,const string &b)
{
	int myHash=0;
	//Ϊ�ַ��� a ����һ������ǩ��
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

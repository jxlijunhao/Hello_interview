#include<iostream>
#include<string>
using namespace std;

char FirstAppearChar(const string &str)
{
	if (str==" ")
		return NULL;
	//��ʼ��һ��hashtable
	int len=str.length();
	int hashtable[255]={0};

	//ͳ�Ƹ���ĸ���ֵĴ���
	for (int i=0;i<len;++i)
		hashtable[str.at(i)-'a']++;

	for (int i=0;i<len;++i){
		if (hashtable[str.at(i)-'a']==1)
			return str.at(i);
	}
	return NULL;
}

//int main()
//{
//	string str="aaba";
//	cout<<FirstAppearChar(str)<<endl;
//	return 0;
//}
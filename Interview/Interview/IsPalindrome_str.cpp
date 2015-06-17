//����1�� ���������м����
//����2�� ���м����������

#include<iostream>
using namespace std;

bool IsPalindrome(char *s,int n)
{
	if (s==NULL || n<1)
		return false;
	char *ptrFront=s;
	char *ptrBack=s+n-1;

	while (ptrFront<ptrBack)
	{
		if (*ptrFront!=*ptrBack)
			return false;
		ptrFront++;
		ptrBack--;	
	}
	return true;
}

bool IsPalindrome2( char *s, int n)
{
	if (s == NULL || n < 1) 
		return false; // �Ƿ�����  
	char *first, *second;

	int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0; // m is themiddle point of s      
	first = s + m; 
	second = s + n - 1 - m;

	while (first >= s)
		if (*first-- != *second++) 
			return false; // not equal, so it's not apalindrome  
	return true; // check over, it's a palindrome  
}

//int main()
//{
//	char s[]="abccba";
//	if (IsPalindrome2(s,6))
//		cout<<s<<" is palindrome"<<endl;
//	else
//		cout<<s<<" is not palindrome"<<endl;
//	return 0;
//}
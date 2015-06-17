/************************************************************************/
/*    字符个数的统计                                                      */
/************************************************************************/

#include<iostream>
using namespace std;

int* CountChars(char* pSource)
{
	if (pSource==NULL)
		return 0;
	
	int hashTable[256]={0};
	char* pChar=pSource;
	while ('\0'!=*pChar)
	{
		hashTable[*pChar]++;
		pChar++;
	}
	return hashTable;
}

//int main()
//{
//	char str[]="aabbcdef";
//	int *count=CountChars(str);
//	 
//	cout<<str[1]<<" "<<count[str[1]]<<endl;
//	return 0;
//}


/************************************************************************/
/* ���ַ�����ɾ���ض����ַ�

   ���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.����
*/
/************************************************************************/

//����˼·��������hash��Ҫɾ�����ַ�ӳ�䵽hash���У�������ҡ�Ȼ����������ָ�룬
//         pSearch,pReturn,һ���������ҵ�ǰ�ַ��ǲ���Ҫ��ɾ���ģ�һ���������ص�
//         ��ô��ɾ������pSearchָ�����ַ���Ҫ��ɾ���ģ���ô����ֵ����pReturn,���򶼸���һ��

#include<iostream> 
using namespace std;

void DeleteChars(char* pSource, char* pDelete)
{
	if (pSource==NULL || pDelete==NULL)
		return;

	 
	int hashTable[256]={0};

	//ΪpDelete�ַ�������һ��hash��
	char* pchar=pDelete;
	while('\0'!=*pchar)
	{
		hashTable[*pchar]++;
		pchar++;
	}

	//��ʼ����pSearch���в���
	char* pSearch=pSource;
	char* pReturn=pSource;
	while ('\0'!=*pSearch)
	{
		if (hashTable[*pSearch]==0)//��ǰ�ַ�����Ҫ��ɾ��
		{			
			*pReturn=*pSearch;
			pReturn++;
		}
		pSearch++;		 
	}
	*pReturn='\0';
	
}

//int main()
//{
//	char pSource[]="They are students.";
//	char pDelete[]="aeiou";
//	DeleteChars(pSource,pDelete);
//	cout<<pSource<<endl;
//	return 0;
//}

 
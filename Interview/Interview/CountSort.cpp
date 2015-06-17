/************************************************************************/
/* ��������                                                             */
/************************************************************************/
//����˼·����֪����Ҫ���������A�ķ�Χ��[0,max]������һ����СΪmax������Counts��Ȼ���Ҫ���������A
//         ����ɨ�裬���ֵĴ�������Counts�У�

#include<stdio.h>
#include<stdlib.h>
void CountsSort(int *array,int Len,int maxNumber)
{
	if (array==NULL || Len<1)
		return;

	int *Counts=(int*) malloc(sizeof(int)*(maxNumber));
	for (int i=0;i<maxNumber;i++)
		Counts[i]=0;

	//ͳ�Ƹ������ֳ��ֵĴ���
	for (int i=0;i<Len;i++)
	{
		Counts[array[i]]++;
	}

	//�ҵ�array��������Ҫ��ŵ�λ��,�����֮ǰҪ���ٸ�������
	for (int i=1;i<maxNumber;i++)
		Counts[i]+=Counts[i-1];

	int *result=(int*)malloc(sizeof(int)*Len);

	for (int i=Len-1;i>=0;i--)
	{		
		result[Counts[array[i]]-1]=array[i];
		Counts[array[i]]--;
	}
	//��result���Ƶ�ԭ����������
	for (int i=0;i<Len;i++)
		array[i]=result[i];

	free(Counts);
	free(result);
}

void CountsSort_new(int *array,int Len,int maxNumber)
{
	if (array==NULL || Len<1)
		return;

	int *Counts=(int*) malloc(sizeof(int)*(maxNumber));
	for (int i=0;i<maxNumber;i++)
		Counts[i]=0;

	//ͳ�Ƹ������ֳ��ֵĴ���
	for (int i=0;i<Len;i++)
	{
		Counts[array[i]]++;
	}
	int z=0;

	for (int i=0;i<maxNumber;i++)
	{
		while(Counts[i]>0)
		{
			array[z++]=i;
			Counts[i]--;
		}
	} 
	free(Counts);
 
}




//int main()
//{
//	 int a[] = {2,2,1,1,7,7,8,7};
//	 CountsSort(a,sizeof(a)/sizeof(a[0]),9);
//	 CountsSort_new(a,sizeof(a)/sizeof(a[0]),9);
//	 for (int i=0;i<sizeof(a)/sizeof(a[0]);i++)
//		 printf("%d ",a[i]);
//	 printf("\n");
//	 return 0;
//}
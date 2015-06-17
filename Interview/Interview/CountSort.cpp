/************************************************************************/
/* 计数排序                                                             */
/************************************************************************/
//基本思路：在知道了要排序的数组A的范围后[0,max]，开辟一个大小为max的数组Counts，然后对要排序的数组A
//         进行扫描，出现的次数放在Counts中，

#include<stdio.h>
#include<stdlib.h>
void CountsSort(int *array,int Len,int maxNumber)
{
	if (array==NULL || Len<1)
		return;

	int *Counts=(int*) malloc(sizeof(int)*(maxNumber));
	for (int i=0;i<maxNumber;i++)
		Counts[i]=0;

	//统计各个数字出现的次数
	for (int i=0;i<Len;i++)
	{
		Counts[array[i]]++;
	}

	//找到array中数字其要存放的位置,这个数之前要多少个不大于
	for (int i=1;i<maxNumber;i++)
		Counts[i]+=Counts[i-1];

	int *result=(int*)malloc(sizeof(int)*Len);

	for (int i=Len-1;i>=0;i--)
	{		
		result[Counts[array[i]]-1]=array[i];
		Counts[array[i]]--;
	}
	//将result复制到原来的数组中
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

	//统计各个数字出现的次数
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
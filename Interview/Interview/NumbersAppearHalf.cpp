/************************************************************************/
/* 找出数组中次数超过总数一半的数                                           */
/************************************************************************/

#include<stdio.h>

int myPartition(int *array,int low,int high)
{
	int pivotData = array[low];
	int littleInd = low;
	int highInd = high;

	while ( littleInd < highInd )
	{
		while (littleInd<highInd && array[highInd]>=pivotData)
		{
			--highInd;
		}
		if (littleInd <highInd )
		{
			array[littleInd++] = array[highInd];
		}

		while (littleInd < highInd && pivotData >=array[littleInd])
		{
			++littleInd;
		}

		if (littleInd <highInd )
		{
			array[highInd--] = array[littleInd];
		}
	}
	array[highInd] = pivotData;
	return highInd;
}


int FindMoreThanHalf(int *array,int len)
{
	if ( array==NULL && len<1)
		return NULL;

	int middle=len>>1;

	int k=myPartition(array,0,len-1);
	
	while (k!=middle)
	{
		if (k<middle)
		{
			k=myPartition(array,k+1,len-1);
		}
		else
		{
			k=myPartition(array,0,k-1);
		}
	}
	return array[k];
}

//int main()
//{
//	int array[]={1,2,3,2,2,2,5,4,2};
//	printf("%d\n",FindMoreThanHalf(array,sizeof(array)/sizeof(array[0])));
//	return 0;
//
//}

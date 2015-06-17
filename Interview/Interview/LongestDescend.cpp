/************************************************************************/
/* 给定一个数组，求这个数组的最后递减子序列                                 */
/************************************************************************/

#include<stdio.h>


void printIt(int *array,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",array[i]);
	printf("\n");
}

void LongestDesend(int *array,int len,int &start,int &end)
{
	if (array==NULL || len<1)
		return;

	int low=0;
	int high=0;
	int LEN=0;

	while (high<len)
	{
		if (array[high+1]<array[high])
		{
			high++;
		}
		else
		{
			printIt(array,low,high);

			if (LEN<(high-low+1))
			{
				LEN=(high-low+1);
				start=low;
				end=high;
			}
			high++;
			low=high;
		}
	}
}

//int main()
//{
//	int a[]={9,4,3,2,5,4,3,2,1,0,0,0,0};
//	int start,end;
//	LongestDesend(a,sizeof(a)/sizeof(a[0]),start,end);
//	printf("start:%d\nend:%d\n",start,end);
//	return 0;
//}

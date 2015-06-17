#include<iostream>
using namespace std;

/*
此方法主要获得计算代价，以及括号化方案的划分点
为此问题解决的核心方法。
num存储的矩阵的下标，num[i-1]为第i个矩阵的行数，num[i]表示第i个矩阵的列数
因为数组存储时，最初始的下标为0，所以下述的定义就变的有点不好理解！仔细想想也容易明白。
cost----二维数组，cost[i][j]代表的就是第（i+1）个矩阵到第（j+1）个矩阵的链乘的最小计算代价
point----二维数组，point[i][j]代表的就是第（i+1）个矩阵到第（j+1）个矩阵的链乘的最佳划分处，假如为k，则k就是第k+1个矩阵，
（i+1）到(k+1)矩阵属于左边的完全括号化矩阵，其余为右侧完全括号化矩阵
length代表的是矩阵的个数，即num的长度-1
*/

const int max_size = 2147483647;
const int SIZE = 6; 

void matrix_divide_option(int *num,int cost[][SIZE],int point[][SIZE],int length)
{
    //首先将代价表中的值重置
    //下标i到下标j之间的矩阵链乘的最小值
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            if(i>=j)
            {
                cost[i][j] = 0;                 //单个矩阵不存在乘积，代价0，同时也将不合理的下标组合置为0
            }
            else
            {
                cost[i][j] = max_size;          //先将各合理的组合代价设为最大，以便后续比较使用。
            }
            point[i][j] = -1;                   //将所有组合的划分点置为-1，以便后续记录。
        }
    }
/*
    l代表矩阵链中矩阵的个数，我们这里从2个矩阵起步.由公式可知，我们要算遍所有的合理组合，同时大区间的组合
    还要依赖于其子区间的合理组合，因为完全括号化的性质，最终都归根于2个矩阵的乘积，所以我们从2个矩阵起步，
    逐步向上计算，最终就能计算（0，n）的组合的最优括号化的代价。
*/
    for(int l=2;l<=length;l++)
    {
        for(int i=0;i<=length-l;i++)            //此处要注意的i+l-1不能超过数组的个数
        {
            int j = i+l-1;                      //矩阵个数要为l，则j-i需满足j-i+1=l，所以有该等式
            int q = 0;
            for(int k=i;k<j;k++)                //注意k要在区间内移动，利用下述if条件，获得所有可能值中的最小值，
            {
                q = cost[i][k] + cost[k+1][j] + num[i]*num[k+1]*num[j+1];
                if(q < cost[i][j])
                {
                    cost[i][j] = q;
                    point[i][j] = k;
                }
            }
        }
    }

}

void show(int p[][SIZE] )
{
    using namespace std;
    for(int i=0;i<SIZE-1;i++)
    {
        for(int j=0;j<SIZE-1;j++)
        {
            cout << p[i][j] << '\t';
        }
        cout << endl;
    }
}

void print(int point[][SIZE],int i,int j)
{
	if(i == j)
	{
		std::cout << "A" << i+1;
	}
	else
	{
		std::cout << "(";
		print(point,i,point[i][j]);             //输出划分点左侧的完全括号化表达式
		print(point,point[i][j]+1,j);            //输出划分点右侧的完全括号化表达式
		std::cout << ")";
	}
}


//int main()
//{
//	int num[7] ={30,35,15,5,10,20,25};
//	int cost[SIZE][SIZE]  = {0};
//	int point[SIZE][SIZE] = {0};
//	matrix_divide_option(num,cost,point,SIZE);
//	cout << "各区间的计算代价：" << endl;
//	show(cost);
//	cout << endl;
//	cout << "区间划分点所在的位置：" << endl;
//	show(point);
//	cout << endl;
//	cout << "输出完全括号化方案：" << endl;
//	print(point,0,SIZE-2);
//	cout << endl << endl;
//
//
//	return 0;
//
//}
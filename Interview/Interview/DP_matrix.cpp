#include<iostream>
using namespace std;

/*
�˷�����Ҫ��ü�����ۣ��Լ����Ż������Ļ��ֵ�
Ϊ���������ĺ��ķ�����
num�洢�ľ�����±꣬num[i-1]Ϊ��i�������������num[i]��ʾ��i�����������
��Ϊ����洢ʱ�����ʼ���±�Ϊ0�����������Ķ���ͱ���е㲻����⣡��ϸ����Ҳ�������ס�
cost----��ά���飬cost[i][j]����ľ��ǵڣ�i+1�������󵽵ڣ�j+1������������˵���С�������
point----��ά���飬point[i][j]����ľ��ǵڣ�i+1�������󵽵ڣ�j+1������������˵���ѻ��ִ�������Ϊk����k���ǵ�k+1������
��i+1����(k+1)����������ߵ���ȫ���Ż���������Ϊ�Ҳ���ȫ���Ż�����
length������Ǿ���ĸ�������num�ĳ���-1
*/

const int max_size = 2147483647;
const int SIZE = 6; 

void matrix_divide_option(int *num,int cost[][SIZE],int point[][SIZE],int length)
{
    //���Ƚ����۱��е�ֵ����
    //�±�i���±�j֮��ľ������˵���Сֵ
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            if(i>=j)
            {
                cost[i][j] = 0;                 //�������󲻴��ڳ˻�������0��ͬʱҲ����������±������Ϊ0
            }
            else
            {
                cost[i][j] = max_size;          //�Ƚ����������ϴ�����Ϊ����Ա�����Ƚ�ʹ�á�
            }
            point[i][j] = -1;                   //��������ϵĻ��ֵ���Ϊ-1���Ա������¼��
        }
    }
/*
    l����������о���ĸ��������������2��������.�ɹ�ʽ��֪������Ҫ������еĺ�����ϣ�ͬʱ����������
    ��Ҫ��������������ĺ�����ϣ���Ϊ��ȫ���Ż������ʣ����ն������2������ĳ˻����������Ǵ�2�������𲽣�
    �����ϼ��㣬���վ��ܼ��㣨0��n������ϵ��������Ż��Ĵ��ۡ�
*/
    for(int l=2;l<=length;l++)
    {
        for(int i=0;i<=length-l;i++)            //�˴�Ҫע���i+l-1���ܳ�������ĸ���
        {
            int j = i+l-1;                      //�������ҪΪl����j-i������j-i+1=l�������иõ�ʽ
            int q = 0;
            for(int k=i;k<j;k++)                //ע��kҪ���������ƶ�����������if������������п���ֵ�е���Сֵ��
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
		print(point,i,point[i][j]);             //������ֵ�������ȫ���Ż����ʽ
		print(point,point[i][j]+1,j);            //������ֵ��Ҳ����ȫ���Ż����ʽ
		std::cout << ")";
	}
}


//int main()
//{
//	int num[7] ={30,35,15,5,10,20,25};
//	int cost[SIZE][SIZE]  = {0};
//	int point[SIZE][SIZE] = {0};
//	matrix_divide_option(num,cost,point,SIZE);
//	cout << "������ļ�����ۣ�" << endl;
//	show(cost);
//	cout << endl;
//	cout << "���仮�ֵ����ڵ�λ�ã�" << endl;
//	show(point);
//	cout << endl;
//	cout << "�����ȫ���Ż�������" << endl;
//	print(point,0,SIZE-2);
//	cout << endl << endl;
//
//
//	return 0;
//
//}
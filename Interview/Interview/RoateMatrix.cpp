/************************************************************************/
/* ��ӡ��������                                                          */
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// static�Ϳ����ˣ�����ʱʹ��-O2�Ϳ�������չ����
static int calculate(int n, int i, int j);

//int main()
//{
//	int n, i, j;
//
//    n=6;
//
//	for (i = 0; i < n; ++i) {
//		for (j = 0; j < n; ++j) {
//			printf("%2d ", calculate(n - 1, i, j));
//		}
//		printf("\n");
//	}
//
//	return 0 ;
//}

// calculate��������߳�Ϊn+1�ľ���(i, j)λ���ϵ���ֵ
static int calculate(int n, int i, int j)
{
	// (i, j)λ�õ���ֵ
	int k = 0;
	// ��������(i, j)�����м��������ġ�Ȧ��
	int mini = i < n - i ? i : n - i;
	int minj = j < n - j ? j : n - j;
	int min = mini < minj ? mini : minj;
	int h;

	// h�������Ʋ���
	for (h = 0; h < min; ++h) {
		// �ڲ��ȦҪ���ٽ�����Ȧ�ı߳�С2
		k += (n - 2 * h) * 4;
	}

	// (i, j)λ��ͬ����Ϸ�
	if (i == min) {
		// ֱ��ȡ��j�����λ�ã�ע����Ҫ����min����Ϊ��Χ�Ѿ��������
		k += j - min + 1;
	}
	// (i, j)λ��ͬ����Ҳ�
	else if (j == n - min) {
		// ��Ҫ�����Ϸ��߳��ĳ���
		k += (n - 2 * min) + (i - min) + 1;
	}
	// (i, j)λ��ͬ����·�
	else if (i == n - min) {
		// ��Ҫ�����Ϸ����Ҳ�ĳ���
		k += (n - 2 * min) * 2 + (n - min - j) + 1;
	}
	// (i, j)λ��ͬ������
	else if (j == min) {
		// ��Ҫ�����Ϸ����Ҳ���·��ĳ���
		k += (n - 2 * min) * 3 + (n - min - i) + 1;
	}

	return k;
}
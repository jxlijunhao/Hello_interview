/**0-1 knapsack d(i, j)��ʾǰi����Ʒװ��ʣ������Ϊj�ı����е��������**/
#include<cstdio>
using namespace std;
#define MAXN 1000
#define MAXC 100000

int V[MAXN], W[MAXN];
int d[MAXN][MAXC];

//int main(){
//	freopen("data.in", "r", stdin);//�ض���������
//	freopen("data.out", "w", stdout);//�ض��������
//	int n, C;
//	while(scanf("%d %d", &n, &C) != EOF){
//		for(int i=0; i<n; ++i)   scanf("%d %d", &V[i], &W[i]);
//
//		for(int i=0; i<=n; ++i){
//			for(int j=0; j<=C; ++j){
//				d[i][j] = i==0 ? 0 : d[i-1][j];
//				if(i>0 && j>=V[i-1])  d[i][j] >?= d[i-1][j-V[i-1]]+W[i-1];
//			}
//		}
//		printf("%d\n", d[n][C]);//������������ֵ
//	}
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//}
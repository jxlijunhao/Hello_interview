#include<iostream>
using namespace std;

long long ClimbStairs(int n)
{
	int dp[3] = { 1, 1 };
	if (n < 2)
	{
		return 1;
	}
	for (int i = 2; i <= n; i++)
	{
		dp[2] = dp[0] + dp[1];
		dp[0] = dp[1];
		dp[1] = dp[2];
	}
	return dp[2];
}

//int main()
//{
//	long long len=ClimbStairs(50);
//	cout<<len<<endl;
//	return 0;
//}
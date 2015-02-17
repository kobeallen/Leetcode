#include<cstdio>
using namespace std;

int main(int argc, char *argv[])
{
	int press;
	while(scanf("%d", &press) != EOF)
	{
		long long dp[press+1];
		for(int i = 0; i <= press; ++i)
			dp[i] = i;
		for(int i = 1; i <= press; ++i)
		{
			for(int j = 1; j < 5 && i + j + 2 <= press; ++j)
			//for(int j = 1; i + j + 2 <= press; ++j)
			{
				if(dp[i+j+2] < dp[i] * (j + 1))
					dp[i+j+2] = dp[i] * (j + 1);
			}
		}
		printf("%lld\n", dp[press]);
	}
	return 0;
}

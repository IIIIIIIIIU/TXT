#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005;

int n,sum[maxn],dp[maxn],ans;

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	int T;
	read(T);
	while(T--)
	{
		read(n);
		read(dp[1]),sum[1]=dp[1];
		for(int i=2;i<=n;i++)
		{
			read(dp[i]);
			dp[i]+=sum[i-2];
			sum[i]=std::max(sum[i-1],dp[i]);
		}
		std::cout<<std::max(dp[n],dp[n-1])<<std::endl;
	}
	return 0;
}

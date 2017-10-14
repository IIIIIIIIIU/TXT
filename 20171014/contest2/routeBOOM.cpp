#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int mod=12345;

int n,dp[1005][1005];

inline void add(int &x,int y)
{
	if((x+=y)>=mod) x-=mod;
}

int main()
{
	freopen("T2DATAfromBOOM.txt","w",stdout);
	dp[0][0]=1;
	for(int i=1;i<=1000;i++)
		for(int j=0;j<=(i/2);j++)
		{
			for(int v=0;v<i;v++)
				if(i-v==1)
					add(dp[i][j],dp[v][j]);
				else if(i-v==2&&j)
					add(dp[i][j],dp[v][j-1]);
				else
				{
					for(int e=0;e<j;e++)
						add(dp[i][j],(dp[v][j-e-1]*dp[i-v-2][e])%mod);
				}
		}
	int ans=0;
	for(int n=1;n<=1000;n++)
	{
		ans=0;
		for(int i=0;i<=n/2;i++)
			add(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}

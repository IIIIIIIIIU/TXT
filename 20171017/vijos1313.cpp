#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=305,maxm=32005;

int n,m,vi[maxn],val[maxn],tot,pi[maxn];
int sta[maxn][maxn],num[maxn],qi[maxn],dp[maxm];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(m),read(n);
	for(int i=1;i<=n;i++)
	{
		read(vi[i]),read(pi[i]),read(qi[i]);
		if(qi[i])
			sta[qi[i]][++num[qi[i]]]=i;
	}
	for(int i=1;i<=n;i++)
		if(qi[i])
			continue;
		else
		{
			for(int v=m;v>=vi[i];v--)
			{
				dp[v]=std::max(dp[v],dp[v-vi[i]]+vi[i]*pi[i]);
				if(num[i]>0)
				{
					int V=vi[i]+vi[sta[i][1]],C=vi[i]*pi[i]+vi[sta[i][1]]*pi[sta[i][1]];
					if(v>=V) dp[v]=std::max(dp[v],dp[v-V]+C);
				}
				if(num[i]>1)
				{
					int V=vi[i]+vi[sta[i][2]],C=vi[i]*pi[i]+vi[sta[i][2]]*pi[sta[i][2]];
					if(v>=V) dp[v]=std::max(dp[v],dp[v-V]+C);
					V+=vi[sta[i][1]],C+=vi[sta[i][1]]*pi[sta[i][1]];
					if(v>=V) dp[v]=std::max(dp[v],dp[v-V]+C);
				}
			}
		}
	std::cout<<dp[m];
	return 0;
}

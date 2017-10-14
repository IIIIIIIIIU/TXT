#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1000005;

struct node
{
	int ti,ci;

	bool operator<(const node &tmp)const
	{
		return ti<tmp.ti;
	}
};

struct node ai[maxn];

int n,dp[maxn],ans;

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	freopen("T2data.txt","r",stdin);
	freopen("T2out2.txt","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		read(ai[i].ti),read(ai[i].ci);
	std::sort(ai+1,ai+n+1);
	memset(dp,-0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)
		for(int v=ai[i].ti;v>=ai[i].ci;v--)
		{
			dp[v]=std::max(dp[v],dp[v-ai[i].ci]+1);
			ans=std::max(ans,dp[v]);
		}
	std::cout<<ans;
	return 0;
}

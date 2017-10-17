#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1000005;

int n,ai[101],val[maxn],s,t,m,ed,dp[maxn];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n),read(s),read(t),read(n);
	for(int i=1;i<=n;i++)
		read(ai[i]);
	std::sort(ai+1,ai+n+1);
	if(s==t)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=!(ai[i]%s);
		std::cout<<ans;
		return 0;
	}
	for(int i=n;i>=1;i--)
		ai[i]=std::min(100,ai[i]-ai[i-1]);
	for(int i=1;i<=n;i++) ai[i]+=ai[i-1];
	ed=ai[n]+1;
	for(int i=1;i<=n;i++)
		val[ai[i]]++;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=ed;i++)
		for(int v=s;v<=t&&i-v>=0;v++)
			dp[i]=std::min(dp[i],dp[i-v]+val[i]);
	std::cout<<dp[ed];
	return 0;
}

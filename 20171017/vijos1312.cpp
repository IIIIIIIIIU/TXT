#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=205;

int p1[maxn],p2[maxn],n,dp[maxn][maxn];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(p1[i]);
	for(int i=1;i<=n;i++)
		p1[i+n]=p1[i];
	for(int i=1;i<(n<<1);i++)
		p2[i]=p1[i+1];
	p2[n<<1]=p1[1];
	for(int step=2;step<=n;step++)
		for(int l=1,r;(r=l+step-1)<=(n<<1);l++)
			for(int e=l;e<r;e++)
				dp[l][r]=std::max(dp[l][r],dp[l][e]+dp[e+1][r]+p1[l]*p2[e]*p2[r]);
	int ans=0;
	for(int i=1;i+n-1<=(n<<1);i++)
		ans=std::max(ans,dp[i][i+n-1]);
	std::cout<<ans;
	return 0;
}

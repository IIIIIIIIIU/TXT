#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef double real;

const real INF=5e8;
const int maxn=1e3+5;

struct node
{
	real x,y;
	
	real operator|(const node&tmp)const
	{
		real tmpx=tmp.x-x,tmpy=tmp.y-y;
		return std::sqrt((tmpx*tmpx)+(tmpy*tmpy));
	}
};

struct node ai[maxn];

int n,b1,b2;

real dp[maxn][maxn],dis[maxn][maxn];

int main()
{
	freopen("data.txt","r",stdin);
	freopen("ans1.txt","w",stdout);
	scanf("%d%d%d",&n,&b1,&b2);
	b1++;
	b2++;
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&ai[i].x,&ai[i].y);
	for(int i=1;i<=n;i++)
		for(int v=1;v<=n;v++)
			dis[i][v]=(ai[i]|ai[v]);
	for(short i=0,v;i<=n;i++)
		for(v=0;v<=n;v++)
			dp[i][v]=INF;
	dp[1][1]=0;
	for(short i=2,v;i<=n;i++)
	{
		if(i!=b2)
		{
			for(v=1;v<i;v++)
				dp[i][i-1]=std::min(dp[i][i-1],dp[v][i-1]+dis[v][i]);
			for(v=1;v<i;v++)
				dp[i][v]=std::min(dp[i][v],dp[i-1][v]+dis[i-1][i]);
		}
		if(i!=b1)
		{
			for(v=1;v<i;v++)
				dp[i-1][i]=std::min(dp[i-1][i],dp[i-1][v]+dis[v][i]);
			for(v=1;v<i;v++)
				dp[v][i]=std::min(dp[v][i],dp[v][i-1]+dis[i-1][i]);
		}
	}
	real ans=INF;
	for(int i=1;i<n;i++)
	{
		ans=std::min(ans,dp[i][n]+dis[i][n]);
		ans=std::min(ans,dp[n][i]+dis[i][n]);
	}
	printf("%.2lf\n",ans);
	return 0;
}

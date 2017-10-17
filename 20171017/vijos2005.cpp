#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef double real;

const int maxn=2005,maxv=305,INF=0x3f3f3f3f;

int n,m,nc,mc,ci[maxn][2],map[maxv][maxv];

real pi[maxn][2],dp[maxn][maxn][2],ans=INF;

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n),read(m),read(nc),read(mc);
	for(int i=1;i<=n;i++)
		read(ci[i][0]);
	for(int i=1;i<=n;i++)
		read(ci[i][1]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&pi[i][1]);
		pi[i][0]=1-pi[i][1];
	}
	for(int i=1;i<=nc;i++)
		for(int v=1;v<=nc;v++)
			if(i==v)
				continue;
			else
				map[i][v]=INF;
	for(int i=1,u,v,w;i<=mc;i++)
	{
		read(u),read(v),read(w);
		map[u][v]=map[v][u]=std::min(map[v][u],w);
	}
	for(int k=1;k<=nc;k++)
		for(int i=1;i<=nc;i++)
			for(int v=1;v<=nc;v++)
				map[i][v]=std::min(map[i][v],map[i][k]+map[k][v]);
	for(int i=1;i<=n;i++)
		for(int v=0;v<=m;v++)
			dp[i][v][0]=dp[i][v][1]=INF;
	dp[1][0][0]=dp[1][1][1]=0;
	int pc0,pc1,nc0,nc1;
	real val01,val00,val11,val10,pp0,pp1,np0,np1;
	for(int i=2;i<=n;i++)
		for(int v=0;v<=m;v++)
		{
			nc0=ci[i][0],nc1=ci[i][1];
			np0=pi[i][0],np1=pi[i][1];
			pc0=ci[i-1][0],pc1=ci[i-1][1];
			pp0=pi[i-1][0],pp1=pi[i-1][1];
			val01=val00=val11=val10=INF;
			val00=dp[i-1][v][0]+map[pc0][nc0];
			val10=dp[i-1][v][1]+map[pc0][nc0]*pp0+map[pc1][nc0]*pp1;
			dp[i][v][0]=std::min(val00,val10);
			if(v)
			{
				val01=dp[i-1][v-1][0]+map[pc0][nc0]*np0+map[pc0][nc1]*np1;
				val11=dp[i-1][v-1][1]+map[pc0][nc0]*pp0*np0+map[pc0][nc1]*pp0*np1
						+map[pc1][nc0]*pp1*np0+map[pc1][nc1]*pp1*np1;
				dp[i][v][1]=std::min(val01,val11);
			}
		}
	for(int i=0;i<=m;i++)
		ans=std::min(ans,std::min(dp[n][i][0],dp[n][i][1]));
	printf("%.2lf\n",ans);
	return 0;
}

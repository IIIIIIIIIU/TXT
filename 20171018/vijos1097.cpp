#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=10005,maxm=1005,INF=1e8;

int n,m,k,X[maxn],Y[maxn],L[maxn],R[maxn],dp[2][maxm];
int num[maxm],val[maxm],sum[maxn];

inline void read(int &now)
{
	char Cget;
	now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
}

int main()
{
	read(n);
	read(m);
	read(k);
	for(int i=0;i<n;i++)
	{
		read(X[i]);
		read(Y[i]);
		L[i]=1;
		R[i]=m;
	}
	L[n]=1,R[n]=m;
	for(int i=1,p;i<=k;i++)
	{
		read(p);
		sum[p]++;
		read(L[p]);
		L[p]++;
		read(R[p]);
		R[p]--;
	}
	int now=1,last=0;
	for(int i=1,tmp;i<=n;i++)
	{
		sum[i]+=sum[i-1];
		memset(num,0,sizeof(num));
		memset(dp[now],0x3f,sizeof(dp[now]));
		bool can=true;
		int x=X[i-1],y=Y[i-1];
		for(int e=1;e<=x;e++)
			num[e]=1,val[e%x]=dp[last][e]-1;
		for(int e=x+1;e<=R[i];e++)
			num[e]=num[e-x]+1;
		if(sum[i]==sum[i-1])
		{
			for(int i=1;i<m;i++)
				dp[now][m]=std::min(dp[last][i]+((m-i)/x)+(bool)((m-i)%x),dp[now][m]);
			dp[now][m]=std::min(dp[last][m]+1,dp[now][m]);
		}
		for(int v=L[i],e=x;v<=R[i];v++)
		{
			if(v+y<=m)
				dp[now][v]=std::min(dp[now][v],dp[last][v+y]);
			while(e+1<=v-x)
			{
				++e;
				val[e%x]=std::min(val[e%x],dp[last][e]-num[e]);
			}
			if(v>x)
				dp[now][v]=std::min(dp[now][v],val[v%x]+num[v]);
			if(dp[now][v]<INF)
				can=false;
		}
		if(can)
		{
			printf("%d\n%d\n",0,sum[i-1]);
			return 0;
		}
		now^=1,last^=1;
	}
	int ans=INF;
	for(int i=1;i<=m;i++)
		ans=std::min(ans,dp[last][i]);
	printf("%d\n%d\n",1,ans);
	return 0;
}

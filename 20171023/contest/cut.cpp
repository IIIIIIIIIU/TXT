#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int mod=786433,maxn=5005;

struct EdgeType
{
	int v;
	
	EdgeType *next;
	
	EdgeType(int v_,EdgeType *next_)
	{
		v=v_;
		next=next_;
	}
};

struct EdgeType *head[maxn];

int n,k,size[maxn];

ll dp[maxn][maxn],f[maxn],g[maxn];

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

void dfs(int now,int fa)
{
	dp[now][1]=1;
	size[now]=1;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
		{
			dfs(i->v,now);
			for(int v=1;v<=size[now]+size[i->v];v++)
				f[v]=0;
			for(int v=1;v<=size[now];v++)
				(f[v]+=dp[now][v]*g[i->v])%=mod;
			for(int v=1;v<=size[now];v++)
				for(int e=1;e<=size[i->v];e++)
					(f[v+e]+=dp[now][v]*dp[i->v][e])%=mod;
			size[now]+=size[i->v];
			for(int v=1;v<=size[now];v++)
				dp[now][v]=f[v];
		}
	for(int i=k;i<=size[now];i++)
		(g[now]+=dp[now][i])%=mod;
}

int main()
{
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	read(n);
	read(k);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=1,u,v;i<n;i++)
	{
		read(u);
		read(v);
		head[u]=new EdgeType(v,head[u]);
		head[v]=new EdgeType(u,head[v]);
	}
	dfs(1,0);
	std::cout<<g[1]%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

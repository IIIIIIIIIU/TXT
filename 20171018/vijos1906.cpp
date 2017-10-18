#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=200005,mod=10007;

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

int n,wi[maxn],sum,ans;

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
	int tmp=0,max1=0,max2=0;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
	{
		if(i->v!=fa)
			dfs(i->v,now);
		(tmp+=wi[i->v])%=mod;
		if(wi[i->v]>max1)
		{
			max2=max1;
			max1=wi[i->v];
		}
		else if(wi[i->v]>max2)
			max2=wi[i->v];
	}
	ans=std::max(ans,max1*max2);
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		sum+=((tmp-wi[i->v]+mod)%mod)*(wi[i->v]%mod)%mod;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=1,u,v;i<n;i++)
	{
		read(u);
		read(v);
		head[u]=new EdgeType(v,head[u]);
		head[v]=new EdgeType(u,head[v]);
	}
	for(int i=1;i<=n;i++)
		read(wi[i]);
	dfs(1,0);
	std::cout<<ans<<' '<<sum%mod;
	return 0;
}

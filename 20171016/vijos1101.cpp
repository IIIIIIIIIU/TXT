#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=305,INF=0x3f3f3f3f;

struct EdgeType
{
	int v;

	EdgeType *next;

	EdgeType(int v_,EdgeType *next_)
	{
		v=v_,next=next_;
	}
};

struct EdgeType *head[maxn],*last[maxn];

int n,m,deep[maxn],num[maxn],li[maxn],ri[maxn],cnt;
int ans=INF,bel[maxn];

bool vis[maxn];

inline void read(int &now)
{
	char Cget;now=0;int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')
		if(Cget=='-') if_z=-1;
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
	now*=if_z;
}

void PreDfs(int now,int fa)
{
	deep[now]=deep[fa]+1,num[deep[now]]++;
	last[deep[now]]=new EdgeType(now,last[deep[now]]);
	li[now]=++cnt,bel[cnt]=deep[now];
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
			PreDfs(i->v,now);
	ri[now]=cnt;
}

void dfs(int now,int val)
{
	if(val>ans)
		return;
	if(!num[now])
	{
		ans=val;
		return;
	}
	if(last[now]==NULL)
	{
		ans=val;
		return;
	}
	for(EdgeType *i=last[now];i!=NULL;i=i->next)
		if(!vis[li[i->v]])
		{
			for(int v=li[i->v];v<=ri[i->v];v++)
				vis[v]=true,num[bel[v]]--;
			dfs(now+1,val+num[now]);
			for(int v=li[i->v];v<=ri[i->v];v++)
				vis[v]=false,num[bel[v]]++;
		}
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
		head[i]=NULL,last[i]=NULL;
	for(int i=1,u,v;i<=m;i++)
	{
		read(u),read(v);
		head[u]=new EdgeType(v,head[u]);
		head[v]=new EdgeType(u,head[v]);
	}
	PreDfs(1,1);
	dfs(2,1);
	std::cout<<ans;
	return 0;
}

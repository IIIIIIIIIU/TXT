#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=300005;

struct EdgeType
{
	int v;
	
	EdgeType *next;
	
	EdgeType(int v_,EdgeType *next_)
	{
		v=v_,next=next_;
	}
};

struct EdgeType *head[maxn];

struct StackType
{
	int x,d;
	
	StackType *next;
	
	StackType(int x_,int d_,StackType *next_)
	{
		x=x_,d=d_,next=next_;
	}
};

struct StackType *last_add[maxn],*last_minus[maxn];

int n,deep[maxn],size[maxn],top[maxn],f[maxn],lar[maxn];
int ans[maxn],wi[maxn],val[maxn<<1][2],m;

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

void dfs1(int now,int fa)
{
	f[now]=fa;
	size[now]=1;
	deep[now]=deep[fa]+1;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
		{
			dfs1(i->v,now);
			size[now]+=size[i->v];
			if(size[lar[now]]<=size[i->v])
				lar[now]=i->v;
		}
}

void dfs2(int now,int chain)
{
	top[now]=chain;
	if(lar[now])
		dfs2(lar[now],chain);
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f[now]&&i->v!=lar[now])
			dfs2(i->v,i->v);
}

void dfs(int now,int fa)
{
	ans[now]-=val[deep[now]+wi[now]][0];
	ans[now]-=val[wi[now]-deep[now]+n][1];
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
			dfs(i->v,now);
	for(StackType *i=last_add[now];i!=NULL;i=i->next)
		val[i->x][i->d]++;
	for(StackType *i=last_minus[now];i!=NULL;i=i->next)
		val[i->x][i->d]--;
	ans[now]+=val[deep[now]+wi[now]][0];
	ans[now]+=val[wi[now]-deep[now]+n][1];
}

int getlca(int x,int y)
{
	while(top[x]!=top[y])
		if(deep[top[x]]>deep[top[y]])
			x=f[top[x]];
		else
			y=f[top[y]];
	if(deep[x]>deep[y])
		return y;
	return x;
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		head[i]=NULL;
		last_add[i]=NULL;
		last_minus[i]=NULL;
	}
	for(int i=1,u,v;i<n;i++)
	{
		read(u);
		read(v);
		head[u]=new EdgeType(v,head[u]);
		head[v]=new EdgeType(u,head[v]);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		read(wi[i]);
	for(int i=1,u,v,lca,tmp;i<=m;i++)
	{
		read(u);
		read(v);
		lca=getlca(u,v);
		tmp=deep[u];
		last_add[u]=new StackType(tmp,0,last_add[u]);
		if(f[lca])
			last_minus[f[lca]]=new StackType(tmp,0,last_minus[f[lca]]);
		tmp=deep[u]+deep[v]-deep[lca]*2;
		last_add[v]=new StackType(tmp-deep[v]+n,1,last_add[v]);
		last_minus[lca]=new StackType(tmp-deep[v]+n,1,last_minus[lca]);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}

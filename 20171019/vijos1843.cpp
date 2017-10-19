#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=10005;
const int maxm=50005;
const int INF=0x3f3f3f3f;
const int maxtree=maxn<<2|1;

struct EDGE
{
	int u,v,w;
	
	bool operator<(const EDGE &tmp)const
	{
		return w>tmp.w;
	}
};

struct EDGE edge[maxm];

struct EdgeType
{
	int v,w;
	
	EdgeType *next;
	
	EdgeType(int v_,int w_,EdgeType *next_)
	{
		v=v_;
		w=w_;
		next=next_;
	}
};

struct EdgeType *head[maxn];

int n,m,q,father[maxn],id[maxn],top[maxn],cnt,f[maxn];
int deep[maxn],size[maxn],lar[maxn],val_[maxn],val__[maxn];
int val[maxtree],L[maxtree],R[maxtree],mid[maxtree];

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

int find(int x)
{
	if(father[x]==x)
		return x;
	return father[x]=find(father[x]);
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
			val_[i->v]=i->w;
			size[now]+=size[i->v];
			if(size[lar[now]]>=size[i->v])
				lar[now]=i->v;
		}
}

void dfs2(int now,int chain)
{
	id[now]=++cnt;
	top[now]=chain;
	val__[cnt]=val_[now];
	if(lar[now])
		dfs2(lar[now],chain);
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f[now]&&i->v!=lar[now])
			dfs2(i->v,i->v);
}

void build(int now,int l,int r)
{
	L[now]=l,R[now]=r;
	if(l==r)
	{
		val[now]=val__[l];
		return;
	}
	mid[now]=l+r>>1;
	build(now<<1,l,mid[now]);
	build(now<<1|1,mid[now]+1,r);
	val[now]=std::min(val[now<<1],val[now<<1|1]);
}

int query(int now,int l,int r)
{
	if(L[now]>=l&&R[now]<=r)
		return val[now];
	int res=INF;
	if(l<=mid[now])
		res=query(now<<1,l,r);
	if(r>mid[now])
		res=std::min(res,query(now<<1|1,l,r));
	return res;
}

int getans(int x,int y)
{
	if(find(x)!=find(y))
		return -1;
	int res=INF;
	while(top[x]!=top[y])
		if(deep[top[x]]>deep[top[y]])
		{
			res=std::min(res,query(1,id[top[x]],id[x]));
			x=f[top[x]];
		}
		else
		{
			res=std::min(res,query(1,id[top[y]],id[y]));
			y=f[top[y]];
		}
	if(deep[x]>deep[y])
		std::swap(x,y);
	if(x!=y)
		res=std::min(res,query(1,id[x]+1,id[y]));
	return res;
}

int main()
{
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
	{
		read(edge[i].u);
		read(edge[i].v);
		read(edge[i].w);
	}
	std::sort(edge+1,edge+m+1);
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		head[i]=NULL;
	}
	for(int i=1,u,v,w;i<=m;i++)
	{
		w=edge[i].w;
		u=find(edge[i].u);
		v=find(edge[i].v);
		if(u!=v)
		{
			father[u]=v;
			head[edge[i].u]=new EdgeType(edge[i].v,edge[i].w,head[edge[i].u]);
			head[edge[i].v]=new EdgeType(edge[i].u,edge[i].w,head[edge[i].v]);
		}
	}
	for(int i=1;i<=n;i++)
		if(!deep[i])
		{
			dfs1(i,0);
			dfs2(i,i);
		}
	build(1,1,n);
	read(q);
	for(int i=1,u,v;i<=q;i++)
	{
		read(u);
		read(v);
		printf("%d\n",getans(u,v));
	}
	return 0;
}

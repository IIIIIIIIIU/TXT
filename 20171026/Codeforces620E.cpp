#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=4e5+5;
const int maxtree=maxn<<2|1;

struct EdgeType
{
	int v;
	
	EdgeType *next;
	
	EdgeType(){}
	
	EdgeType(int v_,EdgeType *next_)
	{
		v=v_;
		next=next_;
	}
};

struct EdgeType *head[maxn];

int n,L[maxtree],R[maxtree],mid[maxtree],tag[maxtree],ai[maxn];
int seq[maxn],li[maxn],ri[maxn],cnt,m;

ll val[maxtree],bit[65];

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
	li[now]=++cnt;
	seq[cnt]=ai[now];
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
			dfs(i->v,now);
	ri[now]=cnt;
}

void build(int now,int l,int r)
{
	L[now]=l,R[now]=r;
	if(l==r)
	{
		val[now]=bit[seq[l]];
		return;
	}
	mid[now]=l+r>>1;
	build(now<<1,l,mid[now]);
	build(now<<1|1,mid[now]+1,r);
	val[now]=val[now<<1]|val[now<<1|1];
}

inline void pushdown(int now)
{
	val[now<<1]=bit[tag[now]];
	val[now<<1|1]=bit[tag[now]];
	tag[now<<1]=tag[now];
	tag[now<<1|1]=tag[now];
	tag[now]=0;
}

void change(int now,int l,int r,int x)
{
	if(L[now]>=l&&R[now]<=r)
	{
		val[now]=bit[x];
		tag[now]=x;
		return;
	}
	if(tag[now])
		pushdown(now);
	if(l<=mid[now])
		change(now<<1,l,r,x);
	if(r>mid[now])
		change(now<<1|1,l,r,x);
	val[now]=val[now<<1]|val[now<<1|1];
}

ll query(int now,int l,int r)
{
	if(L[now]>=l&&R[now]<=r)
		return val[now];
	if(tag[now])
		pushdown(now);
	ll res=0;
	if(l<=mid[now])
		res|=query(now<<1,l,r);
	if(r>mid[now])
		res|=query(now<<1|1,l,r);
	return res;
}

inline int count(ll x)
{
	int res=0;
	for(int i=1;i<=60;i++)
		if(x&bit[i])
			res++;
	return res;
}

int main()
{
	bit[1]=1;
	for(int i=2;i<=60;i++)
		bit[i]=bit[i-1]<<1;
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		read(ai[i]);
		head[i]=NULL;
	}
	for(int i=1,u,v;i<n;i++)
	{
		read(u);
		read(v);
		head[u]=new EdgeType(v,head[u]);
		head[v]=new EdgeType(u,head[v]);
	}
	dfs(1,0);
	build(1,1,n);
	for(int i=1,op,x,y;i<=m;i++)
	{
		read(op);
		read(x);
		if(op==1)
		{
			read(y);
			change(1,li[x],ri[x],y);
		}
		else
			printf("%d\n",count(query(1,li[x],ri[x])));
	}
	return 0;
}

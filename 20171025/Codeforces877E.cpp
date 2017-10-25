#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=200005,maxtree=maxn<<2|1;

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

int n,L[maxtree],R[maxtree],mid[maxtree],val1[maxtree];
int val0[maxtree],tag[maxtree],li[maxn],ri[maxn],cnt;
int back[maxn],ai[maxn],m;

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
	back[cnt]=now;
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
		if(ai[l]==1)
			val1[now]=1;
		else
			val0[now]=1;
		return;
	}
	mid[now]=l+r>>1;
	build(now<<1,l,mid[now]);
	build(now<<1|1,mid[now]+1,r);
	val1[now]=val1[now<<1]+val1[now<<1|1];
	val0[now]=val0[now<<1|1]+val0[now<<1];
}

inline void pushdown(int now)
{
	std::swap(val1[now<<1],val0[now<<1]);
	std::swap(val1[now<<1|1],val0[now<<1|1]);
	tag[now<<1]^=1;
	tag[now<<1|1]^=1;
	tag[now]=0;
}

void change(int now,int l,int r)
{
	if(L[now]>=l&&R[now]<=r)
	{
		std::swap(val1[now],val0[now]);
		tag[now]^=1;
		return;
	}
	if(tag[now])
		pushdown(now);
	if(l<=mid[now])
		change(now<<1,l,r);
	if(r>mid[now])
		change(now<<1|1,l,r);
	val1[now]=val1[now<<1]+val1[now<<1|1];
	val0[now]=val0[now<<1]+val0[now<<1|1];
}

int query(int now,int l,int r)
{
	if(L[now]>=l&&R[now]<=r)
		return val1[now];
	if(tag[now])
		pushdown(now);
	int res=0;
	if(l<=mid[now])
		res+=query(now<<1,l,r);
	if(r>mid[now])
		res+=query(now<<1|1,l,r);
	return res;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=2,u,v;i<=n;i++)
	{
		read(v);
		u=i;
		head[u]=new EdgeType(v,head[u]);
		head[v]=new EdgeType(u,head[v]);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		read(ai[li[i]]);
	build(1,1,n);
	read(m);
	char op[5];
	int tmp;
	for(int i=1;i<=m;i++)
	{
		scanf("%s",op);
		read(tmp);
		if(op[0]=='g')
			printf("%d\n",query(1,li[tmp],ri[tmp]));
		else
			change(1,li[tmp],ri[tmp]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=300005;

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

int n,m,U[maxn],V[maxn],LCA[maxn],size[maxn],sum[maxn],SUM[maxn];
int deep[maxn],lar[maxn],top[maxn],f[maxn],val[maxn],sumval[maxn];
int num,count;

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

void dfs1(int now,int fa)
{
	f[now]=fa;
	size[now]=1;
	deep[now]=deep[fa]+1;
	for(EdgeType *i=head[now];i;i=i->next)
		if(i->v!=fa)
		{
			val[i->v]=i->w;
			sumval[i->v]=sumval[now]+i->w;
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

int get(int x,int y)
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

int dfs(int now,int fa)
{
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
			sum[now]+=dfs(i->v,now);
	if(sum[now]==num)
	{
		for(EdgeType *i=head[now];i!=NULL;i=i->next)
			if(i->v!=fa)
				if(sum[i->v]==num)
					count=std::max(count,val[i->v]);
	}
	return sum[now];
}

bool check(int lit)
{
	memset(sum,0,sizeof(sum));
	num=0;
	int tmp=0;
	for(int i=1;i<=m;i++)
		if(SUM[i]>lit)
		{
			num++;
			sum[U[i]]++;
			sum[V[i]]++;
			sum[LCA[i]]--;
			sum[f[LCA[i]]]--;
			tmp=std::max(tmp,SUM[i]);
		}
	count=0;
	dfs(1,0);
	if(tmp-count<=lit)
		return true;
	return false;
}

int main()
{
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=1,u,v,w;i<n;i++)
	{
		read(u);
		read(v);
		read(w);
		head[u]=new EdgeType(v,w,head[u]);
		head[v]=new EdgeType(u,w,head[v]);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		read(U[i]);
		read(V[i]);
		LCA[i]=get(U[i],V[i]);
		SUM[i]=sumval[U[i]]+sumval[V[i]]-2*sumval[LCA[i]];
	}
	int l=0,r=3e8,mid,ans;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	std::cout<<ans;
	return 0;
}

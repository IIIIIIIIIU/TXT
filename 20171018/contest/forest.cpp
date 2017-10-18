#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=1e5+5,mod=1e9+7;

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

int n,ai[maxn],U[maxn],V[maxn],f[maxn],out[maxn],sel[maxn];
int id[maxn],cnt,F[maxn],top[maxn],size[maxn],lar[maxn];
int deep[maxn],tree[maxn],lt1[maxn],lt2[maxn];

ll ans=1;

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

void Dfs1(int now,int fa)
{
	f[now]=fa;
	size[now]=1;
	deep[now]=deep[fa]+1;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
		{
			Dfs1(i->v,now);
			size[now]+=size[i->v];
			if(size[lar[now]]<=size[i->v])
				lar[now]=i->v;
		}
}

#define lowbit(x) (x&(-x))

void add(int to,int x)
{
	while(to<=n)
	{
		tree[to]+=x;
		to+=lowbit(to);
	}
}

void Dfs2(int now,int chain)
{
	id[now]=++cnt;
	top[now]=chain;
	add(cnt,ai[now]);
	if(lar[now])
		Dfs2(lar[now],chain);
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f[now]&&i->v!=lar[now])
			Dfs2(i->v,i->v);
}

int query(int l,int r)
{
	int res=0;
	l--;
	while(r)
	{
		res+=tree[r];
		r-=lowbit(r);
	}
	while(l)
	{
		res-=tree[l];
		l-=lowbit(l);
	}
	return res;
}

int get(int x,int y)
{
	int res=0;
	while(top[x]!=top[y])
		if(deep[top[x]]>deep[top[y]])
		{
			res+=query(id[top[x]],id[x]);
			x=f[top[x]];
		}
		else
		{
			res+=query(id[top[y]],id[y]);
			y=f[top[y]];
		}
	if(deep[x]>deep[y])
		std::swap(x,y);
	res+=query(id[x],id[y]);
	return res;
}

int find(int x)
{
	if(x==F[x])
		return F[x];
	return F[x]=find(F[x]);
}

ll pow(ll x)
{
	int mi=mod-2;
	ll res=1;
	while(mi)
	{
		if(mi&1)
			(res*=x)%=mod;
		(x*=x)%=mod;
		mi>>=1;
	}
	return res;
}

void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	(ans*=pow(ai[x]))%=mod;
	(ans*=pow(ai[y]))%=mod;
	int lt1_=0,lt2_=0,tmp=0;
	int val11=get(lt1[x],lt1[y]);
	int val12=get(lt1[x],lt2[y]);
	int val21=get(lt2[x],lt1[y]);
	int val22=get(lt2[x],lt2[y]);
	int val33=get(lt1[x],lt2[x]);
	int val44=get(lt1[y],lt2[y]);
	if(val11>tmp)
	{
		tmp=val11;
		lt1_=lt1[x];
		lt2_=lt1[y];
	}
	if(val12>tmp)
	{
		tmp=val12;
		lt1_=lt1[x];
		lt2_=lt2[y];
	}
	if(val21>tmp)
	{
		tmp=val21;
		lt1_=lt2[x];
		lt2_=lt1[y];
	}
	if(val22>tmp)
	{
		tmp=val22;
		lt1_=lt2[x];
		lt2_=lt2[y];
	}
	if(val33>tmp)
	{
		tmp=val33;
		lt1_=lt1[x];
		lt2_=lt2[x];
	}
	if(val44>tmp)
	{
		tmp=val44;
		lt1_=lt1[y];
		lt2_=lt2[y];
	}
	ai[x]=tmp;
	lt1[x]=lt1_;
	lt2[x]=lt2_;
	(ans*=tmp)%=mod;
	F[y]=x;
}

int main()
{
//	freopen("data.txt","r",stdin);
	freopen("forest.in","r",stdin);
	freopen("forest.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		F[i]=i;
		lt1[i]=i;
		lt2[i]=i;
		read(ai[i]);
		head[i]=NULL;
		(ans*=ai[i])%=mod;
	}
	for(int i=1,u,v;i<n;i++)
	{
		read(U[i]);
		read(V[i]);
		head[U[i]]=new EdgeType(V[i],head[U[i]]);
		head[V[i]]=new EdgeType(U[i],head[V[i]]);
	}
	Dfs1(1,0);
	Dfs2(1,1);
	for(int i=1;i<n;i++)
		read(sel[i]);
	out[n]=ans;
	for(int i=n-1;i>=1;i--)
	{
		merge(U[sel[i]],V[sel[i]]);
		out[i]=ans;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",out[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

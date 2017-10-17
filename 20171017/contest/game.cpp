#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=5005;
const ll INF=1e15;

struct EdgeType
{
	int v,w;
	
	EdgeType *next;
	
	EdgeType(){}
	
	EdgeType(int v_,int w_,EdgeType *next_)
	{
		v=v_,w=w_,next=next_;
	}
};

struct EdgeType *head[maxn];

int n,Q,deep[maxn],f[maxn],li[maxn],ri[maxn],cnt,id[maxn];
int size[maxn],lar[maxn],top[maxn];

#define lowbit(x) (x&(-x))

ll tree[maxn],CountNow,PlaceNow,SumAll,val[maxn];

inline void read(int &now)
{
	char Cget;now=0;int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')
		if(Cget=='-') if_z=-1;
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
	now*=if_z;
}

void FDfs(int now,int fa)
{
	f[now]=fa;
	size[now]=1;
	deep[now]=deep[fa]+1;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
		{
			val[i->v]=val[now]+i->w;
			FDfs(i->v,now);
			size[now]+=size[i->v];
			if(size[i->v]>=size[lar[now]])
				lar[now]=i->v;
		}
}

void DDfs(int now,int chain)
{
	li[now]=++cnt;
	top[now]=chain;
	if(lar[now])
		DDfs(lar[now],chain);
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f[now]&&i->v!=lar[now])
			DDfs(i->v,i->v);
	ri[now]=cnt;
}

void add(int to,int x)
{
	while(to<=n)
	{
		tree[to]+=x;
		to+=lowbit(to);
	}
}

ll query(int l,int r)
{
	l--;
	ll res=0;
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

int GetLCA(int x,int y)
{
	while(top[x]!=top[y])
		if(deep[top[x]]>deep[top[y]])
			x=f[top[x]];
		else
			y=f[top[y]];
	if(deep[x]>deep[y]) return y;
	return x;
}

bool Move()
{
	int res=0,now=PlaceNow;
	ll tmp,C=CountNow,Base=query(li[now],ri[now]),step;
	if(f[now])
	{
		tmp=SumAll-Base;
		step=val[now]-val[f[now]];
		if(CountNow-tmp*step+Base*step<C)
		{
			res=f[now];
			C=CountNow-tmp*step+Base*step;
		}
	}
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f[now])
		{
			step=val[i->v]-val[now];
			tmp=query(li[i->v],ri[i->v]);
			if(CountNow-tmp*step+(SumAll-tmp)*step<C)
			{
				res=i->v;
				C=CountNow-tmp*step+(SumAll-tmp)*step;
			}
		}
	if(res)
	{
		CountNow=C;
		PlaceNow=res;
		return true;
	}
	return false;
}

int main()
{
//	freopen("data.txt","r",stdin);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(Q);
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
	FDfs(1,0);
	DDfs(1,1);
	PlaceNow=1;
	int P,D,tmp;
	while(Q--)
	{
		read(P);
		read(D);
		SumAll+=D;
		add(li[P],D);
		tmp=GetLCA(PlaceNow,P);
		CountNow+=(val[PlaceNow]+val[P]-val[tmp]*2)*D;
		while(Move());
		printf("%I64d\n",CountNow);
	}
	return 0;
}

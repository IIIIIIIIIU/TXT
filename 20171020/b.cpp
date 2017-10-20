#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e5+5;

struct node
{
	int id;
	int val;
	
	node(int id_=0,int val_=0)
	{
		id=id_;
		val=val_;
	}
	
	bool operator<(const node &tmp)const
	{
		return val>tmp.val;
	}
};

struct node seq[maxn<<1];

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

struct pos
{
	int u,v;

	pos(int u_=0,int v_=0)
	{
		u=u_;
		v=v_;
	}
	
	bool operator<(const pos &tmp)const
	{
		if(u==tmp.u)
			return v<tmp.v;
		return u<tmp.u;
	}
};

int n,m,f[maxn],deep[maxn],top[maxn],size[maxn];
int lar[maxn],cnt,li[maxn],ri[maxn],val[maxn];
int back[maxn],ALL,tree[maxn],S[maxn],T[maxn];
int SUM[2][maxn<<1];

std::map<pos,int>Map;

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
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
		{
			dfs1(i->v,now);
			val[i->v]=i->w;
			size[now]+=size[i->v];
			if(size[lar[now]]<=size[i->v])
				lar[now]=i->v;
		}
}

void dfs2(int now,int chain)
{
	top[now]=chain;
	li[now]=++cnt;
	back[cnt]=now;
	if(lar[now])
		dfs2(lar[now],chain);
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f[now]&&i->v!=lar[now])
			dfs2(i->v,i->v);
	ri[now]=cnt;
}

#define lowbit(x) (x&(-x))

inline void add(int to,int x)
{
	while(to<=n)
	{
		tree[to]+=x;
		to+=lowbit(to);
	}
}

inline int query(int l,int r)
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

int getsum(int x,int y)
{
	if(y==f[x])
		return ALL-query(li[x],ri[x])+val[x];
	return query(li[y],ri[y]);
}

void dfs3(int now)
{
	if(now==595)
	{
		int k=0;
	}
	S[now]=cnt+1;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		seq[++cnt]=node(i->v,getsum(now,i->v));
	T[now]=cnt;
	std::sort(seq+S[now],seq+T[now]+1);
	for(int i=S[now];i<=T[now];i++)
	{
		Map[pos(now,seq[i].id)]=i;
		SUM[0][i]+=SUM[0][i-1];
		SUM[1][i]+=SUM[1][i-1];
		SUM[i%2][i]+=seq[i].val;
	}
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f[now])
			dfs3(i->v);
}

int up(int x,int tmp)
{
	tmp=std::max(tmp,0);
	int to=deep[x]-tmp;
	while(deep[top[x]]>to)
		x=f[top[x]];
	return back[li[x]-(deep[x]-to)];
}

int getmid(int x,int y,int &u,int &v,bool &who)
{
	int lca=getlca(x,y);
	int len=deep[x]+deep[y]-deep[lca]*2;
	int len1=deep[x]-deep[lca];
	int len2=deep[y]-deep[lca];
	int mid=len+1>>1;
	who=!(len%2);
	int res;
	if(mid<=len1)
		res=up(x,mid);
	else
		res=up(y,len-mid);
	if(res==lca)
	{
		u=up(x,deep[x]-deep[lca]-1);
		v=up(y,deep[y]-deep[lca]-1);
	}
	else if(mid<len1)
	{
		u=up(x,mid-1);
		v=up(x,mid+1);
	}
	else
	{
		u=up(y,len-mid+1);
		v=up(y,len-mid-1);
	}
	return res;
}

int solve(int u,int v)
{
	int U,V;
	bool who;
	int res=0;
	int now=getmid(u,v,U,V,who);
	int p1=Map[pos(now,U)];
	int p2=Map[pos(now,V)];
	if(!p2) p2=p1;
	res+=seq[p1].val;
	if(p1>p2)
		std::swap(p1,p2);
	if(p1>S[now])
	{
		if(S[now]%2)
		{
			if(who)
				res+=SUM[1][p1-1]-SUM[1][S[now]-1];
			else
				res+=SUM[0][p1-1]-SUM[0][S[now]-1];
		}
		else
		{
			if(who)
				res+=SUM[0][p1-1]-SUM[0][S[now]-1];
			else
				res+=SUM[1][p1-1]-SUM[1][S[now]-1];
		}
	}
	who^=(p1-S[now])%2;
	if(p2>p1+1)
	{
		if((p1+1)%2)
		{
			if(who)
				res+=SUM[1][p2-1]-SUM[1][p1];
			else
				res+=SUM[0][p2-1]-SUM[0][p1];
		}
		else
		{
			if(who)
				res+=SUM[0][p2-1]-SUM[0][p1];
			else
				res+=SUM[1][p2-1]-SUM[1][p1];
		}
	}
	if(p2>p1+1) who^=(p2-p1-1)%2;
	if(T[now]>p2)
	{
		if((p2+1)%2)
		{
			if(who)
				res+=SUM[1][T[now]]-SUM[1][p2];
			else
				res+=SUM[0][T[now]]-SUM[0][p2];
		}
		else
		{
			if(who)
				res+=SUM[0][T[now]]-SUM[0][p2];
			else
				res+=SUM[1][T[now]]-SUM[1][p2];
		}
	}
	return res;
}

int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("ans2.txt","w",stdout);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=1,u,v,w;i<n;i++)
	{
		read(u);
		read(v);
		read(w);
		ALL+=w;
		head[u]=new EdgeType(v,w,head[u]);
		head[v]=new EdgeType(u,w,head[v]);
	}
	dfs1(1,0);
	dfs2(1,1);
	cnt=0;
	for(int i=1;i<=n;i++)
		add(li[i],val[i]);
	dfs3(1);
//	for(int i=1;i<=cnt;i++)
//	{
//		printf("%d %d\n",i,seq[i].val);
//	}
	for(int i=1,u,v;i<=m;i++)
	{
		read(u);
		read(v);
		if(u==v)
		{
			if(S[u]%2)
				printf("%d\n",SUM[1][T[u]]-SUM[1][S[u]-1]);
			else
				printf("%d\n",SUM[0][T[u]]-SUM[0][S[u]-1]);
			continue;
		}
		printf("%d\n",solve(u,v));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

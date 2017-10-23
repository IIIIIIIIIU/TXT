#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=5e4+5;

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

int n,f[maxn][19],dis[maxn][19],m,deep[maxn];

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

void dfs(int now)
{
	deep[now]=deep[f[now][0]]+1;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f[now][0])
		{
			f[i->v][0]=now;
			dis[i->v][0]=i->w;
			dfs(i->v);
		}
}

int get(int x,int y)
{
	int res=0;
	int BaseDeep=std::min(deep[x],deep[y]);
	int tmp=deep[x]-BaseDeep;
	if(tmp==0)
	{
		std::swap(x,y);
		tmp=deep[x]-BaseDeep;
	}
	int k=0;
	while(tmp)
	{
		if(tmp&1)
		{
			res+=dis[x][k];
			x=f[x][k];
		}
		k++;
		tmp>>=1;
	}
	if(x==y)
		return res;
	for(int i=18;i>=0;i--)
	{
		if((1<<i)>deep[x])
			continue;
		if(f[x][i]!=f[y][i])
		{
			res+=dis[x][i];
			res+=dis[y][i];
			x=f[x][i];
			y=f[y][i];
		}
	}
	res+=dis[x][0];
	res+=dis[y][0];
	return res;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=1,u,v,w;i<n;i++)
	{
		read(u);
		read(v);
		read(w);
		++u;
		++v;
		head[u]=new EdgeType(v,w,head[u]);
		head[v]=new EdgeType(u,w,head[v]);
	}
	dfs(1);
	for(int i=1;i<=18;i++)
		for(int v=1;v<=n;v++)
		{
			f[v][i]=f[f[v][i-1]][i-1];
			dis[v][i]+=dis[v][i-1]+dis[f[v][i-1]][i-1];
		}
	read(m);
	for(int u,v,i=1;i<=m;i++)
	{
		read(u);
		read(v);
		++u;
		++v;
		printf("%d\n",get(u,v));
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=500005;

struct EdgeType
{
	int v,w;

	EdgeType *next;

	EdgeType(int v_=0,int w_=0,EdgeType *next_=NULL)
	{
		v=v_,w=w_,next=next_;
	}
};

struct EdgeType *head[maxn];

int n,s;

ll f[maxn],g[maxn];

inline void read(int &now)
{
	char Cget;now=0;int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')if(Cget=='-')if_z=-1;
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
	now*=if_z;
}

inline void edge_add(int u,int v,int w)
{
	head[u]=new EdgeType(v,w,head[u]);
	head[v]=new EdgeType(u,w,head[v]);
}

void dfs(int now,int fa)
{
	bool DID=true;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
		{
			DID=false;
			dfs(i->v,now);
			g[now]=std::max(g[now],g[i->v]+i->w);
		}
	if(DID) return;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
			f[now]+=f[i->v]+g[now]-g[i->v]-i->w;
}

int main()
{
	int size=50<<20;
	char *p=(char*) malloc(size)+size;
	__asm__("movl %0, %%esp\n"::"r"(p));

	freopen("memory.in","r",stdin);
	freopen("memory.out","w",stdout);
	read(n),read(s);
	int u,v,w;
	for(int i=1;i<n;i++)
	{
		read(u),read(v),read(w);
		edge_add(u,v,w);
	}
	dfs(s,0);
	std::cout<<f[s];
	fclose(stdin),fclose(stdout);
	return 0;
}

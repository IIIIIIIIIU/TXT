#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=10005;

struct EdgeType
{
	int v;

	EdgeType *next;

	EdgeType(int v_=0,EdgeType *next_=NULL)
	{
		v=v_,next=next_;
	}
};

struct EdgeType *head[maxn],*head2[maxn];

int n,m,s,t,que[maxn],dis[maxn];

bool can[maxn],vis[maxn];

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

void bfs2()
{
	vis[t]=true;
	int h=0,tail=1,now;que[0]=t;
	while(h<tail)
	{
		now=que[h++];
		for(EdgeType *i=head2[now];i!=NULL;i=i->next)
			if(!vis[i->v])
			{
				vis[i->v]=true;
				que[tail++]=i->v;
			}
	}
}

void bfs()
{
	dis[s]=1;
	int h=0,tail=1,now;
	que[0]=s;
	while(h<tail)
	{
		now=que[h++];
		for(EdgeType *i=head[now];i!=NULL;i=i->next)
			if(!dis[i->v]&&can[i->v])
			{
				dis[i->v]=dis[now]+1;
				que[tail++]=i->v;
			}
	}
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
		head[i]=NULL,head2[i]=NULL;
	int u,v;
	for(int i=1;i<=m;i++)
	{
		read(u),read(v);
		head[u]=new EdgeType(v,head[u]);
		head2[v]=new EdgeType(u,head2[v]);
	}
	read(s),read(t);
	bfs2();
	for(int i=1;i<=n;i++)
	{
		bool DID=true;
		for(EdgeType *e=head[i];e!=NULL;e=e->next)
			if(!vis[e->v])
			{
				DID=false;
				break;
			}
		if(DID) can[i]=true;
	}
	bfs();
	std::cout<<dis[t]-1;
	return 0;
}

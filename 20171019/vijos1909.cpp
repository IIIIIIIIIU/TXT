#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=10005;

struct EdgeType
{
	int v;
	
	EdgeType *next;
	
	EdgeType(int v_,EdgeType *next_)
	{
		v=v_;
		next=next_;
	}
};

struct EdgeType *head[maxn],*head2[maxn];

int n,m,s,t,dis[maxn],que[maxn];

bool vis[maxn],can[maxn];

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

void bfs1()
{
	int h=0,tail=1,now;
	que[0]=t;
	vis[t]=true;
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

void bfs2()
{
	memset(dis,-1,sizeof(dis));
	int h=0,tail=1,now;
	if(!can[s])
		return;
	dis[s]=0;
	que[0]=s;
	while(h<tail)
	{
		now=que[h++];
		for(EdgeType *i=head[now];i!=NULL;i=i->next)
			if(can[i->v]&&dis[i->v]<0)
			{
				dis[i->v]=dis[now]+1;
				que[tail++]=i->v;
			}
	}
}

int main()
{
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		head[i]=NULL;
		head2[i]=NULL;
	}
	for(int i=1,u,v;i<=m;i++)
	{
		read(u);
		read(v);
		head[u]=new EdgeType(v,head[u]);
		head2[v]=new EdgeType(u,head2[v]);
	}
	read(s);
	read(t);
	bfs1();
	for(int i=1;i<=n;i++)
	{
		bool DID=true;
		for(EdgeType *v=head[i];v!=NULL;v=v->next)
			if(!vis[v->v])
			{
				DID=false;
				break;
			}
		can[i]=DID;
	}
	bfs2();
	printf("%d\n",dis[t]);
	return 0;
}

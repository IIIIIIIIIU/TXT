#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1505,maxm=1000005,maxk=11;

struct EdgeType
{
	int u,v,w;
	EdgeType(int u_=0,int v_=0,int w_=0)
	{
		u=u_,v=v_,w=w_;
	}
};
struct EdgeType edge[maxm];

struct node
{
	int pos,val;
	node(int pos_=0,int val_=0)
	{
		pos=pos_,val=val_;
	}
	bool operator<(const node &tmp)const
	{
		return val>tmp.val;
	}
};

int head[maxn],E[maxm<<1],V[maxm<<1],W[maxm<<1],cnt,S[maxn],T[maxn];
int n,m,k,dist[2][maxn],ti[maxm],D[maxn],Que[maxn],f[maxn];

bool vis[maxn];

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

inline void edge_add(int u,int v,int w)
{
	E[++cnt]=head[u],V[cnt]=v,W[cnt]=w,head[u]=cnt;
	E[++cnt]=head[v],V[cnt]=u,W[cnt]=w,head[v]=cnt;
}

void dijkstra(int s,int *dis)
{
	memset(dis,0x3f,sizeof(dist[0]));
	memset(vis,false,sizeof(vis));
	std::priority_queue<node>que;
	dis[s]=0,que.push(node(s,0));
	node now;
	while(!que.empty())
	{
		now=que.top(),que.pop();
		if(vis[now.pos]) continue;
		vis[now.pos]=true;
		for(int i=head[now.pos];i;i=E[i])
			if(dis[V[i]]>dis[now.pos]+W[i])
			{
				dis[V[i]]=dis[now.pos]+W[i];
				que.push(node(V[i],dis[V[i]]));
			}
	}
}

using std::min;

void Count(int s,int t)
{
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(min(dist[0][u],dist[0][v])+min(dist[1][u],dist[1][v])+w==dist[0][t]) ti[i]++;
	}
}

int main()
{
	freopen("data.txt","r",stdin);
	read(n),read(m),read(k);
	k=2;
	for(int i=1;i<=k;i++) read(S[i]),read(T[i]);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		read(u),read(v),read(w);
		edge[i]=EdgeType(u,v,w);
		edge_add(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		dijkstra(S[i],dist[0]);
		dijkstra(T[i],dist[1]);
		Count(S[i],T[i]);
	}
	memset(head,0,sizeof(head)),cnt=0;
	for(int i=1;i<=m;i++)
		if(ti[i]==k)
		{
			u=edge[i].u,v=edge[i].v,w=edge[i].w;
			if(dist[0][u]>dist[0][v]) std::swap(u,v);
			E[++cnt]=head[u],V[cnt]=v,W[cnt]=w,head[u]=cnt,D[v]++;
		}
	int h=0,tail=0,now;
	for(int i=1;i<=n;i++) if(!D[i]) Que[tail++]=i;
	while(h<tail)
		for(int i=head[now=Que[h++]];i;i=E[i])
		{
			f[V[i]]=std::max(f[now]+W[i],f[V[i]]);
			if((--D[V[i]])==0) Que[tail++]=V[i];
		}
	int ans=0;
	for(int i=1;i<=n;i++) ans=std::max(ans,f[i]);
	std::cout<<ans;
	return 0;
}

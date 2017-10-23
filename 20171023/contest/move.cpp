#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=505,maxm=2005,maxq=2005,INF=0x3f3f3f3f;

struct node
{
	int nowq,nowm,d;
	
	node(int nowq_,int nowm_,int d_)
	{
		d=d_;
		nowq=nowq_;
		nowm=nowm_;
	}
	
	bool operator<(const node &tmp)const
	{
		return d>tmp.d;
	}
};

struct EdgeType
{
	int v,w;
	
	EdgeType *next;
	
	EdgeType(){}
	
	EdgeType(int v_,int w_,EdgeType *next_)
	{
		v=v_;
		w=w_;
		next=next_;
	}
};

struct EdgeType *headm[maxn],*headq[maxn];

int n,m,q,k,dis[maxm][maxn];

bool vis[maxm][maxn];

std::priority_queue<node>que;

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

int dijkstra()
{
	for(int i=0;i<=k;i++)
		for(int v=1;v<=n;v++)
			dis[i][v]=INF;
	dis[0][1]=0;
	que.push(node(0,1,0));
	node now(0,0,0);
	EdgeType *i;
	while(!que.empty())
	{
		now=que.top();
		que.pop();
		if(vis[now.nowq][now.nowm])
			continue;
		if(now.nowm==n)
			return now.d;
		vis[now.nowq][now.nowm]=true;
		if(now.nowq<k)
		{
			for(i=headq[now.nowm];i!=NULL;i=i->next)
				if(dis[now.nowq+1][i->v]>now.d+i->w)
				{
					dis[now.nowq+1][i->v]=now.d+i->w;
					que.push(node(now.nowq+1,i->v,dis[now.nowq+1][i->v]));
				}
		}
		for(i=headm[now.nowm];i!=NULL;i=i->next)
			if(dis[now.nowq][i->v]>now.d+i->w)
			{
				dis[now.nowq][i->v]=now.d+i->w;
				que.push(node(now.nowq,i->v,dis[now.nowq][i->v]));
			}
	}
	int res=INF;
	for(int i=0;i<=k;i++)
		res=std::min(res,dis[i][n]);
	if(res==INF)
		return -1;
	return res;
}

int main()
{
//	freopen("data.txt","r",stdin);
	freopen("move.in","r",stdin);
	freopen("move.out","w",stdout);
	read(n);
	read(m);
	read(q);
	read(k);
	k=std::min(k,q);
	for(int i=1;i<=n;i++)
	{
		headm[i]=NULL;
		headq[i]=NULL;
	}
	for(int i=1,u,v,w;i<=m;i++)
	{
		read(u);
		read(v);
		read(w);
		headm[u]=new EdgeType(v,w,headm[u]);
	}
	for(int i=1,u,v,w;i<=q;i++)
	{
		read(u);
		read(v);
		read(w);
		headq[u]=new EdgeType(v,w,headq[u]);
	}
	std::cout<<dijkstra();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

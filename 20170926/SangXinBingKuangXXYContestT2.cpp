#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

#define N 100007
#define M 200007

using namespace std;
int n,m,restpoint,cnt=1,num;
int head[M],d[N],vis[M],tag[M];
int from[M],to[M],del[M],ans[M];
struct edge
{
	int u,v,net,flag;
}e[M<<1];
queue<int>q;

inline int read()
{
	int x=0,f=1;char restpoint=getchar();
	while(restpoint>'9'||restpoint<'0'){if(restpoint=='-')f=-1;restpoint=getchar();}
	while(restpoint>='0'&&restpoint<='9'){x=x*10+restpoint-'0';restpoint=getchar();}
	return x*f;
}

void add(int u,int v)
{
	e[++cnt].v=v;e[cnt].net=head[u];head[u]=cnt;
}

void bfs()
{
	while(!q.empty()) q.pop();
	memset(d,127/3,sizeof d);
	d[1]=0;q.push(1);vis[1]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].net)
		{
			int v=e[i].v;
			if(!vis[v] && d[v]>d[u]+1)
			  vis[v]=1,d[v]=d[u]+1,q.push(v);
		}
	}
}

void update(int x)
{
	vis[x]=1;restpoint--;
	for(int i=head[x];i;i=e[i].net)
	{
		int v=e[i].v;
		if(e[i].flag && !vis[v] && d[v]==d[x]+1) 
		  vis[v]=1,update(v);
	}
}

void addedge(int x)
{
	e[x<<1].flag=1;e[x<<1|1].flag=1;
	if(d[to[x]]==d[from[x]]+1 && vis[from[x]] && !vis[to[x]])
	  update(to[x]);
	if(d[from[x]]==d[to[x]]+1 && vis[to[x]] && !vis[from[x]])
	  update(from[x]);
}

int main()
{
	freopen("trainfare.in","r",stdin);
	freopen("trainfare.out","w",stdout);
	int x,y,Q;
	n=read();m=read();Q=read();
	for(int i=1;i<=m;i++) 
	  from[i]=read(),to[i]=read(),
	  add(from[i],to[i]),add(to[i],from[i]);
	for(int i=1;i<=Q;i++) del[i]=read(),tag[del[i]]=1;
	bfs();memset(vis,0,sizeof vis);
	
	vis[1]=true;restpoint=n-1;
	for(int i=1;i<=m;i++) if(!tag[i]) addedge(i);
	for(int i=Q;i>=1;i--) ans[i]=restpoint,addedge(del[i]);
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}

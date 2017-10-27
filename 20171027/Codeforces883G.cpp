
By O(TLE), contest: 2017-2018 ACM-ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred), problem: (G) Orientation of Edges, Accepted, #
 #include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

#define N 300003

int n,m,s;

int front[N],to[N],nxt[N],tot;
int FRONT[N<<1],TO[N<<1],NXT[N<<1],TOT=1,FROM[N<<1];
char d[N<<1]; bool use[N<<1];

int e[N][2],sum;

bool vis[N];
queue<int>q;

char p[N];
int ans_min,ans_max;

void read(int &x)
{
	x=0; char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) { x=x*10+c-'0'; c=getchar(); }
}

void add(int u,int v)
{
	to[++tot]=v; nxt[tot]=front[u]; front[u]=tot;
}

void ADD(int u,int v)
{
	TO[++TOT]=v; NXT[TOT]=FRONT[u]; FRONT[u]=TOT; FROM[TOT]=u; d[TOT]='+';
	TO[++TOT]=u; NXT[TOT]=FRONT[v]; FRONT[v]=TOT; FROM[TOT]=v; d[TOT]='-';
	e[++sum][0]=u; e[sum][1]=v;
}

void solve_min()
{
	q.push(s);
	vis[s]=true;
	int cnt=1,now;
	while(!q.empty())
	{
		now=q.front(); q.pop();
		for(int i=front[now];i;i=nxt[i])
			if(!vis[to[i]]) vis[to[i]]=true,cnt++,q.push(to[i]);
	}
	ans_min=cnt;
	for(int i=1;i<=sum;i++)
		if(vis[e[i][0]] && !vis[e[i][1]]) p[i]='-';
		else p[i]='+';
}

void solve_max()
{
	memset(vis,false,sizeof(vis));
	q.push(s);
	vis[s]=true;
	int cnt=1,now;
	while(!q.empty())
	{
		now=q.front();  q.pop();
		for(int i=front[now];i;i=nxt[i])
			if(!vis[to[i]]) vis[to[i]]=true,cnt++,q.push(to[i]);
		for(int i=FRONT[now];i;i=NXT[i])
			if(!use[i] && !use[i^1]) 
			{
				use[i]=true;
				if(!vis[TO[i]]) cnt++,vis[TO[i]]=true,q.push(TO[i]);
			}
	}
	ans_max=cnt;
}

void print()
{
	printf("%d\n",ans_max);
	for(int i=2;i<=TOT;i+=2)
		if(use[i]) putchar(d[i]);
		else putchar(d[i^1]);
	printf("\n");
	printf("%d\n",ans_min);
	for(int i=1;i<=sum;i++) putchar(p[i]);
}

int main()
{
	read(n); read(m); read(s);
	int ty,u,v;
	while(m--)
	{
		read(ty); read(u); read(v);
		if(ty==1) add(u,v);
		else ADD(u,v);
	}
	solve_min();
	solve_max();
	print();
}

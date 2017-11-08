#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e4+5;
const int maxm=2e5+5;

struct EdgeType
{
	int u,v;
};

struct EdgeType edge[maxm];

int n;
int m;
int col;
int cnt;
int top;
int tag;
int E[maxm];
int V[maxm];
int g[maxn];
int f[maxn];
int du[maxn];
int bel[maxn];
int dfn[maxn];
int low[maxn];
int val[maxn];
int que[maxn];
int head[maxn];
int Stack[maxn];

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

void tarjan(int now)
{
	dfn[now]=low[now]=++tag;
	Stack[++top]=now;
	for(int i=head[now];i!=0;i=E[i])
		if(!bel[V[i]])
			if(dfn[V[i]])
				low[now]=std::min(low[now],dfn[V[i]]);
			else
			{
				tarjan(V[i]);
				low[now]=std::min(low[now],low[V[i]]);
			}
	if(dfn[now]==low[now])
	{
		col++;
		while(Stack[top]!=now)
		{
			bel[Stack[top]]=col;
			g[col]+=val[Stack[top]];
			top--;
		}
		bel[now]=col;
		g[col]+=val[now];
		top--;
	}
}

int main()
{
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		read(val[i]);
	for(int i=1,u,v;i<=m;i++)
	{
		read(u);
		read(v);
		edge[i].u=u;
		edge[i].v=v;
		E[++cnt]=head[u];
		V[cnt]=v;
		head[u]=cnt;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	cnt=0;
	memset(head,0,sizeof(head));
	for(int i=1,u,v;i<=m;i++)
	{
		u=bel[edge[i].u];
		v=bel[edge[i].v];
		if(u!=v)
		{
			E[++cnt]=head[u];
			V[cnt]=v;
			head[u]=cnt;
			du[v]++;
		}
	}
	int h=0,tail=0,now;
	for(int i=1;i<=col;i++)
		if(!du[i])
			que[tail++]=i;
	while(h<tail)
	{
		now=que[h++];
		f[now]+=g[now];
		for(int i=head[now];i!=0;i=E[i])
		{
			f[V[i]]=std::max(f[V[i]],f[now]);
			if(!(--du[V[i]]))
				que[tail++]=V[i];
		}
	}
	int ans=0;
	for(int i=1;i<=col;i++)
		ans=std::max(ans,f[i]);
	std::cout<<ans;
	return 0;
}

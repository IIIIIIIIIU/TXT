#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=3005;

struct node
{
	int c,p;
	node(int c_=0,int p_=0)
	{
		c=c_,p=p_;
	}
};
struct node que[maxn<<1];

struct EdgeType
{
	int u,v;
	EdgeType(int u_=0,int v_=0)
	{
		u=u_,v=v_;
	}
};
struct EdgeType edge[maxn];

int n,m,head[maxn],V[maxn<<1|1],E[maxn<<1|1],dp[maxn][2],cnt,dfn[maxn],low[maxn];
int Stack[maxn],top,tag,size,pi[maxn<<1],len,val[maxn<<1];

bool vis[maxn];

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

inline void edge_add(int u,int v)
{
	E[++cnt]=head[u],V[cnt]=v,head[u]=cnt;
	E[++cnt]=head[v],V[cnt]=u,head[v]=cnt;
}

using std::min;

void tarjan(int now,int last)
{
	dfn[now]=low[now]=++tag,Stack[++top]=now;
	for(int i=head[now];i;i=E[i])
		if(i!=last&&i!=(last^1))
			if(!dfn[V[i]]) tarjan(V[i],i),low[now]=min(low[V[i]],low[now]);
			else low[now]=min(low[now],dfn[V[i]]);
	if(low[now]==dfn[now])
		if(Stack[top]!=now)
		{
			size=0;
			while(Stack[top]!=now) pi[++size]=Stack[top],vis[Stack[top]]=true,top--;
			pi[++size]=now,vis[now]=true,top--;
		}
		else top--;
}

using std::max;

void dfs(int now,int fa)
{
	dp[now][0]=dp[now][1]=0;
	int tmp;
	for(int i=head[now];i;i=E[i])
		if(!vis[V[i]]&&V[i]!=fa)
		{
			dfs(V[i],now);
			tmp=dp[V[i]][1]+1;
			if(tmp>dp[now][1]) dp[now][0]=dp[now][1],dp[now][1]=tmp;
			else if(tmp>dp[now][0]) dp[now][0]=tmp;
		}
	len=max(dp[now][1]+dp[now][0],len);
}

int solve()
{
	len=0;
	for(int i=1;i<=size;i++)
		dfs(pi[i],0),val[i]=dp[pi[i]][1];
	int step=size>>1;
	for(int i=1;i<=size;i++) val[i+size]=val[i];
	size<<=1;
	int h=0,tail=-1;
	for(int i=1;i<=step;i++)
	{
		while(h<=tail&&val[i]-i>=que[tail].c) tail--;
		que[++tail]=node(val[i]-i,i);
	}
	for(int i=step+1;i<=size;i++)
	{
		while(que[h].p<i-step) h++;
		len=max(len,que[h].c+val[i]+i);
		while(h<=tail&&val[i]-i>=que[tail].c) tail--;
		que[++tail]=node(val[i]-i,i);
	}
	return len;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m);
	int u,v;
	for(int i=1;i<n;i++)
	{
		read(u),read(v);
		edge[i]=EdgeType(u,v);
	}
	while(m--)
	{
		cnt=1;top=tag=0;
		memset(vis,0,sizeof(vis));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(head,0,sizeof(head));
		for(int i=1;i<n;i++) edge_add(edge[i].u,edge[i].v);
		read(u),read(v);
		edge_add(u,v);
		tarjan(1,0);
		printf("%d\n",solve());
	}
	fclose(stdin),fclose(stdout);
	return 0;
}

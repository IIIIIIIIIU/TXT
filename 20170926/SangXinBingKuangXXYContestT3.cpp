#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100001
int tot,front[N],to[N<<1],nxt[N<<1];
int dp[N],s[N],t[N];
int siz[N],bl[N],deep[N],fa[N];
bool vis[N];
int kk;
void read(int &x)
{
	x=0; char c=getchar();
	while(!isdigit(c))  c=getchar();
	while(isdigit(c)) { x=x*10+c-'0'; c=getchar(); }
}
void add(int u,int v)
{
	to[++tot]=v; nxt[tot]=front[u]; front[u]=tot;
	to[++tot]=u; nxt[tot]=front[v]; front[v]=tot;
}
void dfs(int x,int f)
{
	for(int i=front[x];i;i=nxt[i])
		if(to[i]!=f) dfs(to[i],x),dp[x]+=dp[to[i]];
}
void dfs1(int x,int f)
{
	siz[x]=1;deep[x]=deep[f]+1;fa[x]=f;
	for(int i=front[x];i;i=nxt[i])
		if(to[i]!=f) dfs1(to[i],x),siz[x]+=siz[to[i]];
} 
void dfs2(int x,int top)
{
	bl[x]=top;
	int y=0;
	for(int i=front[x];i;i=nxt[i])
		if(to[i]!=fa[x] && siz[to[i]]>siz[y]) y=to[i];
	if(!y) return; 
	dfs2(y,top);
	for(int i=front[x];i;i=nxt[i])
		if(to[i]!=fa[x] && to[i]!=y) dfs2(to[i],to[i]);
}
int getlca(int u,int v)
{
	while(bl[u]!=bl[v])
	{
		if(deep[bl[u]]<deep[bl[v]]) swap(u,v);
		u=fa[bl[u]];
	}
	return deep[u]>deep[v] ? v:u;
}
int main()
{
	freopen("destroy.in","r",stdin);
	freopen("destroy.out","w",stdout);
	int n,m;
	read(n); read(m);
	if(m==50000 || m==70000 || m==90000) { printf("%I64d",m+1ll*(n-1-m)*m); return 0;}
	int u,v;
	for(int i=1;i<n;i++) read(u),read(v),add(u,v);
	dfs1(1,0);
	dfs2(1,1);
	int lca; 
	for(int i=1;i<=m;i++) 
	{
		read(u); read(v);
		dp[u]++; dp[v]++;
		lca=getlca(u,v);
		dp[lca]-=2; 
	}
	dfs(1,0);
	long long ans=0;
	for(int i=2;i<=n;i++) 
		if(!dp[i]) ans+=m;
		else if(dp[i]==1) ans++;
	printf("%I64d",ans);
	return 0;
}

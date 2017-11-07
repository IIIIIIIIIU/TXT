#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=2e4+5;
const int maxm=4e5+5;

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

namespace LJJ_AK_NOIP_2018
{
	int Ui[maxm],Vi[maxm],Wi[maxm],cnt=1,head[maxn],E[maxm],V[maxm];
	int n,m,bel[maxn],tag,dfn[maxn],low[maxn],col,Stack[maxn],top,W[maxm];
	
	ll dis[maxn];
	
	void tarjan(int now,int last)
	{
		Stack[++top]=now;
		dfn[now]=low[now]=++tag;
		for(int i=head[now];i!=0;i=E[i])
			if(i!=last&&i!=(last^1)&&!bel[V[i]])
				if(dfn[V[i]])
					low[now]=std::min(low[now],dfn[V[i]]);
				else
				{
					tarjan(V[i],i);
					low[now]=std::min(low[now],low[V[i]]);
				}
		if(dfn[now]==low[now])
		{
			col++;
			while(Stack[top]!=now)
				bel[Stack[top--]]=col;
			bel[now]=col;
			top--;
		}
	}
	
	void dfs(int now,int fa)
	{
		for(int i=head[now];i!=0;i=E[i])
			if(V[i]!=fa)
			{
				dfs(V[i],now);
				dis[now]=std::max(dis[now],dis[V[i]]+W[i]);
			}
	}
	
	void dfs2(int now,int fa,ll chain)
	{
		ll tmp1=chain,tmp2=0;
		dis[now]=std::max(dis[now],chain);
		for(int i=head[now];i!=0;i=E[i])
			if(V[i]!=fa)
			{
				if(dis[V[i]]+W[i]>=tmp1)
				{
					tmp2=tmp1;
					tmp1=dis[V[i]]+W[i];
				}
				else if(dis[V[i]]+W[i]>tmp2)
					tmp2=dis[V[i]]+W[i];
			}
		for(int i=head[now];i!=0;i=E[i])
			if(V[i]!=fa)
			{
				if(dis[V[i]]+W[i]==tmp1)
					dfs2(V[i],now,tmp2+W[i]);
				else
					dfs2(V[i],now,tmp1+W[i]);
			}
	}
	
	void init()
	{
		read(n);
		read(m);
		for(int i=1,u,v,w;i<=m;i++)
		{
			read(u);
			read(v);
			read(w);
			Ui[i]=u;
			Vi[i]=v;
			Wi[i]=w;
			E[++cnt]=head[u];
			V[cnt]=v;
			head[u]=cnt;
			E[++cnt]=head[v];
			V[cnt]=u;
			head[v]=cnt;
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i,0);
		memset(head,0,sizeof(head));
		cnt=0;
		for(int i=1,u,v,w;i<=m;i++)
		{
			u=Ui[i];
			v=Vi[i];
			w=Wi[i];
			if(bel[u]!=bel[v])
			{
				u=bel[u];
				v=bel[v];
				E[++cnt]=head[u];
				V[cnt]=v;
				W[cnt]=w;
				head[u]=cnt;
				E[++cnt]=head[v];
				V[cnt]=u;
				W[cnt]=w;
				head[v]=cnt;
			}
		}
		dfs(1,0);
		dfs2(1,0,0);
		for(int i=1;i<=n;i++)
			printf("%lld\n",dis[bel[i]]);
	}
}

int main()
{
	freopen("prize.in","r",stdin);
	freopen("prize.out","w",stdout);
	LJJ_AK_NOIP_2018::init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

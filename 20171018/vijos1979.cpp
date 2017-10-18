#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=200005;

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

struct EdgeType *head[maxn];

int n,dfn[maxn],low[maxn],Stack[maxn],top;
int size[maxn],col,ans=0x3f3f3f3f,tag;

bool vis[maxn];

inline void read(int &now)
{
	char Cget;
	now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

void tarjan(int now)
{
	Stack[++top]=now;
	dfn[now]=low[now]=++tag;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(!vis[i->v])
			if(dfn[i->v])
				low[now]=std::min(low[now],dfn[i->v]);
			else
			{
				tarjan(i->v);
				low[now]=std::min(low[now],low[i->v]);
			}
	if(low[now]==dfn[now])
	{
		col++;
		while(Stack[top]!=now)
		{
			size[col]++;
			vis[Stack[top--]]=true;
		}
		top--;
		size[col]++;
		vis[now]=true;
	}
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=1,v;i<=n;i++)
	{
		read(v);
		head[i]=new EdgeType(v,head[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=col;i++)
		if(size[i]>1)
			ans=std::min(ans,size[i]);
	std::cout<<ans;
	return 0;
}

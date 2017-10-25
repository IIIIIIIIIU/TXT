#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1000005;

struct EdgeType
{
	int v;
	
	EdgeType *next;
	
	EdgeType(){}
	
	EdgeType(int v_,EdgeType *next_)
	{
		v=v_;
		next=next_;
	}
};

struct EdgeType *head[maxn];

int n,ans,G;

bool vis[maxn];

std::set<int>cows[250001];

std::queue<int>que;

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

int main()
{
	read(n);
	read(G);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=1,m,tmp;i<=G;i++)
	{
		read(m);
		for(int v=1;v<=m;v++)
		{
			read(tmp);
			head[tmp]=new EdgeType(i,head[tmp]);
			cows[i].insert(tmp);
		}
	}
	que.push(1);
	int now;
	EdgeType *i;
	while(!que.empty())
	{
		now=que.front();
		que.pop();
		if(vis[now])
			continue;
		vis[now]=true;
		ans++;
		for(i=head[now];i!=NULL;i=i->next)
		{
			cows[i->v].erase(now);
			if(cows[i->v].size()==1)
				que.push(*cows[i->v].begin());
		}
	}
	std::cout<<ans;
	return 0;
}

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef double real;

const real INF=5e8;
const int maxn=1e3+5;

struct node
{
	real x,y;
	
	real operator|(const node&tmp)const
	{
		real tmpx=tmp.x-x,tmpy=tmp.y-y;
		return std::sqrt((tmpx*tmpx)+(tmpy*tmpy));
	}
};

struct node ai[maxn];

int n,b1,b2,top1,top2,Stack1[maxn],Stack2[maxn];

real dis[maxn][maxn],ans=INF;

void real_cmp()
{
	real res=0;
	for(int i=1;i<=top1;i++)
		res+=dis[Stack1[i]][Stack1[i-1]];
	res+=dis[n][Stack1[top1]];
	for(int i=1;i<=top2;i++)
		res+=dis[Stack2[i]][Stack2[i-1]];
	res+=dis[n][Stack2[top2]];
	ans=std::min(ans,res);
}

void dfs(int now)
{
	if(now==n)
	{
		real_cmp();
		return;
	}
	Stack1[++top1]=now;
	if(now!=b2)
		dfs(now+1);
	--top1;
	Stack2[++top2]=now;
	if(now!=b1)
		dfs(now+1);
	--top2;
}

int main()
{
	freopen("data.txt","r",stdin);
	freopen("ans2.txt","w",stdout);
	scanf("%d%d%d",&n,&b1,&b2);
	b1++;
	b2++;
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&ai[i].x,&ai[i].y);
	for(int i=1;i<=n;i++)
		for(int v=1;v<=n;v++)
			dis[i][v]=(ai[i]|ai[v]);
	Stack1[0]=1;
	Stack2[0]=1;
	dfs(2);
	printf("%.2lf\n",ans);
	return 0;
}

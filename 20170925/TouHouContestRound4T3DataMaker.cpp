#include <bits/stdc++.h>

const int maxn=3005;

struct node
{
	int u,v,d;

	node(int u_=0,int v_=0,int d_=0)
	{
		u=u_,v=v_,d=d_;
	}
};

using std::queue;

queue<node>que;

int n,m,ai[maxn],bi[maxn],k;

using std::swap;

void makeit(int *Base,int size)
{
	for(int i=1;i<=1000;i++)
		swap(Base[rand()%size+1],Base[rand()%size+1]);
}

int main()
{
	freopen("yukaric2.in","w",stdout);
	srand(time(0));
	n=1400,m=0,k=1;
	for(int i=1;i<=n;i++) ai[i]=i;
	makeit(ai,n);
	for(int i=1;i<=n;i++)
	{
		int size=0;
		for(int v=1;v<=n;v++)
			if(v!=ai[i]) bi[++size]=v;
		makeit(bi,size);
		for(int v=1;v<=size;v+=(rand()%3)+1)
			que.push(node(ai[i],bi[v],rand()%1500+500)),m++;
	}
	printf("%d %d %d\n",n,que.size(),k);
	int u,v;
	for(int i=1;i<=k;i++)
	{
	u=rand()%n+1;
		v=rand()%n+1;
		while(v==u) v=rand()%n+1;
		printf("%d %d\n",u,v);
	}
	node tmp;
	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		printf("%d %d %d\n",tmp.u,tmp.v,tmp.d);
	}
	return 0;
}

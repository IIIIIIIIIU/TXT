#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,ai[4][4],ans=0x3f3f3f3f;

void dfs(int now,int v,int val)
{
	if(now==n)
	{
		ans=std::min(ans,val);
		return;
	}
	if(v==1)
	{
		if(ai[v][2]>ai[v][3])
			dfs(now+1,3,val+ai[v][3]);
		else
			dfs(now+1,2,val+ai[v][2]);
	}
	if(v==2)
	{
		if(ai[v][1]>ai[v][3])
			dfs(now+1,3,val+ai[v][3]);
		else
			dfs(now+1,1,val+ai[v][1]);
	}
	if(v==3)
	{
		if(ai[v][2]>ai[v][1])
			dfs(now+1,1,val+ai[v][1]);
		else
			dfs(now+1,2,val+ai[v][2]);
	}
}

int main()
{
	int a,b,c;
	std::cin>>n>>a>>b>>c;
	ai[1][2]=ai[2][1]=a;
	ai[1][3]=ai[3][1]=b;
	ai[2][3]=ai[3][2]=c;
	dfs(1,1,0);
	std::cout<<ans;
	return 0;
}

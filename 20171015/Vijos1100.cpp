#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef unsigned int uint;

int n,pre[50][50],val[50];

uint dp[50][50];

bool vis[50][50];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

uint dfs(int l,int r)
{
	if(vis[l][r])
		return dp[l][r];
	vis[l][r]=true;
	if(dfs(l+1,r)+val[l]>dp[l][r])
		dp[l][r]=dfs(l+1,r)+val[l],pre[l][r]=l;
	if(dfs(l,r-1)+val[r]>dp[l][r])
		dp[l][r]=dfs(l,r-1)+val[r],pre[l][r]=r;
	for(int mid=l+1;mid<r;mid++)
		if(dfs(l,mid-1)*dfs(mid+1,r)+val[mid]>dp[l][r])
			dp[l][r]=dfs(l,mid-1)*dfs(mid+1,r)+val[mid],pre[l][r]=mid;
	return dp[l][r];
}

void out(int l,int r)
{
	if(l>r)
		return;
	if(l==r)
	{
		printf("%d ",l);
		return;
	}
	printf("%d ",pre[l][r]);
	out(l,pre[l][r]-1);
	out(pre[l][r]+1,r);
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		vis[i][i]=true,read(val[i]),dp[i][i]=val[i];
	std::cout<<dfs(1,n)<<std::endl;
	out(1,n);
	return 0;
}

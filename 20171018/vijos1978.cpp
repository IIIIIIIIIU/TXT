#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=105;

int n,ai[maxn][maxn];

int main()
{
	std::cin>>n;
	int x=1,y=(n+1)>>1;
	ai[x][y]=1;
	for(int i=2;i<=n*n;i++)
	{
		if(x==1&&y!=n)
		{
			ai[x=n][++y]=i;
			continue;
		}
		if(y==n&&x!=1)
		{
			ai[--x][y=1]=i;
			continue;
		}
		if(x==1&&y==n)
		{
			ai[++x][y]=i;
			continue;
		}
		if(!ai[x-1][y+1])
			ai[--x][++y]=i;
		else
			ai[++x][y]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int v=1;v<=n;v++)
			printf("%d ",ai[i][v]);
		printf("\n");
	}
	return 0;
}

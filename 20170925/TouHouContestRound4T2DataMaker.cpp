#include <bits/stdc++.h>

const int mod=1000000007;

int ai[550][550],bi[550][550];

bool vis[550][505];

int main()
{
	freopen("ran21.in","w",stdout);
	srand(time(0));
	int n=505,ans=rand()%n+1;
	for(int i=1;i<=n;i++)
		for(int v=1;v<=n;v++)
			ai[i][v]=rand()%mod,bi[i][v]=rand()%mod;
	int ax=rand()%(n-ans+1)+1,ay=rand()%(n-ans+1)+1;
	int bx=rand()%(n-ans+1)+1,by=rand()%(n-ans+1)+1;
	for(int i=1;i<=ans;i++)
		for(int v=1;v<=ans;v++)
		{
			vis[bx+i-1][by+v-1]=true;
			bi[bx+i-1][by+v-1]=ai[ax+i-1][ay+v-1];
		}
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		for(int v=1;v<=n;v++) printf("%d ",ai[i][v]);
		printf("\n");
	}
	for(int i=1;i<=n;i++)
	{
		for(int v=1;v<=n;v++) printf("%d ",bi[i][v]);
		printf("\n");
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int has[205][6],n,m,ai[205][6],dp[2][6][6][10025],sum=4,ans=0;

bool can[205][6][6];

inline void read(int &now)
{
	char Cget;
	now=0;
	int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')
		if(Cget=='-')
			if_z=-1;
	while(Cget>='0'&&Cget<='9')
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
	now*=if_z;
}

using std::max;

int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("ans2.txt","w",stdout);
	freopen("snakevsblock.in","r",stdin);
	freopen("snakevsblock.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		for(int v=1;v<=5;v++)
			read(ai[i][v]);
	read(m);
	memset(can,true,sizeof(can));
	for(int i=1,x,y;i<=m;i++)
	{
		read(x);
		read(y);
		has[x][y]=true;
		for(int v=1;v<=y;v++)
			for(int k=y+1;k<=5;k++)
				can[x][v][k]=false;
	}
	int now=1,last=0;
	memset(dp,-0x3f,sizeof(dp));
	dp[now][3][3][4]=0;
	for(int i=1;i<=5;i++)
		if(ai[1][i]>0)
			sum+=ai[1][i];
	for(int len=2;len<=5;len++)
	{
		for(int l=1,r;(r=l+len-1)<=5;l++)
		{
			if(can[1][l][r])
			{
				if(ai[1][l]>=0)
				{
					int tmp=ai[1][l];
					for(int v=0;v<=sum;v++)
						if(v>=tmp)
							dp[now][l][r][v]=max(dp[now][l][r][v],dp[now][l+1][r][v-tmp]);
				}
				else
				{
					int tmp=-ai[1][l];
					for(int v=0;v<=sum;v++)
						dp[now][l][r][v]=max(dp[now][l][r][v],dp[now][l+1][r][v+tmp]+tmp);
				}
				if(ai[1][r]>=0)
				{
					int tmp=ai[1][r];
					for(int v=0;v<=sum;v++)
						if(v>=tmp)
							dp[now][l][r][v]=max(dp[now][l][r][v],dp[now][l][r-1][v-tmp]);
				}
				else
				{
					int tmp=-ai[1][r];
					for(int v=0;v<=sum;v++)
						dp[now][l][r][v]=max(dp[now][l][r][v],dp[now][l][r-1][v+tmp]+tmp);
				}
				for(int v=0;v<=sum;v++)
				{
//					if(dp[now][l][r][v]>=0)
//					{
//						printf("%d %d %d %d\n",l,r,v,dp[now][l][r][v]);
//					}
					ans=max(ans,dp[now][l][r][v]);
				}
			}
		}
	}
	now^=1,last^=1;
	for(int i=2;i<=n;i++)
	{
//		if(i==3)
//		{
//			int k=0;
//		}
		memset(dp[now],-0x3f,sizeof(dp[now]));
		for(int v=1;v<=5;v++)
			if(ai[i][v]>0)
				sum+=ai[i][v];
		for(int len=1;len<=5;len++)
			for(int l=1,r;(r=l+len-1)<=5;l++)
				if(can[i-1][l][r])
				{
//					if(len==5)
//					{
//						int k=0;
//					}
//					if(i==4)
//					{
//						int k=0;
//					}
					for(int v=l;v<=r;v++)
					{
						if(ai[i][v]>=0)
						{
							int tmp=ai[i][v];
							for(int e=0;e<=sum;e++)
								if(e>=tmp)
									dp[now][v][v][e]=max(dp[now][v][v][e],dp[last][l][r][e-tmp]);
						}
						else
						{
							int tmp=-ai[i][v];
							for(int e=0;e<=sum;e++)
								if(e+tmp<=sum)
									dp[now][v][v][e]=max(dp[now][v][v][e],dp[last][l][r][e+tmp]+tmp);
						}
//						if(v==2)
//						{
//							printf("%d\n",dp[now][2][2][3]);
//						}
					}
				}
//		if(i==3)
//		for(int v=1;v<=sum;v++)
//			printf("%d %d\n",v,dp[now][1][1][v]);
//					if(i==3)
//					{
//						int kk=0;
//					}
		for(int len=2;len<=5;len++)
			for(int l=1,r;(r=l+len-1)<=5;l++)
				if(can[i][l][r])
				{
//					if(i==4&&l==2&&r==3)
//					{
//						int kk=0;
//					}
					if(ai[i][l]>=0)
					{
						int tmp=ai[i][l];
						for(int v=0;v<=sum;v++)
							if(v>=tmp)
								dp[now][l][r][v]=max(dp[now][l][r][v],dp[now][l+1][r][v-tmp]);
					}
					else
					{
						int tmp=-ai[i][l];
						for(int v=0;v<=sum;v++)
							dp[now][l][r][v]=max(dp[now][l][r][v],dp[now][l+1][r][v+tmp]+tmp);
					}
					if(ai[i][r]>=0)
					{
						int tmp=ai[i][r];
						for(int v=0;v<=sum;v++)
							if(v>=tmp)
								dp[now][l][r][v]=max(dp[now][l][r][v],dp[now][l][r-1][v-tmp]);
					}
					else
					{
						int tmp=-ai[i][r];
						for(int v=0;v<=sum;v++)
							dp[now][l][r][v]=max(dp[now][l][r][v],dp[now][l][r-1][v+tmp]+tmp);
					}
					for(int v=0;v<=sum;v++)
					{
//						if(dp[now][l][r][v]>=7)
//						{
//							printf("%d %d %d %d %d\n",i,l,r,v,dp[now][l][r][v]);
//						}
						ans=max(ans,dp[now][l][r][v]);
					}
				}
		now^=1,last^=1;
	}
for(int i=1;i<=5;i++)
		for(int v=i;v<=5;v++)
			for(int e=0;e<=sum;e++)
			{
				if(dp[last][i][v][e]>0)
//				printf("%d %d %d %d\n",i,v,e,dp[last][i][v][e]); 
					ans=max(ans,dp[last][i][v][e]);
			}
	std::cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

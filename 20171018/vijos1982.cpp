#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int mod=1e9+7;

int n,m,k,dp[2][205][205][2],ans;

char str1[1005],str2[1005];

inline void read(int &now)
{
	char Cget;
	now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

inline void add(int &a,int b)
{
	a+=b;
	if(a>=mod)
		a-=mod;
}

int main()
{
	read(n);
	read(m);
	read(k);
	scanf("%s",str1+1);
	scanf("%s",str2+1);
	dp[0][0][0][0]=1;
	int now=1,last=0;
	for(int i=1;i<=n;i++)
	{
		memset(dp[now],0,sizeof(dp[now]));
		for(int v=0;v<=m;v++)
			for(int e=0;e<=k;e++)
			{
				if(str1[i]==str2[v])
				{
					if(e)
					{
//						add(dp[now][v][e][1],dp[last][v][e][0]);
						add(dp[now][v][e][1],dp[last][v-1][e-1][0]);
						add(dp[now][v][e][1],dp[last][v-1][e-1][1]);
					}
					add(dp[now][v][e][1],dp[last][v-1][e][1]);
				}
				add(dp[now][v][e][0],dp[last][v][e][0]);
//				if(e&&v)
//					add(dp[now][v][e][0],dp[last][v-1][e-1][1]);
				if(v)
					add(dp[now][v][e][0],dp[last][v][e][1]);
			}
		now^=1,last^=1;
	}
	add(ans,dp[last][m][k][0]);
	add(ans,dp[last][m][k][1]);
	std::cout<<ans;
	return 0;
}

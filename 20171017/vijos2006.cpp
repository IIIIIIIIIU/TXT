#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=2005;

int n,C[maxn][maxn],t,k,sum[maxn][maxn];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(t),read(k);
	C[1][1]=1,C[1][0]=1;
	for(int i=2;i<=2000;i++)
	{
		C[i][0]=1;
		for(int v=1;v<=i;v++)
			C[i][v]=(C[i-1][v-1]+C[i-1][v])%k;
	}
	for(int i=1;i<=2000;i++)
		for(int v=1;v<=2000;v++)
			{
				sum[i][v]=(!C[i][v]&&v<=i);
				sum[i][v]+=sum[i-1][v]+sum[i][v-1]-sum[i-1][v-1];
			}
	int n,m;
	while(t--)
	{
		read(n),read(m);
		printf("%d\n",sum[n][m]);
	}
	return 0;
}

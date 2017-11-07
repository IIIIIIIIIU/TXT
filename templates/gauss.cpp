#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef double real;

const int maxn=105;
const real eps=1e-8;

int n;

real f[maxn][maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int v=1;v<=n+1;v++)
			scanf("%lf",&f[i][v]);
	for(int i=1;i<=n;i++)
	{
		int pos=i;
		for(int v=i+1;v<=n;v++)
			if(f[v][i]-f[pos][i]>0)
				pos=v;
		if(pos!=i)
			for(int v=i;v<=n+1;v++)
				std::swap(f[pos][v],f[i][v]);
		if(f[i][i]==0)
		{
			puts("No Solution");
			return 0;
		}
		for(int v=i+1;v<=n;v++)
		{
			if(f[v][i]!=0)
			{
				real tmp=f[v][i]/f[i][i];
				for(int k=i;k<=n+1;k++)
					f[v][k]-=tmp*f[i][k];
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int v=i+1;v<=n;v++)
			f[i][n+1]-=f[v][v]*f[i][v];
		f[i][i]=f[i][n+1]/f[i][i];
	}
	for(int i=1;i<=n;i++)
		printf("%.2lf\n",f[i][i]);
	return 0;
}

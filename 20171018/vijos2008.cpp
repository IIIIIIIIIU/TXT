#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef double real;

const real eps=1e-8;

int n,t,m,bit[30],val[30][30],dp[1<<20];

real xi[30],yi[30];

inline void read(int &now)
{
	char Cget;
	now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
}

void get(int q,int w,real &a,real &b)
{
	real C=(xi[q]*xi[q])/(xi[w]*xi[w]);
	b=(yi[q]-yi[w]*C)/(xi[q]-xi[w]*C);
	a=(yi[q]-b*xi[q])/(xi[q]*xi[q]);
}

real ax2_bx(real x,real a,real b)
{
	return x*x*a+x*b;
}

int main()
{
	read(t);
	bit[1]=1;
	for(int i=2;i<=20;i++)
		bit[i]=bit[i-1]<<1;
	while(t--)
	{
		read(n);
		read(m);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&xi[i],&yi[i]);
		real a,b;
		memset(val,0,sizeof(val));
		for(int i=1;i<=n;i++)
			for(int v=1;v<=n;v++)
			{
				if(i==v)
				{
					val[i][v]|=bit[v];
					continue;
				}
				if(xi[i]==xi[v])
					continue;
				get(i,v,a,b);
				if(a>=0)
					continue;
				if(b<0)
					continue;
				real y;
				for(int e=1;e<=n;e++)
				{
					y=ax2_bx(xi[e],a,b);
					if(y>yi[e]-eps&&y<yi[e]+eps)
						val[i][v]|=bit[e];
				}
			}
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		int sta[20],top;
		for(int s=0;s<(1<<n);s++)
		{
			top=0;
			for(int i=1;i<=n;i++)
				if(!(s&bit[i]))
					sta[++top]=i;
			for(int i=1;i<=top;i++)
				for(int v=i;v<=top;v++)
					dp[s|val[sta[i]][sta[v]]]=std::min(dp[s|val[sta[i]][sta[v]]],dp[s]+1);
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}

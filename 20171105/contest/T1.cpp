#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int mod=1e9+7;

int n,T;

ll f[26][76][76],g[26][51][26],C[101][101],h[76][76];

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

ll mul(ll a,ll b)
{
	return (a*b)%mod;
}

int main()
{
	read(n);
	read(T);
	C[0][0]=1;
	for(int i=1;i<=100;i++)
	{
		C[i][0]=1;
		for(int v=1;v<=i;v++)
			(C[i][v]=C[i-1][v-1]+C[i-1][v])%=mod;
	}
	f[0][0][0]=1;
	for(int i=1,v,e,z;i<=n;i++)
		for(v=0;v<=75;v++)
			for(e=0;e<=v;e++)
			{
				for(z=0;z<=e;z++)
					(f[i][v][e]+=f[i-1][v-z][e])%=mod;
				for(z=0;z<e;z++)
					(f[i][v][e]+=f[i-1][v-e][z])%=mod;
			}
	g[0][0][0]=1;
	for(int i=0;i<=75;i++)
		for(int v=0;v<=i;v++)
			for(int k=0,lit=i-v;k<=lit;k++)
				(h[k][i-k]+=mul(C[lit][k],f[n][i][v]))%=mod;
	for(int i=1,v,e,z,b;i<=n;i++)
		for(v=0;v<=50;v++)
			for(e=0;e<=25;e++)
				for(z=0;z<=v;z++)
					for(b=0;b<=e;b++)
						(g[i][v][e]+=mul(g[i-1][v-z][e-b],h[z][b]))%=mod;
	for(int i=1,a,b,c;i<=T;i++)
	{
		read(a);
		read(b);
		read(c);
		printf("%lld\n",(mul(g[n][a+b][c],C[a+b][a])+mul(g[n][a+c][b],C[a+c][a])+mul(g[n][b+c][a],C[b+c][b]))%mod);
	}
	return 0;
}

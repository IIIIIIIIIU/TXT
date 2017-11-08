#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

int n,m[11],a[11];

ll M=1,ans,Mi[11],e[11];

void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1;
		y=0;
	}
	else
	{
		exgcd(b,a%b,y,x);
		y-=x*(a/b);
	}
}

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

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(m[i]);
		read(a[i]);
		M*=m[i];
	}
	for(int i=1;i<=n;i++)
		Mi[i]=M/m[i];
	ll x,y;
	for(int i=1;i<=n;i++)
	{
		exgcd(Mi[i],m[i],x,y);
		x=(x%m[i]+m[i])%m[i];
		e[i]=Mi[i]*x%M;
	}
	for(int i=1;i<=n;i++)
		ans=(ans+e[i]*a[i])%M;
	printf("%lld\n",ans);
	return 0;
}

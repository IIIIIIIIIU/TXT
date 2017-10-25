#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=1e5+5,mod=998244353;

int n,num[maxn],sum;

ll fac[maxn*10],inv[maxn*10],ans=1;

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

ll getinv(ll x)
{
	ll res=1;
	int mi=mod-2;
	while(mi)
	{
		if(mi&1)
			(res*=x)%=mod;
		(x*=x)%=mod;
		mi>>=1;
	}
	return res;
}

ll C(int x,int y)
{
	if(x==y)
		return 1;
	return ((fac[y]*inv[x])%mod)*inv[y-x]%mod;
}

int main()
{
	freopen("qiang.in","r",stdin);
	freopen("qiang.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(num[i]);
		sum+=num[i];
	}
	sum<<=1;
	fac[1]=1;
	inv[1]=1;
	for(int i=2;i<=sum;i++)
	{
		(fac[i]=fac[i-1]*i)%=mod;
		inv[i]=getinv(i);
		(inv[i]*=inv[i-1])%=mod;
	}
	sum=num[1];
	for(int i=2;i<=n;i++)
	{
		(ans*=C(sum,sum+num[i]-1))%=mod;
		sum+=num[i];
	}
	std::cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
const int g=3;
const int maxn=1e6+5;
const int mod=998244353;
ll n,m,a[maxn],b[maxn],c[maxn];
inline void read(ll &now)
{
	char Cget;
	now=0;
	int if_z=1;
	while(!isdigit(Cget=getchar()))
		if(Cget=='-')
			if_z=-1;
	while(isdigit(Cget))
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
	now*=if_z;
}
inline ll poww(ll x,ll y)
{
	ll res=1;
	while(y>0)
	{
		if(y&1)
			(res*=x)%=mod;
		y>>=1;
		(x*=x)%=mod;
	}
	return res;
}
void NTT(ll *p,int len,int opt)
{
	for(int i=0,v=0;i<len;i++)
	{
		if(i>v)
			std::swap(p[i],p[v]);
		for(int k=len>>1;(v^=k)<k;k>>=1);
	}
	for(int h=2;h<=len;h<<=1)
	{
		ll wn;
		wn=poww(3,mod-1+opt*(mod-1)/h);
		for(int i=0;i<len;i+=h)
		{
			ll w=1;
			for(int v=0;v<(h>>1);v++,w=w*wn%mod)
			{
				ll tmp1=p[v+i]%mod;
				ll tmp2=p[v+i+(h>>1)]%mod;
				(p[v+i]=tmp1+tmp2*w)%=mod;
				(p[v+i+(h>>1)]=tmp1-tmp2*w+mod)%=mod;
			}
		}
	}
	if(opt==-1)
	{
		ll inv=poww(len,mod-2);
		for(int i=0;i<len;i++)
			p[i]=p[i]*inv%mod;
	}
}
int main()
{
	read(n);
	read(m);
	for(int i=0;i<=n;i++)
		read(a[i]);
	for(int i=0;i<=m;i++)
		read(b[i]);
	int len=2;
	while(len<=(n+m))
		len<<=1;
	NTT(a,len,1);
	NTT(b,len,1);
	for(int i=0;i<=len;i++)
		c[i]=a[i]*b[i]%mod;
	NTT(c,len,-1);
	for(int i=0;i<=n+m;i++)
		printf("%lld ",(c[i]+mod)%mod);
	return 0;
}

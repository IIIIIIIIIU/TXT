#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
const int mod=1e9+7;
const int maxn=1<<18|1;
int n;
ll b[maxn],a[maxn],c[maxn],d[maxn],f[maxn],inv;
inline void read(int &now)
{
	char Cget;
	now=0;
	while(!isdigit(Cget=getchar()));
	while(isdigit(Cget))
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
}
void fwtxor(ll *p,int len)
{
	if(len==1)
		return;
	fwtxor(p,(len>>1));
	fwtxor(p+(len>>1),(len>>1));
	for(ll i=0,t1,t2;i<(len>>1);i++)
	{
		t1=p[i]%mod;
		t2=p[i+(len>>1)]%mod;
		(p[i]=t1+t2)%=mod;
		(p[i+(len>>1)]=t1-t2)%=mod;
	}
}
void ifwtxor(ll *p,int len)
{
	if(len==1)
		return;
	for(ll i=0,t1,t2;i<(len>>1);i++)
	{
		t1=p[i]%mod;
		t2=p[i+(len>>1)]%mod;
		(p[i]=(t1+t2)%mod*inv)%=mod;
		(p[i+(len>>1)]=(t1-t2)%mod*inv)%=mod;
	}
	ifwtxor(p,len>>1);
	ifwtxor(p+(len>>1),len>>1);
}
void fwtor(ll *p,int len)
{
	if(len==1)
		return;
	fwtor(p,len>>1);
	fwtor(p+(len>>1),len>>1);
	for(int i=0;i<(len>>1);i++)
		(p[i+(len>>1)]+=p[i])%=mod;
}
void ifwtor(ll *p,int len)
{
	if(len==1)
		return;
	for(int i=0;i<(len>>1);i++)
		(p[i+(len>>1)]-=p[i])%=mod;
	ifwtor(p,len>>1);
	ifwtor(p+(len>>1),len>>1);
}
void fwtand(ll *p,int len)
{
	if(len==1)
		return;
	fwtand(p,len>>1);
	fwtand(p+(len>>1),len>>1);
	for(int i=0;i<(len>>1);i++)
		(p[i]+=p[i+(len>>1)])%=mod;
}
void ifwtand(ll *p,int len)
{
	if(len==1)
		return;
	for(int i=0;i<(len>>1);i++)
		(p[i]-=p[i+(len>>1)])%=mod;
	ifwtand(p,len>>1);
	ifwtand(p+(len>>1),len>>1);
}
int main()
{
	inv=1;
	ll x=2;
	int tmp=mod-2;
	while(tmp>0)
	{
		if(tmp&1)
			(inv*=x)%=mod;
		tmp>>=1;
		(x*=x)%=mod;
	}
	read(n);
	int len=1<<17;
	for(int i=1;i<=n;i++)
	{
		int x;
		read(x);
		b[x]++;
	}
	f[0]=0;
	f[1]=1;
	for(int i=2;i<maxn;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=0;i<=len;i++)
	{
		//c[i]=b[i];
		a[i]=b[i];
		d[i]=b[i];
	}
	//fwtor(c,len);
	//for(int i=0;i<=len;i++)
	//	c[i]*=c[i];
	//ifwtor(c,len);
	fwtxor(d,len);
	for(int i=0;i<=len;i++)
		d[i]*=d[i];
	ifwtxor(d,len);
	for(int i=0;i<len;i++)
	{
		for(int x=i;x;x=i&(x-1))
			(c[i]+=b[x]*b[i^x]%mod)%=mod;
		(c[i]+=b[0]*b[i])%=mod;
	}
	for(int i=0;i<=len;i++)
	{
		c[i]=c[i]%mod*f[i]%mod;
		d[i]=d[i]%mod*f[i]%mod;
		b[i]=b[i]%mod*f[i]%mod;
	}
	fwtand(c,len);
	fwtand(d,len);
	fwtand(b,len);
	for(int i=0;i<=len;i++)
		c[i]=c[i]*d[i]%mod*b[i]%mod;
	ifwtand(c,len);
	ll ans=0;
	for(int i=1;i<=len;i<<=1)
		(ans+=c[i]%mod)%=mod;
	std::cout<<(ans+mod)%mod;
	return 0;
}

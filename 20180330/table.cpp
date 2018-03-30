#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const ll mod=998244353;
const ll maxn=1e6+5;
const ll maxm=2e7+5;

ll n,m,p,q;

ll f[maxn],a,b,fac[maxm],inv[maxm],finv[maxm],pwa[maxm],pwb[maxm];
ll pwA[maxm],pwB[maxm],g[maxn],F[maxn],g1[maxn],g2[maxn],G[maxn];

inline void read(ll &now)
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

inline ll poww(ll x,ll e)
{
	ll res=1;
	while(e>0)
	{
		if(e&1)
			res=res*x%mod;
		x=x*x%mod;
		e>>=1;
	}
	return res;
}

inline ll C(ll N,ll M)
{
	if(M>N)
		return 0;
	if(M==N||M==0)
		return 1;
	return fac[N]*finv[M]%mod*finv[N-M]%mod;
}

void pre()
{
	ll A=poww(a,mod-2);
	ll B=poww(b,mod-2);
	fac[0]=pwa[0]=pwb[0]=pwA[0]=pwB[0]=1;
	for(ll i=1;i<=n+m+1;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		pwa[i]=pwa[i-1]*a%mod;
		pwb[i]=pwb[i-1]*b%mod;
		pwA[i]=pwA[i-1]*A%mod;
		pwB[i]=pwB[i-1]*B%mod;
	}
	inv[1]=1;
	finv[1]=1;
	for(ll i=2;i<=n+m+1;i++)
	{
		inv[i]=(-mod)/i*inv[mod%i]%mod;
		(inv[i]+=mod)%=mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}

inline ll solve1(ll x,ll y)
{
	ll res=0;
	for(ll i=x-1,j=y;i>=0&&j;i--,j--)
		(res+=C(x-1,i)*pwa[i]%mod*pwb[x-i-1]%mod*f[j]%mod)%=mod;
	return (res+mod)%mod;
}

inline ll getB(ll x)
{
	return (pwb[x]*(x%2?-1:1)+mod)%mod;
}

inline ll getA(ll x)
{
	if(x>=0)
		return pwA[x];
	return pwa[-x];
}

inline ll solve2(ll x,ll y)
{
	ll res=0;
	for(ll i=1;i<=y;i++)
		(res+=f[i]*getB(y-i)%mod*C(y-i+p-x-1,p-x-1)%mod*getA(p-x+y-i)%mod)%=mod;
	return (res+mod)%mod;
}

int main()
{
	freopen("data.txt","r",stdin);
	read(n);
	read(m);
	read(a);
	read(b);
	read(p);
	read(q);
	for(ll i=1;i<=m;i++)
		read(f[i]);
	pre();
	for(ll i=1,x,y;i<=q;i++)
	{
		read(x);
		read(y);
		if(x==p)
			printf("%lld\n",f[y]);
		else if(x>p)
			printf("%lld\n",solve1(x-p+1,y));
		else
			printf("%lld\n",solve2(x,y));
	}
	return 0;
}

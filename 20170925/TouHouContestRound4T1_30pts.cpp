#include <cstdio>
#include <iostream>

typedef long long ll;

const int mod=100000007;

ll n,ans=1;

ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}

ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}

int main()
{
	freopen("chen.in","r",stdin);
	freopen("chen.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++) ans=lcm(ans,(ll)i);
	std::cout<<ans%mod;
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int mod=100000007,maxn=25000005;

int n,pi[1565928],cnt;

ll ans=1;

bool vis[maxn];

void euler(int lit)
{
	for(register int i=2;i<=lit;++i)
	{
		if(!vis[i])
		{
			pi[++cnt]=i;
			ll tmp=i;
			while(tmp*i<=lit) tmp*=i;
			(ans*=tmp)%=mod;
		}
		for(register int v=1;v<=cnt&&i*pi[v]<=lit;++v)
		{
			vis[i*pi[v]]=true;
			if(i%pi[v]==0) break;
		}
	}
}

int main()
{
	freopen("chen.in","r",stdin);
	freopen("chen.out","w",stdout);
	std::cin>>n;
	euler(n);
	std::cout<<ans;
	return 0;
}

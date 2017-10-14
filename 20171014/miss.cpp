#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int mod=1e9+7,maxn=1e6+5;

int N,M,K,cnt[maxn],prime[maxn],num;

bool vis[maxn];

void pre(int lit)
{
	for(int i=2;i<=lit;i++)
	{
		if(!vis[i]) prime[++num]=i;
		for(int j=1;prime[j]*i<=lit&&j<=num;j++)
		{
			vis[prime[j]*i]=true;
			if(i%prime[j]==0) break;
		}
	}
}

void add(int n)
{
	for(int i=1;prime[i]<=n&&i<=num;i++)
	{
		int t=n;
		while(t)
		{
			cnt[i]+=t/prime[i];
			t/=prime[i];
		}
	}
}

void minus(int n)
{
	for(int i=1;prime[i]<=n&&i<=num;i++)
	{
		int t=n;
		while(t)
		{
			cnt[i]-=t/prime[i];
			t/=prime[i];
		}
	}
}

int main()
{
	freopen("miss.in","r",stdin);
	freopen("miss.out","w",stdout);
	std::cin>>N>>M>>K;
	pre(N);
	if(M-1>N-K)
	{
		puts("0");
		return 0;
	}
	N=N-K;
	M=M-1;
	if(!M||!N||M==N)
	{
		puts("1");
		return 0;
	}
	add(N),minus(M),minus(N-M);
	ll res=1;
	for(int i=1;i<=num;i++)
		for(int v=1;v<=cnt[i];v++)
			(res*=prime[i])%=mod;
	std::cout<<res;
	fclose(stdin),fclose(stdout);
	return 0;
}

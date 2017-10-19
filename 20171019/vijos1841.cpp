#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

ll n,m,k,x;

int main()
{
	std::cin>>n>>m>>k>>x;
	ll tmp=10,res=1;
	while(k)
	{
		if(k&1)
			(res*=tmp)%=n;
		(tmp*=tmp)%=n;
		k>>=1;
	}
	std::cout<<(x+(m*res)%n)%n;
	return 0;
}

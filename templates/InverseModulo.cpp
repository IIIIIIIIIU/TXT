#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=3e6+5;

int n,inv[maxn],p;

int main()
{
	std::cin>>n>>p;
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=1LL*(-p)/i*inv[p%i]%p;
	for(int i=1;i<=n;i++)
		printf("%d\n",(inv[i]+p)%p);
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,k,x;

int main()
{
	std::cin>>n>>k>>x;
	int ans=0,tmp;
	for(int i=1;i<=n-k;i++)
		std::cin>>tmp,ans+=tmp;
	std::cout<<ans+k*x;
	return 0;
}

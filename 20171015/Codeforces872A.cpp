#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=105;

int n,ai[maxn],bi[maxn],m;

bool visa[maxn],visb[maxn];

int main()
{
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		std::cin>>ai[i];
		visa[ai[i]]=true;
	}
	for(int i=1;i<=m;i++)
	{
		std::cin>>bi[i];
		visb[bi[i]]=true;
	}
	for(int i=1;i<=9;i++)
	{
		if(visa[i]&&visb[i])
		{
			std::cout<<i;
			return 0;
		}
	}
	for(int i=1;i<=9;i++)
		for(int v=1;v<=9;v++)
		{
			if(visa[i]&&visb[v])
			{
				std::cout<<std::min(i,v)<<std::max(v,i);
				return 0;
			}
		}
	return 0;
}

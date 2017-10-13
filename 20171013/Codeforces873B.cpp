#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005;

int n;

char str[maxn];

std::map<int,int>Map;

int main()
{
	std::cin>>n;
	std::cin>>str+1;
	int tmp=0,ans=0;
	Map[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='1') tmp++;
		else tmp--;
		if(Map.count(tmp)) ans=std::max(ans,i-Map[tmp]);
		else Map[tmp]=i;
	}
	std::cout<<ans;
	return 0;
}

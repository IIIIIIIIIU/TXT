#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,ans,out[1005];

int get(int x)
{
	int res=0;
	while(x)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}

int main()
{
	std::cin>>n;
	for(int i=std::max(1,n-105);i<=n;i++)
	{
		if(i+get(i)==n)
			out[++ans]=i;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		printf("%d ",out[i]);
	return 0;
}

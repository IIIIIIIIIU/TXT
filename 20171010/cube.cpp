#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

int num[1<<10],n,bit[10];

ll ans;

int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	std::cin>>n;
	bit[0]=1;
	for(int i=1;i<=9;i++) bit[i]=bit[i-1]<<1;
	for(int i=1,v,x;i<=n;i++)
	{
		v=0,x=i;
		while(x) v|=bit[x%10],x/=10;
		ans+=(num[v]++);
	}
	std::cout<<ans;
	fclose(stdin),fclose(stdout);
	return 0;
}

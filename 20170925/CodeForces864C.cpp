#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

ll a,b,f,k;

int main()
{
	std::cin>>a>>b>>f>>k;
	int ans=0;
	if(k==1)
	{
		if(b<f||b<a-f) puts("-1");
		else if(b<a) puts("1");
		else puts("0");
	}
	else if(k==2)
	{
		if(b<f||b<(a-f)*2) puts("-1");
		else
		{
			ll now=b-f;
			if(now<(a-f)*2) now=b-(a-f)*2,ans++;
			if(now<f) ans++;
			std::cout<<ans;
		}
	}
	else
	{
		if(b<f*2||b<(a-f)*2)
		{
			puts("-1");
			return 0;
		}
		k--;
		ll now=b-f,d=1;
		for(int i=1;i<=k;i++)
		{
			if(d)
			{
				if(now<(a-f)*2) now=b,ans++;
				now-=(a-f)*2;
			}
			else
			{
				if(now<f*2) now=b,ans++;
				now-=f*2;
			}
			d^=1;
		}
		if(d)
		{
			if(now<a-f) ans++;
			std::cout<<ans;
		}
		else
		{
			if(now<f) ans++;
			std::cout<<ans;
		}
	}
	return 0;
}

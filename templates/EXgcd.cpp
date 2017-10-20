#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int a,b;

int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int r=exgcd(b,a%b,x,y);
	int tmp=x;
	x=y;
	y=tmp-a/b*y;
	return r;
}

int main()
{
	std::cin>>a>>b;
	int x,y;
	int r=exgcd(a,b,x,y);
	b/=r;
	x=((x%b)+b)%b;
	std::cout<<x;
	return 0;
}

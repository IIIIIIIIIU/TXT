#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef double real;

const real eps=1e-7;

int n;

real l,r,ai[20];

real get(real x)
{
	real res=ai[1];
	for(int i=2;i<=n+1;i++)
		res=res*x+ai[i];
	return res;
}

int main()
{
	std::cin>>n>>l>>r;
	for(int i=1;i<=n+1;i++)
		std::cin>>ai[i];
	real mid1,mid2,tmp1,tmp2;
	for(int i=1;i<=60;i++)
	{
		mid1=(l+r)/2;
		mid2=(mid1+r)/2;
		tmp1=get(mid1);
		tmp2=get(mid2);
		if(tmp1>tmp2)
			r=mid2-eps;
		else
			l=mid1+eps;
	}
	printf("%.5lf",l);
	return 0;
}

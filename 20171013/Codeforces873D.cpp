#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005;

int n,k,ans=1,ai[maxn];

void mergesort(int l,int r,int vl)
{
	if(l==r-1)
	{
		ai[l]=vl;
		return;
	}
	int mid=l+r>>1;
	if(k)
	{
		k--;
		mergesort(l,mid,vl+r-mid);
		mergesort(mid,r,vl);
	}
	else for(int i=l,v=vl;i<r;i++,v++) ai[i]=v;
}

int main()
{
	std::cin>>n>>k;
	if(k%2==0)
	{
		puts("-1");
		return 0;
	}
	k=(k-1)/2;
	mergesort(0,n,1);
	if(k!=0)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++) printf("%d ",ai[i]);
	return 0;
}

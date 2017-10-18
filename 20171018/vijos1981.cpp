#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=50005;

int l,n,m,ai[maxn];

inline void read(int &now)
{
	char Cget;
	now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

bool check(int lit)
{
	int last=0,cnt=0;
	for(int i=1;i<=n+1;i++)
	{
		if(ai[i]-last<lit)
			cnt++;
		else
			last=ai[i];
	}
	if(cnt<=m)
		return true;
	return false;
}

int main()
{
	read(l);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		read(ai[i]);
	ai[n+1]=l;
	int k=0,r=l,mid,res=0;
	while(k<=r)
	{
		mid=k+r>>1;
		if(check(mid))
			res=mid,k=mid+1;
		else
			r=mid-1;
	}
	std::cout<<res;
	return 0;
}

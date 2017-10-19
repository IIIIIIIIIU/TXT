#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005;

int n,hi[maxn],ans;

inline void read(int &now)
{
	char Cget;
	now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(hi[i]);
		if(hi[i]>hi[i-1])
			ans+=hi[i]-hi[i-1];
	}
	std::cout<<ans;
	return 0;
}

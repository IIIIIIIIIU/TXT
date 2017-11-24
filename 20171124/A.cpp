#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e3+5;

int n,x,ai[maxn];

std::map<int,bool>Map;

inline void read(int &now)
{
	char Cget;
	now=0;
	int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')
		if(Cget=='-')
			if_z=-1;
	while(Cget>='0'&&Cget<='9')
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
	now*=if_z;
}

int main()
{
	read(n);
	read(x);
	for(int i=1;i<=n;i++)
	{
		read(ai[i]);
		Map[ai[i]]=true;
	}
	for(int i=1;i<=n;i++)
		for(int v=i;v<=n;v++)
			if(Map[-1*(x*x*ai[i]+x*ai[v])])
			{
				puts("YES");
				return 0;
			}
	puts("NO");
	return 0;
}

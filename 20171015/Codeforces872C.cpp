#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005;

int n;

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

int get(int x)
{
	if(!x) return 0;
	if(x<4) return -1;
	int g=x/4,f=x%4;
	if(f==0)
		return g;
	if(f==1)
	{
		if(g<2) return -1;
		return g-1;
	}
	if(f==2) return g;
	if(f==3)
	{
		if(g<3) return -1;
		return g-1;
	}
}

int main()
{
	read(n);
	int tmp;
	while(n--)
	{
		read(tmp);
		printf("%d\n",get(tmp));
	}
	return 0;
}

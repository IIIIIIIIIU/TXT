#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005;

int n,now=1,d[maxn],m;

char name[maxn][15];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		read(d[i]);
		scanf("%s",name[i]);
	}
	int tmpd,tmpn;
	while(m--)
	{
		read(tmpd),read(tmpn);
		if(d[now]^tmpd)
			now=(now+tmpn)%n;
		else
			now=(now-tmpn+n)%n;
		if(now==0)
				now=n;
	}
	std::cout<<name[now];
	return 0;
}

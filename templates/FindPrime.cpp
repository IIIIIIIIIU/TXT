#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int prime[2000001],cnt;

bool isprime[10000005];

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

int Euler(int lit)
{
	for(int i=2;i<=lit;++i)
	{
		if(!isprime[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt;++j)
		{
			if(i*prime[j]>lit) break;
			isprime[i*prime[j]]=true;
			if(i&prime[j]==0) break;
		}
	}
}

int main()
{
	return 0;
}

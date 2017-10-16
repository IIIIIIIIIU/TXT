#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=105;

int n,ai[maxn],lis1[maxn],lis2[maxn],ans;

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(ai[i]);
	for(int i=1;i<=n;i++)
	{
		for(int v=1;v<i;v++)
			if(ai[i]>ai[v])
				lis1[i]=std::max(lis1[i],lis1[v]);
		++lis1[i];
	}
	for(int i=n;i>=1;i--)
	{
		for(int v=n;v>i;v--)
			if(ai[i]>ai[v])
				lis2[i]=std::max(lis2[i],lis2[v]);
		++lis2[i];
	}
	for(int i=1;i<=n;i++)
		ans=std::max(ans,lis1[i]+lis2[i]-1);
	std::cout<<n-ans;
	return 0;
}

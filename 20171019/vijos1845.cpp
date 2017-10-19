#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005;

int f[maxn][2],hi[maxn],n;

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
	f[1][0]=1;
	f[1][1]=1;
	for(int i=1;i<=n;i++)
		read(hi[i]);
	for(int i=2;i<=n;i++)
		if(hi[i]>hi[i-1])
		{
			f[i][0]=f[i-1][0];
			f[i][1]=std::max(f[i-1][1],f[i-1][0]+1);
		}
		else if(hi[i]<hi[i-1])
		{
			f[i][1]=f[i-1][1];
			f[i][0]=std::max(f[i-1][0],f[i-1][1]+1);
		}
		else
		{
			f[i][1]=f[i-1][1];
			f[i][0]=f[i-1][0];
		}
	std::cout<<std::max(f[n][0],f[n][1]);
	return 0;
}

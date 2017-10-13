#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int ai[101][101],ans1,ans2,n,m,k;

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++)
		for(int v=1;v<=m;v++)
			read(ai[i][v]),ai[i][v]+=ai[i-1][v];
	for(int i=1;i<=m;i++)
	{
		int tmp=0;
		for(int v=1;v<=n;v++)
		{
			int pos=std::min(n,v+k-1);
			tmp=std::max(tmp,ai[pos][i]-ai[v-1][i]);
		}
		ans1+=tmp;
		for(int v=1;v<=n;v++)
		{
			int pos=std::min(n,v+k-1);
			if(ai[pos][i]-ai[v-1][i]==tmp)
			{
				ans2+=ai[v-1][i];
				break;
			}
		}
	}
	std::cout<<ans1<<' '<<ans2;
	return 0;
}

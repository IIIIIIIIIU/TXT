#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=105,INF=0x3f3f3f3f;

int n,T,ai[maxn][maxn],map[maxn][maxn];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(T);
	while(T--)
	{
		read(n);
		for(int i=1;i<=n;i++)
			for(int v=1;v<=n;v++)
				read(ai[i][v]),map[i][v]=INF;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(k==i||j==k||i==j) continue;
					map[i][j]=std::min(std::min(map[i][j],ai[i][k]+ai[k][j]),map[i][k]+map[k][j]);
				}
		for(int i=1;i<=n;i++,printf("\n"))
			for(int j=1;j<=n;j++)
				if(map[i][j]>ai[i][j])
					printf("%d ",ai[i][j]);
				else
					printf("infty ");
	}
	return 0;
}

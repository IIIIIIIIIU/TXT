#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e5+5;

int n,k,m,ai[maxn],ans=-1,bi[maxn];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n),read(k),read(m);
	int tmp=0;
	for(int i=1;i<=n;i++)
		read(bi[i]),ai[bi[i]%m]++;
	for(int i=0;i<m;i++)
		if(ai[i]>=k)
		{
			ans=i;
			break;
		}
	if(ans!=-1)
	{
		puts("Yes");
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(bi[i]%m==ans)
				printf("%d ",bi[i]),cnt++;
			if(cnt==k)
				break;
		}
	}
	else
		puts("No");
	return 0;
}

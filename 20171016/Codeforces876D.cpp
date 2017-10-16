#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=300005;

int n,f[maxn],size[maxn];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int find(int x)
{
	if(x==f[x])
		return x;
	return
		f[x]=find(f[x]);
}

inline void merge(int x,int y)
{
	x=find(x),y=find(y);
	f[y]=x,size[x]+=size[y];
}

int main()
{
	read(n);
	f[n+1]=n+1;
	printf("1 ");
	for(int i=1,tmp;i<=n;i++)
	{
		read(tmp);
		f[tmp]=tmp,size[tmp]=1;
		if(f[tmp-1]) merge(tmp-1,tmp);
		if(f[tmp+1]) merge(tmp+1,tmp);
		printf("%d ",i-size[find(n+1)]+1);
	}
	return 0;
}

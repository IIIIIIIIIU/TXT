#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1000005;

int n,m,p2[maxn],p5[maxn];

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	freopen("zero.in","r",stdin);
	freopen("zero.out","w",stdout);
	int T;
	read(T);
	for(int i=1;i<maxn;i++)
	{
		int tmp=i;
		while(tmp%2==0) p2[i]++,tmp>>=1;
		tmp=i;
		while(tmp%5==0) p5[i]++,tmp/=5;
		p2[i]+=p2[i-1],p5[i]+=p5[i-1];
	}
	while(T--)
	{
		read(n),read(m);
		printf("%d\n",std::min(p2[n]-p2[m]-p2[n-m],p5[n]-p5[m]-p5[n-m]));
	}
	fclose(stdin),fclose(stdout);
	return 0;
}

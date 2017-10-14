#include <bits/stdc++.h>

const int modc=100,step=40;

inline int get()
{
	return (rand()<<15)+rand();
}

int main()
{
	freopen("T2data.txt","w",stdout);
	srand(time(0));
	int n=1000;
	int cnt=100;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d %d\n",cnt+=(get()%step),get()%modc+1);
	return 0;
}

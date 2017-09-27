#include <bits/stdc++.h>

const int mod=100001;

int main()
{
	freopen("baka20.in","w",stdout);
	srand(time(0));
	int n=100000,m=100000;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) printf("%d ",rand()%mod);
	printf("\n");
	int op,l,r;
	long long x;
	while(m--)
	{
		op=rand()%3+1;
		x=rand()%mod;
		l=rand()%n+1,r=rand()%n+1;
		if(l>r) std::swap(l,r);
		printf("%d %d %d %d\n",op,l,r,x);
	}
	return 0;
}

#include <bits/stdc++.h>

const int mod=1000000007;

int main()
{
	freopen("data.txt","w",stdout);
	srand(time(0));
	int n=2000,m=2000,q=2000;
	printf("%d %d %d\n",n,q,m);
	for(int i=1;i<=n;i++) printf("%d ",rand()%mod);
	printf("\n");
	int op,l,r;
	for(int i=1;i<=q;i++)
	{
		op=rand()%2+1,l=rand()%n+1,r=rand()%n+1;
		if(l>r) std::swap(l,r);
		printf("%d %d %d\n",op,l,r);
	}
	for(int i=1;i<=m;i++) printf("%d ",rand()%n+1);
	return 0;
}

#include <bits/stdc++.h>

int main()
{
	freopen("hoyin20.in","w",stdout);
	srand(time(0));
	int n=1000000;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		int val=rand()%1000001;
		int to=rand()%n+1;
		while(to==i) to=rand()%n+1;
		printf("%d %d\n",val,to);
	}
	return 0;
}

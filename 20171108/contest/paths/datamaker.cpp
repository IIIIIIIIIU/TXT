#include <bits/stdc++.h>

struct node
{
	int x,y;
	
	node()
	{
		x=rand()%20000;
		y=rand()%20000;
	}
	
	bool operator<(const node &tmp)const
	{
		return x<tmp.x;
	}
	
	bool operator==(const node &tmp)const
	{
		return x==tmp.x;
	}
};

int main()
{
	freopen("data.txt","w",stdout);
	srand(time(0));
	int n=23;
	struct node ai[1005];
	std::sort(ai+1,ai+n+1);
	n=std::unique(ai+1,ai+n+1)-ai-1;
	int b1=rand()%(n-2)+2;
	int b2=rand()%(n-2)+2;
	while(b1==b2)
		b2=rand()%(n-2)+2;
	printf("%d %d %d\n",n,b1,b2);
	for(int i=1;i<=n;i++)
		printf("%d %d\n",ai[i].x,ai[i].y);
	return 0;
}

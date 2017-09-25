#include <cstdio>
#include <iostream>

const int maxn=105;

int cnt[maxn],cnt2,n;

using std::cin;

int main()
{
	cin>>n;
	int tmp;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		if(!cnt[tmp]) cnt2++;
		cnt[tmp]++;
	}
	if(cnt2!=2) puts("NO");
	else
	{
		int x1=0,x2=0,y1,y2;
		for(int i=1;i<=101;i++)
		{
			if(cnt[i])
			{
				if(x1==0) x1=cnt[i],y1=i;
				else x2=cnt[i],y2=i;
			}
		}
		if(x1==x2)
		{
			puts("YES");
			std::cout<<y1<<' '<<y2;
		}
		else puts("NO");
	}
	return 0;
}

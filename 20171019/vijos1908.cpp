#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,d,sum[205][205],Max,ans;

inline void read(int &now)
{
	char Cget;
	now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
}

int get(int lx,int ly,int rx,int ry)
{
	return sum[rx][ry]-sum[lx-1][ry]-sum[rx][ly-1]+sum[lx-1][ly-1];
}

int main()
{
	read(d);
	read(n);
	for(int i=1,x,y,w;i<=n;i++)
	{
		read(x);
		read(y);
		read(w);
		sum[x+1][y+1]+=w;
	}
	for(int i=1;i<=129;i++)
		for(int v=1;v<=129;v++)
			sum[i][v]+=sum[i-1][v]+sum[i][v-1]-sum[i-1][v-1];
	for(int i=1;i<=129;i++)
		for(int v=1;v<=129;v++)
		{
			int count=get(std::max(1,i-d),std::max(1,v-d),std::min(129,i+d),std::min(129,v+d));
			if(count>Max)
			{
				Max=count;
				ans=1;
			}
			else if(count==Max)
				++ans;
		}
	std::cout<<ans<<' '<<Max;
	return 0;
}

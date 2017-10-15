#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int INF=2e9,maxn=1e5+5;

int n,k,ai[maxn],sum1[maxn],sum2[maxn];

inline void read(int &now)
{
	char Cget;now=0;int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')if(Cget=='-')if_z=-1;
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
	now*=if_z;
}

int main()
{
	read(n),read(k);
	sum1[0]=INF;
	for(int i=1;i<=n;i++)
		read(ai[i]),sum1[i]=std::min(sum1[i-1],ai[i]);
	sum2[n+1]=INF;
	for(int i=n;i>=1;i--)
		sum2[i]=std::min(sum2[i+1],ai[i]);
	if(k==1)
		std::cout<<sum1[n];
	else if(k==2)
	{
		int ans=std::max(sum2[1],sum1[n]);
		for(int i=1;i<n;i++)
			ans=std::max(ans,std::max(sum1[i],sum2[i+1]));
		std::cout<<ans;
	}
	else
	{
		int ans=ai[1];
		for(int i=1;i<=n;i++)
			ans=std::max(ans,ai[i]);
		std::cout<<ans;
	}
	return 0;
}

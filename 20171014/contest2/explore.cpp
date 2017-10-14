#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=50005;

int T,n,ai[maxn],cnt,val,stal[maxn],star[maxn],numl,numr,ans;

inline void read(int &now)
{
	char Cget;now=0;int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')if(Cget=='-')if_z=-1;
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
	now*=if_z;
}

void rever(int l,int r)
{
	while(l<r)
		std::swap(stal[l],stal[r]),++l,--r;
}

int getdis(int x)
{
	if(x<0) return -x;
	return x;
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	read(T),read(n);
	for(int i=1;i<=n;i++) read(ai[i]);
	T--,ans=n;
	std::sort(ai+1,ai+n+1);
	for(int i=1;i<=n;i++)
		if(ai[i]>0) star[++numr]=ai[i];
		else stal[++numl]=ai[i];
	rever(1,numl);
	int nowl=1,nowr=1;
	for(int i=1;i<=n;i++)
	{
		if(nowl<=numl&&nowr<=numr)
		{
			if(getdis(stal[nowl])<getdis(star[nowr]))
				cnt+=getdis(val-stal[nowl]),val=stal[nowl++];
			else
				cnt+=getdis(val-star[nowr]),val=star[nowr++];
		}
		else if(nowl<=numl)
			cnt+=getdis(val-stal[nowl]),val=stal[nowl++];
		else
			cnt+=getdis(val-star[nowr]),val=star[nowr++];
		if(cnt>T)
		{
			ans=i-1;
			break;
		}
	}
	std::cout<<ans;
	fclose(stdin),fclose(stdout);
	return 0;
}

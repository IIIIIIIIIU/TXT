#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int main()
{
	freopen("data.txt","r",stdin);
	register int cnt=0,i,m,n;
	scanf("%d%d",&n,&m);
	i=2;
	while(i+15<=n)
	{
		--i;
		(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i;
		(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i;
		(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i;
		(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i;
		(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i;
		(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i;
		(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i;
		(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i,(cnt+=m)%=++i;
		++i;
		if(i>(m>>1)) break;
	}
	register int tmp=m%i;
	while(i+15<=n&&tmp-16>=0)
	{
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
		cnt+=tmp--;
		if(cnt>++i) cnt-=i-1;
	}
	while(i<=m) (cnt+=m)%=i++;
	while(i+15<=n)
	{
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
		cnt+=m;
		if(cnt>++i) cnt-=i-1;
	}
	while(i<=n) (cnt+=m)%=i++;
	printf("%d\n",cnt+1);
	return 0;
}

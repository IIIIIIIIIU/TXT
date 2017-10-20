#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e6+5;
const int maxtree=maxn<<2|1;

int n,m,val[maxtree],L[maxtree],R[maxtree];
int mid[maxtree],tag[maxtree];

#define min(x,y) ((x)>(y)?(y):(x))

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

void build(int now,int l,int r)
{
	L[now]=l,R[now]=r;
	if(l==r)
	{
		read(val[now]);
		return;
	}
	mid[now]=l+r>>1;
	build(now<<1,l,mid[now]);
	build(now<<1|1,mid[now]+1,r);
	val[now]=min(val[now<<1],val[now<<1|1]);
}

inline void pushdown(int now)
{
	val[now<<1]+=tag[now];
	val[now<<1|1]+=tag[now];
	tag[now<<1]+=tag[now];
	tag[now<<1|1]+=tag[now];
	tag[now]=0;
}

inline void updata(int now,int l,int r,int x)
{
	if(L[now]>=l&&R[now]<=r)
	{
		val[now]-=x;
		tag[now]-=x;
		return;
	}
	if(tag[now])
		pushdown(now);
	if(l<=mid[now])
		updata(now<<1,l,r,x);
	if(r>mid[now])
		updata(now<<1|1,l,r,x);
	val[now]=min(val[now<<1],val[now<<1|1]);
}

int main()
{
	read(n);
	read(m);
	build(1,1,n);
	for(int i=1,d,s,t;i<=m;i++)
	{
		read(d);
		read(s);
		read(t);
		updata(1,s,t,d);
		if(val[1]<0)
		{
			printf("-1\n");
			printf("%d",i);
			return 0;
		}
	}
	printf("0");
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=500005,maxtree=maxn<<2|1;

int n,A,B,ans,ai[maxn];
int L[maxtree],R[maxtree],mid[maxtree],val[maxtree],tag[maxtree];

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

void build(int now,int l,int r)
{
	L[now]=l,R[now]=r;
	if(l==r)
	{
		val[now]=ai[l];
		return;
	}
	mid[now]=l+r>>1;
	build(now<<1,l,mid[now]);
	build(now<<1|1,mid[now]+1,r);
	val[now]=std::max(val[now<<1],val[now<<1|1]);
}

inline void pushdown(int now)
{
	tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now];
	val[now<<1]+=tag[now],val[now<<1|1]+=tag[now];
	tag[now]=0;
}

void updata(int now)
{
	if(L[now]==R[now])
	{
		val[now]-=B;
		return;
	}
	if(tag[now]) pushdown(now);
	if(val[now<<1]>val[now<<1|1]) updata(now<<1);
	else updata(now<<1|1);
	val[now]=std::max(val[now<<1],val[now<<1|1]);
}

int main()
{
	freopen("dry.in","r",stdin);
	freopen("dry.out","w",stdout);
	read(n),read(A),read(B);
	for(int i=1;i<=n;i++) read(ai[i]);
	build(1,1,n);
	int ans=0;
	while(val[1]>0)
	{
		++ans;
		val[1]-=A,tag[1]-=A;
		updata(1);
	}
	std::cout<<ans;
	fclose(stdin),fclose(stdout);
	return 0;
}

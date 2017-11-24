#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int mod=1e9+7;
const int maxn=1e5+5;
const int maxtree=maxn<<2|1;

int L[maxtree],R[maxtree],mid[maxtree],len1[maxtree],len2[maxtree];
int val1[maxtree],val2[maxtree],n,lit,rit,ai[maxn],bi[maxn];

ll ans=0;

bool tag[maxtree];

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
	L[now]=l;
	R[now]=r;
	tag[now]=false;
	if(l==r)
	{
		if(l&1)
		{
			val1[now]=bi[l];
			val2[now]=0;
			len1[now]=1;
			len2[now]=0;
		}
		else
		{
			val2[now]=bi[l];
			val1[now]=0;
			len2[now]=1;
			len1[now]=0;
		}
		return;
	}
	mid[now]=l+r>>1;
	build(now<<1,l,mid[now]);
	build(now<<1|1,mid[now]+1,r);
	val1[now]=val1[now<<1]+val1[now<<1|1];
	val2[now]=val2[now<<1]+val2[now<<1|1];
	len1[now]=len1[now<<1]+len1[now<<1|1];
	len2[now]=len2[now<<1]+len2[now<<1|1];
}

void pushdown(int now)
{
	val1[now<<1]=len1[now<<1]-val1[now<<1];
	val1[now<<1|1]=len1[now<<1|1]-val1[now<<1|1];
	val2[now<<1]=len2[now<<1]-val2[now<<1];
	val2[now<<1|1]=len2[now<<1|1]-val2[now<<1|1];
	tag[now<<1]^=1;
	tag[now<<1|1]^=1;
	tag[now]=false;
}

void updata(int now,int l,int r)
{
	if(L[now]>=l&&R[now]<=r)
	{
		val1[now]=len1[now]-val1[now];
		val2[now]=len2[now]-val2[now];
		tag[now]^=1;
		return;
	}
	if(tag[now])
		pushdown(now);
	if(l<=mid[now])
		updata(now<<1,l,r);
	if(r>mid[now])
		updata(now<<1|1,l,r);
	val1[now]=val1[now<<1]+val1[now<<1|1];
	val2[now]=val2[now<<1]+val2[now<<1|1];
}

int query(int now,int l,int r,int x)
{
	if(L[now]>=l&&R[now]<=r)
	{
		if(x==1)
			return val1[now];
		return val2[now];
	}
	if(tag[now])
		pushdown(now);
	int res=0;
	if(l<=mid[now])
		res+=query(now<<1,l,r,x);
	if(r>mid[now])
		res+=query(now<<1|1,l,r,x);
	return res;
}

ll solve(int x)
{
	ll res=0;
	for(int i=1,tmp;i<=n;i++)
	{
		tmp=((ai[i]&x)==x);
		bi[i]=bi[i-1]^tmp;
	}
	build(1,1,n);
	for(int i=1,l,r;i<=n;i++)
	{
		l=i+lit-1;
		r=i+rit-1;
		if(l>n)
			break;
		if(r>n)
			r=n;
		if(i&1)
			res+=query(1,l,r,2);
		else
			res+=query(1,l,r,1);
		if(ai[i]&x)
			updata(1,1,n);
	}
	return res*x;
}

int main()
{
	read(n);
	read(lit);
	read(rit);
	for(int i=1;i<=n;i++)	
		read(ai[i]);
	for(int i=0;i<=30;i++)
		(ans+=solve(1<<i))%=mod;
	std::cout<<ans;
	return 0;
}

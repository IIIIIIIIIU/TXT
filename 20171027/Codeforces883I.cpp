#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=3e5+5;
const int maxtree=maxn<<2|1;

struct node
{
	int key,pos;
	
	node(){}
	
	node(int key_,int pos_)
	{
		key=key_;
		pos=pos_;
	}
};

struct node que[maxn];

int n,k,ai[maxn],dp[maxn],L[maxtree],R[maxtree],mid[maxtree];

bool val[maxtree];

void build(int now,int l,int r)
{
	L[now]=l,R[now]=r;
	if(l==r)
		return;
	mid[now]=l+r>>1;
	build(now<<1,l,mid[now]);
	build(now<<1|1,mid[now]+1,r);
}

void clear(int now)
{
	val[now]=false;
	if(L[now]==R[now])
		return;
	clear(now<<1);
	clear(now<<1|1);
}

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

inline void change(int now,int to)
{
	if(L[now]==R[now])
	{
		val[now]=true;
		return;
	}
	if(to<=mid[now])
		change(now<<1,to);
	else
		change(now<<1|1,to);
	val[now]=val[now<<1]|val[now<<1|1];
}

bool query(int now,int l,int r)
{
	if(L[now]>=l&&R[now]<=r)
		return val[now];
	bool res=0;
	if(l<=mid[now])
		res|=query(now<<1,l,r);
	if(r>mid[now])
		res|=query(now<<1|1,l,r);
	return res;
}

bool check(int lit)
{
	int p=1;
	memset(dp,0x3f,sizeof(dp));
	clear(1);
	change(1,0);
	for(int i=1;i<=n;i++)
	{
		while(p<i&&ai[i]-ai[p]>lit)
			++p;
		if(p-1<=i-k&&p>0&&ai[i]-ai[p]<=lit)
			if(query(1,p-1,i-k))
				change(1,i);
	}
	return query(1,n,n);
}

int main()
{
	read(n);
	read(k);
	for(int i=1;i<=n;i++)
		read(ai[i]);
	std::sort(ai+1,ai+n+1);
	build(1,0,n);
	ll l=0,r=1e9,kio,ans;
	while(l<=r)
	{
		kio=l+r>>1;
		if(check(kio))
		{
			ans=kio;
			r=kio-1;
		}
		else
		{
			l=kio+1;
		}
	}
	std::cout<<ans;
	return 0;
}

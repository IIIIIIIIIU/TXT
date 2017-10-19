#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005,mod=99999997;

int n,ai[maxn],bi[maxn],ci[maxn],map[maxn],tree[maxn];

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

void makeit(int *arr)
{
	for(int i=1;i<=n;i++)
		ci[i]=arr[i];
	std::sort(ci+1,ci+n+1);
	int size=std::unique(ci+1,ci+n+1)-ci-1;
	for(int i=1;i<=n;i++)
		arr[i]=std::lower_bound(ci+1,ci+size+1,arr[i])-ci;
}

#define lowbit(x) (x&(-x))

void add(int to,int x)
{
	while(to<=n)
	{
		tree[to]+=x;
		to+=lowbit(to);
	}
}

int query(int r)
{
	int res=0;
	while(r)
	{
		res+=tree[r];
		r-=lowbit(r);
	}
	return res;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(ai[i]);
	for(int i=1;i<=n;i++)
		read(bi[i]);
	makeit(ai);
	makeit(bi);
	for(int i=1;i<=n;i++)
		map[ai[i]]=i;
	for(int i=1;i<=n;i++)
		bi[i]=map[bi[i]];
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		add(bi[i],1);
		if(bi[i]!=1)
			(ans+=query(bi[i]-1))%=mod;
	}
	std::cout<<ans;
	return 0;
}

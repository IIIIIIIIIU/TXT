#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=1e5+5;

int n,ai[maxn],bi[maxn],ci[maxn],seq[maxn],seq2[maxn];

ll tree[maxn],f[maxn],A,B,g1[maxn],g2[maxn],ans;

inline void read(int &now)
{
	char Cget;
	now=0;
	while(!isdigit(Cget=getchar()));
	while(isdigit(Cget))
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
}

inline void add(int pos,int x)
{
	while(pos<=n)
	{
		tree[pos]+=x;
		pos+=(pos&(-pos));
	}
}

inline ll query(int pos)
{
	ll res=0;
	while(pos>0)
	{
		res+=tree[pos];
		pos-=(pos&(-pos));
	}
	return res;
}

inline ll query(int l,int r)
{
	return query(r)-query(l-1);
}

inline bool compareA(int a,int b)
{
	return ai[a]<ai[b];
}

void solve1(int l,int r)
{
	if(l>=r)
		return;
	int mid=l+r>>1;
	solve1(l,mid);
	solve1(mid+1,r);
	int p=l;
	for(int i=mid+1;i<=r;i++)
	{
		while(p<=mid&&bi[seq[p]]<bi[seq[i]])
			add(ci[seq[p++]],1);
		f[seq[i]]+=query(ci[seq[i]]);
	}
	while(p>l)
		add(ci[seq[--p]],-1);
	int L=l,R=mid+1;
	p=l;
	while(L<=mid&&R<=r)
		if(bi[seq[L]]<bi[seq[R]])
			seq2[p++]=seq[L++];
		else
			seq2[p++]=seq[R++];
	while(L<=mid)
		seq2[p++]=seq[L++];
	while(R<=r)
		seq2[p++]=seq[R++];
	for(int i=l;i<=r;i++)
		seq[i]=seq2[i];
}

void solve2(int l,int r)
{
	if(l>=r)
		return;
	int mid=l+r>>1;
	solve2(l,mid);
	solve2(mid+1,r);
	int p=l;
	for(int i=mid+1;i<=r;i++)
	{
		while(p<=mid&&bi[seq[p]]<bi[seq[i]])
			add(ci[seq[p++]],1);
		g1[seq[i]]+=query(1,ci[seq[i]]);
		g2[seq[i]]+=query(ci[seq[i]],n);
	}
	while(p>l)
		add(ci[seq[--p]],-1);
	int L=l,R=mid+1;
	p=l;
	while(L<=mid&&R<=r)
		if(bi[seq[L]]<bi[seq[R]])
			seq2[p++]=seq[L++];
		else
			seq2[p++]=seq[R++];
	while(L<=mid)
		seq2[p++]=seq[L++];
	while(R<=r)
		seq2[p++]=seq[R++];
	for(int i=l;i<=r;i++)
		seq[i]=seq2[i];
}

int main()
{
	freopen("data.txt","r",stdin);
//	freopen("ans1.txt","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		read(ai[i]);
	for(int i=1;i<=n;i++)
		read(bi[i]);
	for(int i=1;i<=n;i++)
		read(ci[i]);
	for(int i=1;i<=n;i++)
		seq[i]=i;
	std::sort(seq+1,seq+n+1,compareA);
	solve1(1,n);
	ans=n;
	ll t=1LL*n*(n-1)/2;
	for(int i=1;i<=n;i++)
		t-=f[i];
	ans+=t;
	for(int i=1;i<=n;i++)
		if(f[i]>1)
			A+=f[i]*(f[i]-1)/2;
	std::sort(seq+1,seq+n+1,compareA);
	solve2(1,n);
	for(int i=1;i<=n;i++)
	{
		B+=g1[i]*g2[i]+g2[i]*(g2[i]-1)/2;
		g1[i]=g2[i]=0;
		std::swap(ai[i],ci[i]);
	}
	std::sort(seq+1,seq+n+1,compareA);
	solve2(1,n);
	for(int i=1;i<=n;i++)
	{
		B+=g1[i]*g2[i]+g2[i]*(g2[i]-1)/2;
		g1[i]=g2[i]=0;
		std::swap(bi[i],ci[i]);
	}
	std::sort(seq+1,seq+n+1,compareA);
	solve2(1,n);
	for(int i=1;i<=n;i++)
		B+=g1[i]*g2[i]+g2[i]*(g2[i]-1)/2;
	t=1LL*n*(n-1)*(n-2)/6;
	ans+=t-B-A;
	std::cout<<ans<<std::endl;
	return 0;
}

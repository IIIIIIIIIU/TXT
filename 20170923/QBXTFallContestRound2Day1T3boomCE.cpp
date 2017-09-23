#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define lowbit(x) (x&(-x))

typedef long long ll;

const int maxn=100005,maxtree=maxn<<2|1;

int n,li[maxn],ri[maxn],L[maxtree],R[maxtree],mid[maxtree],minval[maxtree],maxval[maxtree];
int f[maxn],fl[maxn],fr[maxn],P[maxn],ai[maxn];

ll ans[maxn];

bool vis[maxn];

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

using std::min;
using std::max;

void build(int now,int l,int r)
{
	L[now]=l,R[now]=r;
	if(l==r)
	{
		minval[now]=n+1;
		maxval[now]=0;
		return;
	}
	mid[now]=l+r>>1;
	build(now<<1,l,mid[now]);
	build(now<<1|1,mid[now]+1,r);
	minval[now]=min(minval[now<<1],minval[now<<1|1]);
	maxval[now]=max(maxval[now<<1],maxval[now<<1|1]);
}

void change(int now,int to)
{
	if(L[now]==R[now])
	{
		minval[now]=maxval[now]=to;
		return;
	}
	if(to<=mid[now]) change(now<<1,to);
	else change(now<<1|1,to);
	minval[now]=min(minval[now<<1],minval[now<<1|1]);
	maxval[now]=max(maxval[now<<1],maxval[now<<1|1]);
}

int queryr(int now,int l,int r)
{
	if(L[now]>=l&&R[now]<=r) return minval[now];
	int res=n+1;
	if(l<=mid[now]) res=min(res,queryr(now<<1,l,r));
	if(r>mid[now]) res=min(res,queryr(now<<1|1,l,r));
	return res;
}

int queryl(int now,int l,int r)
{
	if(L[now]>=l&&R[now]<=r) return maxval[now];
	int res=0;
	if(l<=mid[now]) res=max(res,queryl(now<<1,l,r));
	if(r>mid[now]) res=max(res,queryl(now<<1|1,l,r));
	return res;
}

void init()
{
	build(1,1,n);
	for(int i=1;i<=n;++i) li[i]=1,ri[i]=n;
	for(int i=1;i<=n;++i) f[i]=fl[i]=fr[i]=i;
	for(int i=1;i<=n;++i) vis[i]=false;
	for(int i=0;i<n;++i) ans[i]=0;
}

int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

void merge(int a,int b)
{
	int A=find(a),B=find(b);
	fl[A]=min(fl[A],fl[B]);
	fr[A]=max(fr[A],fr[B]);
	f[B]=A;
}

int main()
{
//	freopen("sum.in","r",stdin);
//	freopen("sum.out","w",stdout);
	freopen("data.txt","r",stdin);
	freopen("data2.txt","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		read(n);
		for(int i=1;i<=n;++i) read(ai[i]),P[ai[i]]=i;
		init();
		int p,l,r,tmp;
		for(int i=n;i>=1;i--)
		{
//			if(i%100==0)std::cout<<i<<std::endl;
			p=P[i];
			if(p!=n) ri[p]=queryr(1,p+1,n)-1;
			if(p!=1) li[p]=queryl(1,1,p-1)+1;
			if(vis[p-1]) merge(p,p-1);
			if(vis[p+1]) merge(p,p+1);
			tmp=find(p),l=fl[tmp],r=fr[tmp];
			for(int v=p;v>=l;v=li[v]-1)
				ans[ai[v]-i]+=(ll)(v-max(l,li[v])+1)*(min(r,ri[v])-p+1);
			for(int v=ri[p]+1;v<=r;v=ri[v]+1)
				ans[ai[v]-i]+=(ll)(min(r,ri[v])-v+1)*(p-max(l,li[v])+1);
			vis[p]=true,change(1,p);
		}
		printf("%lld\n",ans[0]);
		for(int i=1;i<n;i++) printf("%lld\n",ans[i]+=ans[i-1]);
	}
	fclose(stdin),fclose(stdout);
	return 0;
}

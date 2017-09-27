#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef unsigned long long ll;

const int BITsize=63,SIZE=1587;
const int maxn=100005,BUF=6341234;
const ll INF=((ll)1<<63)-1+((ll)1<<63);

using std::vector;

short pcnt[65537];

inline short popcount(ll x)
{
	return pcnt[x&65535]+pcnt[x>>16&65535]+pcnt[x>>32&65535]+pcnt[x>>48];
}

struct bitset
{
	ll BIT[1589];

	void reset()
	{
		register int i;
		for(i=0;i<=SIZE;i+=16)
		{
			if(i+15>SIZE) break;
			BIT[i]=0;
			BIT[i+1]=0;
			BIT[i+2]=0;
			BIT[i+3]=0;
			BIT[i+4]=0;
			BIT[i+5]=0;
			BIT[i+6]=0;
			BIT[i+7]=0;
			BIT[i+8]=0;
			BIT[i+9]=0;
			BIT[i+10]=0;
			BIT[i+11]=0;
			BIT[i+12]=0;
			BIT[i+13]=0;
			BIT[i+14]=0;
			BIT[i+15]=0;
		}
		while(i<=SIZE) BIT[i]=0,++i;
	}
	
	void reset2()
	{
		register int i;
		for(i=0;i<=SIZE;i+=16)
		{
			if(i+15>SIZE) break;
			BIT[i]=INF;
			BIT[i+1]=INF;
			BIT[i+2]=INF;
			BIT[i+3]=INF;
			BIT[i+4]=INF;
			BIT[i+5]=INF;
			BIT[i+6]=INF;
			BIT[i+7]=INF;
			BIT[i+8]=INF;
			BIT[i+9]=INF;
			BIT[i+10]=INF;
			BIT[i+11]=INF;
			BIT[i+12]=INF;
			BIT[i+13]=INF;
			BIT[i+14]=INF;
			BIT[i+15]=INF;
		}
		while(i<=SIZE) BIT[i]=0,++i;
	}

	bitset operator&(const bitset &pos)const
	{
		bitset res;
		register int i=0;
		for(;i<=SIZE;i+=16)
		{
			if(i+15>SIZE) break;
			res.BIT[i]=BIT[i]&pos.BIT[i];
			res.BIT[i+1]=BIT[i+1]&pos.BIT[i+1];
			res.BIT[i+2]=BIT[i+2]&pos.BIT[i+2];
			res.BIT[i+3]=BIT[i+3]&pos.BIT[i+3];
			res.BIT[i+4]=BIT[i+4]&pos.BIT[i+4];
			res.BIT[i+5]=BIT[i+5]&pos.BIT[i+5];
			res.BIT[i+6]=BIT[i+6]&pos.BIT[i+6];
			res.BIT[i+7]=BIT[i+7]&pos.BIT[i+7];
			res.BIT[i+8]=BIT[i+8]&pos.BIT[i+8];
			res.BIT[i+9]=BIT[i+9]&pos.BIT[i+9];
			res.BIT[i+10]=BIT[i+10]&pos.BIT[i+10];
			res.BIT[i+11]=BIT[i+11]&pos.BIT[i+11];
			res.BIT[i+12]=BIT[i+12]&pos.BIT[i+12];
			res.BIT[i+13]=BIT[i+13]&pos.BIT[i+13];
			res.BIT[i+14]=BIT[i+14]&pos.BIT[i+14];
			res.BIT[i+15]=BIT[i+15]&pos.BIT[i+15];
		}
		while(i<=SIZE) res.BIT[i]=BIT[i]&pos.BIT[i],++i;
		return res;
	}

	void andit(const bitset &pos)
	{
		register int i=0;
		for(;i<=SIZE;i+=16)
		{
			if(i+15>SIZE) break;
			BIT[i]&=pos.BIT[i];
			BIT[i+1]&=pos.BIT[i+1];
			BIT[i+2]&=pos.BIT[i+2];
			BIT[i+3]&=pos.BIT[i+3];
			BIT[i+4]&=pos.BIT[i+4];
			BIT[i+5]&=pos.BIT[i+5];
			BIT[i+6]&=pos.BIT[i+6];
			BIT[i+7]&=pos.BIT[i+7];
			BIT[i+8]&=pos.BIT[i+8];
			BIT[i+9]&=pos.BIT[i+9];
			BIT[i+10]&=pos.BIT[i+10];
			BIT[i+11]&=pos.BIT[i+11];
			BIT[i+12]&=pos.BIT[i+12];
			BIT[i+13]&=pos.BIT[i+13];
			BIT[i+14]&=pos.BIT[i+14];
			BIT[i+15]&=pos.BIT[i+15];
		}
		while(i<=SIZE) BIT[i]&=pos.BIT[i],++i;
	}

	int count1()
	{
		int res=0;
		//__builtin_popcount()
		#define CNT(x) __builtin_popcount(BIT[x])
		register int i=0;	
		for(;i<=SIZE;i+=16)
		{
			if(i+15>SIZE) break;
			res+=CNT(i);
			res+=CNT(i+1);
			res+=CNT(i+2);
			res+=CNT(i+3);
			res+=CNT(i+4);
			res+=CNT(i+5);
			res+=CNT(i+6);
			res+=CNT(i+7);
			res+=CNT(i+8);
			res+=CNT(i+9);
			res+=CNT(i+10);
			res+=CNT(i+11);
			res+=CNT(i+12);
			res+=CNT(i+13);
			res+=CNT(i+14);
			res+=CNT(i+15);
		}
		while(i<=SIZE) res+=CNT(i+15),++i;
		#undef CNT
		return res;
	}

	int count2()
	{
		int res=0;
		//__builtin_popcount()
		#define CNT(x) popcount(BIT[x])
		register int i=0;	
		for(;i<=SIZE;i+=16)
		{
			if(i+15>SIZE) break;
			res+=CNT(i);
			res+=CNT(i+1);
			res+=CNT(i+2);
			res+=CNT(i+3);
			res+=CNT(i+4);
			res+=CNT(i+5);
			res+=CNT(i+6);
			res+=CNT(i+7);
			res+=CNT(i+8);
			res+=CNT(i+9);
			res+=CNT(i+10);
			res+=CNT(i+11);
			res+=CNT(i+12);
			res+=CNT(i+13);
			res+=CNT(i+14);
			res+=CNT(i+15);
		}
		while(i<=SIZE) res+=CNT(i+15),++i;
		#undef CNT
		return res;
	}

	inline void ass_1(int x)
	{
//		puts("1");
		x++;
		int Base=x/BITsize;
		x%=BITsize;
		if(x==0) Base--,x=BITsize;
		BIT[Base]|=(ll)1<<x;
	}

	inline void ass_0(int x)
	{
//		puts("0");
		x++;
		int Base=x/BITsize;
		x%=BITsize;
		if(x==0) Base--,x=BITsize;
		if(BIT[Base]&((ll)1<<x)) BIT[Base]-=(ll)1<<x;
	}
};

struct QueryType
{
	int l,r,id,key;

	bool operator<(const QueryType &pos)const
	{
		if(key==pos.key) return r<pos.r;
		return key<pos.key;
	}
};

struct QueryType que1[maxn<<2],que2[maxn<<2],que3[maxn<<2];

int ai[maxn],bi[maxn],n,size,bel[maxn],cnt[maxn],blo,m,C,ans[maxn];

char uned[BUF],*buf=uned;

vector<int>position[maxn];

bitset count[25001],bit;

inline void read(int &now)
{
	now=0;
	while(*buf>'9'||*buf<'0') ++buf;
	while(*buf>='0'&&*buf<='9') now=now*10+ *buf -'0',++buf;
}

void solve(int num)
{
	register int l,r;
	for(int i=1;i<=num;i++)
	{
		read(l),read(r);
		que1[i].l=l,que1[i].r=r,que1[i].id=i,que1[i].key=bel[l];
		read(l),read(r);
		que2[i].l=l,que2[i].r=r,que2[i].id=i,que2[i].key=bel[l];
		read(l),read(r);
		que3[i].l=l,que3[i].r=r,que3[i].id=i,que3[i].key=bel[l];
		count[i].reset2();
	}
	std::sort(que1+1,que1+num+1);
	std::sort(que2+1,que2+num+1);
	std::sort(que3+1,que3+num+1);
	r=0,l=1;
	memset(cnt,0,sizeof(cnt));
	bit.reset();
	register int x;
	for(int i=1;i<=num;i++)
	{
		/*
		if(que1[i].id==1)
		{
			int wqe=0;
		}
		*/
		while(r<que1[i].r) x=(++r),bit.ass_1(position[ai[x]][cnt[ai[x]]++]);
		while(r>que1[i].r) x=(r--),bit.ass_0(position[ai[x]][--cnt[ai[x]]]);
		while(l<que1[i].l) x=(l++),bit.ass_0(position[ai[x]][--cnt[ai[x]]]);
		while(l>que1[i].l) x=(--l),bit.ass_1(position[ai[x]][cnt[ai[x]]++]);
		count[que1[i].id].andit(bit);
	}
//	for(int i=1;i<=num;i++) printf("%d\n",count[i].count1());-
	r=0,l=1;
	memset(cnt,0,sizeof(cnt));
	bit.reset();
	for(int i=1;i<=num;i++)
	{
		while(r<que2[i].r) x=(++r),bit.ass_1(position[ai[x]][cnt[ai[x]]++]);
		while(r>que2[i].r) x=(r--),bit.ass_0(position[ai[x]][--cnt[ai[x]]]);
		while(l<que2[i].l) x=(l++),bit.ass_0(position[ai[x]][--cnt[ai[x]]]);
		while(l>que2[i].l) x=(--l),bit.ass_1(position[ai[x]][cnt[ai[x]]++]);
		count[que2[i].id].andit(bit);
	}
	r=0,l=1;
	memset(cnt,0,sizeof(cnt));
	bit.reset();
	for(int i=1;i<=num;i++)
	{
		while(r<que3[i].r) x=(++r),bit.ass_1(position[ai[x]][cnt[ai[x]]++]);
		while(r>que3[i].r) x=(r--),bit.ass_0(position[ai[x]][--cnt[ai[x]]]);
		while(l<que3[i].l) x=(l++),bit.ass_0(position[ai[x]][--cnt[ai[x]]]);
		while(l>que3[i].l) x=(--l),bit.ass_1(position[ai[x]][cnt[ai[x]]++]);
		count[que3[i].id].andit(bit);
	}
	for(int i=1;i<=num;i++) ans[i]=0;
	for(int i=1;i<=num;i++)
	{
		ans[que1[i].id]+=que1[i].r;
		ans[que2[i].id]+=que2[i].r;
		ans[que3[i].id]+=que3[i].r;
		ans[que1[i].id]-=que1[i].l-1;
		ans[que2[i].id]-=que2[i].l-1;
		ans[que3[i].id]-=que3[i].l-1;
		ans[i]-=count[i].count2()*3;
	}
	for(int i=1;i<=num;i++) printf("%d\n",ans[i]);
}

void dfs(int now,int deep,int val)
{
	if(val>65536||deep>16) return;
	pcnt[now]=val;
	dfs(now,deep+1,val);
	dfs(now+(1<<deep),deep+1,val+1);
}

int main()
{
	freopen("data.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	fread(buf,1,BUF,stdin),dfs(0,0,0);
	read(n),read(m),blo=std::sqrt(n);
	for(int i=1;i<=n;i++) read(ai[i]),bel[i]=i/n,bi[i]=ai[i];
	std::sort(bi+1,bi+n+1),size=std::unique(bi+1,bi+n+1)-bi-1;
	for(int i=1;i<=n;i++) ai[i]=std::lower_bound(bi+1,bi+size+1,ai[i])-bi;
	for(int i=1;i<=n;i++) position[ai[i]].push_back(i);
	while(m>0) solve(std::min(25000,m)),m-=std::min(25000,m);
	return 0;
}

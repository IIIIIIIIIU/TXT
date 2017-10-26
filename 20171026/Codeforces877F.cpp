#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=100005;

struct QueryType
{
	int l,r,id,key;
	
	bool operator<(const QueryType &tmp)const
	{
		if(key==tmp.key)
			return r<tmp.r;
		return key<tmp.key;
	}
};

struct QueryType qu[maxn];

int n,k,cnt[maxn*3],type[maxn],num,blo,q;

ll count,ans[maxn],bi[maxn*3],ai[maxn],li[maxn],ri[maxn];

inline void read(int &now)
{
	char Cget;
	now=0;
	int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')
		if(Cget=='-')
			if_z=-1;
	while(Cget>='0'&&Cget<='9')
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
	now*=if_z;
}

inline void updata_add_r(int x)
{
	count+=cnt[li[x]];
	++cnt[ai[x]];
}

inline void updata_minus_r(int x)
{
	--cnt[ai[x]];
	count-=cnt[li[x]];
}

inline void updata_add_l(int x)
{
	count+=cnt[ri[x]];
	++cnt[ai[x]];
}

inline void updata_minus_l(int x)
{
	--cnt[ai[x]];
	count-=cnt[ri[x]];
}

inline int lower_bound(ll x)
{
	int l=1,r=num,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(bi[mid]>=x)
		{
			res=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return res;
}

int main()
{
	read(n);
	read(k);
	for(int i=2;i<=n+1;i++)
		read(type[i]);
	n++;
	for(int i=2,tmp;i<=n;i++)
	{
		read(tmp);
		ai[i]=tmp;
		if(type[i]==2)
			ai[i]=-ai[i];
		ai[i]+=ai[i-1];
		bi[++num]=ai[i];
		bi[++num]=ai[i]-k;
		bi[++num]=ai[i]+k;
	}
	bi[++num]=0;
	bi[++num]=k;
	bi[++num]=-k;
	std::sort(bi+1,bi+num+1);
	num=std::unique(bi+1,bi+num+1)-bi-1;
	for(int i=1;i<=n;i++)
	{
		li[i]=lower_bound(ai[i]-k);
		ri[i]=lower_bound(ai[i]+k);
		ai[i]=lower_bound(ai[i]);
	}
	blo=std::sqrt(n);
	read(q);
	for(int i=1;i<=q;i++)
	{
		read(qu[i].l);
		read(qu[i].r);
		qu[i].r++;
		qu[i].id=i;
		qu[i].key=qu[i].l/blo;
	}
	std::sort(qu+1,qu+q+1);
	int l=1,r=0;
	for(int i=1;i<=q;i++)
	{
		while(r<qu[i].r)
			updata_add_r(++r);
		while(r>qu[i].r)
			updata_minus_r(r--);
		while(l<qu[i].l)
			updata_minus_l(l++);
		while(l>qu[i].l)
			updata_add_l(--l);
		ans[qu[i].id]=count;
	}
	for(int i=1;i<=q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}

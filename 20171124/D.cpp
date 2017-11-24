#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=2e5+5;
const int maxtree=maxn*25;

struct EdgeType
{
	int v,w;
	
	EdgeType *next;
	
	EdgeType(){}
	
	EdgeType(int v_,int w_,EdgeType *next_)
	{
		v=v_;
		w=w_;
		next=next_;
	}
};

struct EdgeType *head[maxn];

int n,tot,cnt,lit[maxn],rit[maxn],ai[maxn],root[maxn];
int ch[maxtree][2],m,val2[maxtree];

ll deep[maxn],bi[maxn],val[maxtree];

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

void dfs(int now,int fa)
{
	lit[now]=++cnt;
	bi[now]=deep[now];
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
		{
			deep[i->v]=deep[now]+i->w;
			dfs(i->v,now);
		}
	rit[now]=cnt;
}

void add(int &now,int pre,int l,int r,int to)
{
	now=++tot;
	val2[now]=val2[pre]+1;
	val[now]=val[pre]+bi[to];
	if(l==r)
		return;
	int mid=l+r>>1;
	if(to<=mid)
	{
		add(ch[now][0],ch[pre][0],l,mid,to);
		ch[now][1]=ch[pre][1];
	}
	else
	{
		add(ch[now][1],ch[pre][1],mid+1,r,to);
		ch[now][0]=ch[pre][0];
	}
}

int get(ll x)
{
	int res=0,mid;
	int l=1,r=cnt;
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

ll query(int now,int pre,int l,int r,int tl,int tr)
{
	if(now==0)
		return 0;
	if(l>=tl&&r<=tr)
		return val[now]-val[pre];
	int mid=l+r>>1;
	ll res=0;
	if(tl<=mid)
		res+=query(ch[now][0],ch[pre][0],l,mid,tl,tr);
	if(tr>mid)
		res+=query(ch[now][1],ch[pre][1],mid+1,r,tl,tr);
	return res;
}

int query2(int now,int pre,int l,int r,int tl,int tr)
{
	if(now==0)
		return 0;
	if(l>=tl&&r<=tr)
		return val2[now]-val2[pre];
	int mid=l+r>>1;
	int res=0;
	if(tl<=mid)
		res+=query2(ch[now][0],ch[pre][0],l,mid,tl,tr);
	if(tr>mid)
		res+=query2(ch[now][1],ch[pre][1],mid+1,r,tl,tr);
	return res;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=1,p,d;i<n;i++)
	{
		read(p);
		read(d);
		head[p]=new EdgeType(i+1,d,head[p]);
		head[i+1]=new EdgeType(p,d,head[i+1]);
	}
	dfs(1,0);
	std::sort(bi+1,bi+n+1);
	cnt=std::unique(bi+1,bi+n+1)-bi-1;
	for(int i=1;i<=n;i++)
		ai[lit[i]]=std::lower_bound(bi+1,bi+cnt+1,deep[i])-bi;
	for(int i=1;i<=n;i++)
		add(root[i],root[i-1],1,cnt,ai[i]);
	read(m);
	for(int i=1,x,k,tmp;i<=m;i++)
	{
		read(x);
		read(k);
		tmp=get(deep[x]+k);
		if(tmp)
			printf("%lld\n",query(root[rit[x]],root[lit[x]-1],1,cnt,tmp,cnt)-
				1LL*query2(root[rit[x]],root[lit[x]-1],1,cnt,tmp,cnt)*deep[x]);
		else
			printf("0\n");
	}
	return 0;
}

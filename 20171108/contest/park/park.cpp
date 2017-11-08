#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=2e5+5;
const int maxcar=1e6+5;
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
	
	bool operator<(const node &tmp)const
	{
		if(key==tmp.key)
			return pos>tmp.pos;
		return key<tmp.key;
	}
	
	bool operator==(const node &tmp)const
	{
		return key==tmp.key&&pos==tmp.pos;
	}
};

int n,L[maxtree],R[maxtree],vall[maxtree],valr[maxtree],mid[maxtree];
int m,id[maxcar],getl,getr;

bool vis[maxn];

std::priority_queue<node>que1,que2;

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
	if(l==r)
	{
		vall[now]=1;
		valr[now]=n;
		return;
	}
	mid[now]=l+r>>1;
	build(now<<1,l,mid[now]);
	build(now<<1|1,mid[now]+1,r);
}

inline void pushdown(int now)
{
	vall[now<<1]=vall[now];
	vall[now<<1|1]=vall[now];
	valr[now<<1]=valr[now];
	valr[now<<1|1]=valr[now];
	vall[now]=0;
	valr[now]=0;
}

void updata(int now,int l,int r,int xl,int xr)
{
	if(L[now]>=l&&R[now]<=r)
	{
		vall[now]=xl;
		valr[now]=xr;
		return;
	}
	if(vall[now])
		pushdown(now);
	if(l<=mid[now])
		updata(now<<1,l,r,xl,xr);
	if(r>mid[now])
		updata(now<<1|1,l,r,xl,xr);
}

void query(int to)
{
	int now=1;
	while(L[now]!=R[now])
	{
		if(vall[now])
			pushdown(now);
		if(to<=mid[now])
			now=(now<<1);
		else
			now=(now<<1|1);
	}
	getl=vall[now];
	getr=valr[now];
}

inline void pushit1(int l,int r)
{
	if(l==1)
		que1.push(node(r-l,l));
	else if(r==n)
		que1.push(node(r-l,r));
	else
		que1.push(node(r-l>>1,l+(r-l>>1)));
}

inline void pushit2(int l,int r)
{
	if(l==1)
		que2.push(node(r-l,l));
	if(r==n)
		que2.push(node(r-l,r));
	else
		que2.push(node(r-l>>1,l+(r-l>>1)));
}

int main()
{
	freopen("data.txt","r",stdin);
	freopen("ans1.txt","w",stdout);
	read(n);
	read(m);
	pushit1(1,n);
	node now;
	int tmp;
	build(1,1,n);
	for(int i=1,op,x,l,r;i<=m;i++)
	{
		read(op);
		read(x);
		if(op==1)
		{
			while(que2.size()&&que2.top()==que1.top())
			{
				que1.pop();
				que2.pop();
			}
			now=que1.top();
			que1.pop();
			printf("%d\n",now.pos);
			vis[now.pos]=true;
			query(now.pos);
			if(now.pos>getl)
			{
				updata(1,getl,now.pos-1,getl,now.pos-1);
				l=getl;
				r=now.pos-1;
				pushit1(l,r);
			}
			if(now.pos<getr)
			{
				updata(1,now.pos+1,getr,now.pos+1,getr);
				l=now.pos+1;
				r=getr;
				pushit1(l,r);
			}
			id[x]=now.pos;
		}
		else
		{
			tmp=id[x];
			l=tmp;
			r=tmp;
			if(l!=1&&!vis[tmp-1])
			{
				query(tmp-1);
				pushit2(getl,getr);
				l=getl;
			}
			if(r!=n&&!vis[tmp+1])
			{
				query(tmp+1);
				pushit2(getl,getr);
				r=getr;
			}
			pushit1(l,r);
			updata(1,l,r,l,r);
			vis[tmp]=false;
		}
	}
	return 0;
}

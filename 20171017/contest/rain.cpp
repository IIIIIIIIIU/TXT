#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e5+5,maxtree=maxn<<2|1;

class SegTreeType
{
	private:
		int val[maxtree];
		
		inline void pushdown(int now)
		{
			val[now<<1]+=val[now];
			val[now<<1|1]+=val[now];
			val[now]=0;
		}
		
	public:
		inline void updata(int now,int l,int r,int tl,int tr)
		{
			if(l>=tl&&r<=tr)
			{
				val[now]++;
				return;
			}
			if(val[now])
				pushdown(now);
			int mid=l+r>>1;
			if(tl<=mid)
				updata(now<<1,l,mid,tl,tr);
			if(tr>mid)
				updata(now<<1|1,mid+1,r,tl,tr);
		}
		
		void count(int now,int l,int r,int bel,int *arr,int *num)
		{
			if(l==r)
			{
				if(val[now]>num[l])
				{
					arr[l]=bel;
					num[l]=val[now];
				}
				return;
			}
			if(val[now])
				pushdown(now);
			int mid=l+r>>1;
			count(now<<1,l,mid,bel,arr,num);
			count(now<<1|1,mid+1,r,bel,arr,num);
		}
};

class SegTreeType tree[21];

struct EdgeType
{
	int v;
	
	EdgeType *next;
	
	EdgeType(){}
	
	EdgeType(int v_,EdgeType *next_)
	{
		v=v_,next=next_;
	}
};

struct EdgeType *head[maxn],*Si[maxn];

int n,m,deep[maxn],id[maxn],cnt,top[maxn],ans[maxn];
int f[maxn],size[maxn],back[maxn],ans_[maxn],lar[maxn];
int Sn[maxn],Sfa[maxn],St[maxn];

inline void read(int &now)
{
	char Cget;now=0;int if_z=1;
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

/*void FDfs(int now,int fa)
{
	f[now]=fa;
	size[now]=1;
	deep[now]=deep[fa]+1;
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
		{
			FDfs(i->v,now);
			size[now]+=size[i->v];
			if(size[i->v]>=size[lar[now]])
				lar[now]=i->v;
		}
}*/

void FDfs(int now,int fa)
{
	Sn[1]=now,Sfa[1]=fa,now=1;
	FLAG1:;
	f[Sn[now]]=Sfa[now];
	size[Sn[now]]=1;
	deep[Sn[now]]=deep[Sfa[now]]+1;
	for(Si[now]=head[Sn[now]];Si[now]!=NULL;Si[now]=Si[now]->next)
		if(Si[now]->v!=Sfa[now])
		{
			Sn[now+1]=Si[now]->v;
			Sfa[now+1]=Sn[now];
			++now;
			goto FLAG1;
			FLAG2:;
			if(size[Si[now]->v]>=size[lar[Sn[now]]])
				lar[Sn[now]]=Si[now]->v;
		}
	if(now==1) return;
	now--;
	goto FLAG2;
}

/*void DDfs(int now,int chain)
{
	id[now]=++cnt;
	back[cnt]=now;
	top[now]=chain;
	if(lar[now])
		DDfs(lar[now],chain);
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f[now]&&i->v!=lar[now])
			DDfs(i->v,i->v);
}*/

void DDfs(int now,int chain)
{
	Sn[1]=now,Sfa[1]=chain;
	now=1;
	FLAG1:;
	id[Sn[now]]=++cnt;
	back[cnt]=Sn[now];
	top[Sn[now]]=Sfa[now];
	if(lar[Sn[now]])
	{
		Sn[now+1]=lar[Sn[now]];
		Sfa[now+1]=Sfa[now];
		St[now+1]=2;
		now++;
		goto FLAG1;
		FLAG2:;
	}
	for(Si[now]=head[Sn[now]];Si[now]!=NULL;Si[now]=Si[now]->next)
		if(Si[now]->v!=f[Sn[now]]&&Si[now]->v!=lar[Sn[now]])
		{
			Sn[now+1]=Si[now]->v;
			Sfa[now+1]=Si[now]->v;
			St[now+1]=3;
			now++;
			goto FLAG1;
			FLAG3:;
		}
	if(now==1)
		return;
	if(St[now]==2)
	{
		now--;
		goto FLAG2;
	}
	now--;
	goto FLAG3;
}

void solve(int x,int y,int z)
{
	while(top[x]!=top[y])
		if(deep[top[x]]>deep[top[y]])
		{
			tree[z].updata(1,1,n,id[top[x]],id[x]);
			x=f[top[x]];
		}
		else
		{
			tree[z].updata(1,1,n,id[top[y]],id[y]);
			y=f[top[y]];
		}
	if(deep[x]>deep[y])
		std::swap(x,y);
	tree[z].updata(1,1,n,id[x],id[y]);
}

int main()
{
	freopen("rain.in","r",stdin);
	freopen("rain.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		head[i]=NULL;
	for(int i=1,u,v;i<n;i++)
	{
		read(u);
		read(v);
		head[u]=new EdgeType(v,head[u]);
		head[v]=new EdgeType(u,head[v]);
	}
	FDfs(1,0);
	DDfs(1,1);
	for(int i=1,x,y,z;i<=m;i++)
	{
		read(x);
		read(y);
		read(z);
		solve(x,y,z);
	}
	for(int i=1;i<=20;i++)
		tree[i].count(1,1,n,i,ans,ans_);
	for(int i=1;i<=n;i++)
		ans_[back[i]]=ans[i];
	for(int i=1;i<=n;i++)
		printf("%d\n",ans_[i]);
	fclose(stdin),fclose(stdout);
	return 0;
}

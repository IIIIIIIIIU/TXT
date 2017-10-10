#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1000005,BUF=52341235,INF=0x3f3f3f3f;

class SegTreeType
{
	private:
		struct SegTreeNodeType
		{
			int l,r,mid,val;

			SegTreeNodeType *lc,*rc;

			SegTreeNodeType()
			{
				l=r=mid=val=0;
				lc=rc=NULL;
			}
		};

		struct SegTreeNodeType node[maxn<<2|1];

		int tot;
	public:
		struct SegTreeNodeType *root;

		void build(SegTreeNodeType *&now,int l,int r)
		{
			now=&node[++tot];
			now->l=l,now->r=r,now->val=-INF;
			if(l==r) return;now->mid=l+r>>1;
			build(now->lc,l,now->mid);
			build(now->rc,now->mid+1,r);
		}

		inline void change(SegTreeNodeType *now,int to,int x)
		{
			if(now->l==now->r)
			{
				if(x>now->val) now->val=x;
				return;
			}
			if(to<=now->mid) change(now->lc,to,x);	
			else change(now->rc,to,x);
			now->val=(now->lc->val>now->rc->val?now->lc->val:now->rc->val);
		}

		inline int query(SegTreeNodeType *now,int l,int r)
		{
			if(now->l>=l&&now->r<=r) return now->val;
			int res=-INF;
			if(l<=now->mid) res=query(now->lc,l,r);
			if(r>now->mid) res=std::max(res,query(now->rc,l,r));
			return res;
		}
};

class SegTreeType tree[2];

char buf[BUF],*Cget=buf;

int n,k,ai[maxn],bi[maxn],size,up[maxn],down[maxn];

inline void read(int &now)
{
	now=0;while((*Cget)>'9'||(*Cget)<'0') ++Cget;
	while((*Cget)>='0'&&(*Cget)<='9')now=now*10+ *Cget -'0',++Cget;
}

int main()
{
//	freopen("data.txt","r",stdin);
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	fread(buf,1,BUF,stdin);
	read(n),read(k);
	for(int i=1;i<=n;++i) read(ai[i]),bi[i]=ai[i];
	std::sort(bi+1,bi+n+1);
	size=std::unique(bi+1,bi+n+1)-bi-1;
	for(int i=1,l,r,mid,res;i<=n;++i)
	{
		l=1,r=size;
		while(l<=r)
			if(ai[i]<=bi[mid=l+r>>1]) res=mid,r=mid-1;
			else l=mid+1;
		ai[i]=res;
	}
	for(int i=1,j=0;i<=size;++i)
	{
		while(bi[j+1]+k<=bi[i]) ++j;
		down[i]=j;
	}
	for(int i=size,j=size+1;i>=1;--i)
	{
		while(bi[j-1]-k>=bi[i]) --j;
		up[i]=j;
	}
	tree[1].build(tree[1].root,1,size);
	tree[0].build(tree[0].root,1,size);
	for(int i=1,tmp1,tmp0;i<=n;i++)
	{
		if(up[ai[i]]<=size)
			tmp1=tree[0].query(tree[0].root,up[ai[i]],size)+1;
		else tmp1=-INF;
		if(down[ai[i]]>=1)
			tmp0=tree[1].query(tree[1].root,1,down[ai[i]])+1;
		else tmp0=-INF;
		if(1>tmp1) tmp1=1;
		tree[0].change(tree[0].root,ai[i],tmp0);
		tree[1].change(tree[1].root,ai[i],tmp1);
	}
	std::cout<<std::max(tree[0].root->val,tree[1].root->val);
	fclose(stdin),fclose(stdout);
	return 0;
}

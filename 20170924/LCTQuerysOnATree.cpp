#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=300005,BUF=12341235;

using std::max;

class LinkCutTreeType
{
	private:
		struct NodeType
		{
			int maxval,sumval,BaseVal,BaseID,rev;

			struct NodeType *f,*ch[2];

			NodeType(int BaseVal_=0,int BaseID_=0)
			{
				BaseVal=BaseVal_,BaseID=BaseID_;
				maxval=sumval=BaseVal;
				ch[0]=ch[1]=f=NULL;
			}

			inline bool isroot()
			{
				if(this->f==NULL) return true;
				return this->f->ch[0]!=this&&this->f->ch[1]!=this;
			}

			inline void updata()
			{
				maxval=sumval=BaseVal;
				if(ch[1]!=NULL) maxval=max(maxval,ch[1]->maxval),sumval+=ch[1]->sumval;
				if(ch[0]!=NULL) maxval=max(maxval,ch[0]->maxval),sumval+=ch[0]->sumval;
			}

			inline void pushdown()
			{
				if(rev)
				{
					std::swap(ch[0],ch[1]);
					if(ch[0]!=NULL) ch[0]->rev^=1;
					if(ch[1]!=NULL) ch[1]->rev^=1;
					rev=0;
				}
			}

			inline void rotate()
			{
				NodeType *fa=this->f,*ffa=fa->f;int l=(fa->ch[1]==this),r=l^1;
				if(!fa->isroot()) ffa->ch[ffa->ch[1]==fa]=this;
				this->f=ffa,fa->ch[l]=this->ch[r],this->ch[r]=fa,fa->f=this;
				if(fa->ch[l]!=NULL) fa->ch[l]->f=fa;fa->updata();
			}
		};

		struct NodeType node[maxn],*Stack[maxn];

	public:
		void makeit(int key,int id)
		{
			node[id]=NodeType(key,id);
		}

		void remakeit(int key,int id)
		{
			node[id].BaseVal=key;
			node[id].updata();
		}

		void splay(int x)
		{
			NodeType *now=&node[x],*fa=now,*ffa;
			int top=0;
			Stack[++top]=now;
			while(fa->f!=NULL) Stack[++top]=fa->f,fa=fa->f;
			while(top) Stack[top--]->pushdown();
			while(!now->isroot())
			{
				fa=now->f,ffa=fa->f;
				if(!fa->isroot())
				{
					if(ffa->ch[1]==fa^fa->ch[1]==now) now->rotate();
					else fa->rotate();
				}
				now->rotate();
			}
			now->updata();
		}

		void access(int x)
		{
			for(NodeType *tmp=NULL,*now=&node[x];now!=NULL;tmp=now,now=now->f)
			{
				splay(now->BaseID);
				now->ch[1]=tmp;
				now->updata();
			}
		}

		void makeroot(int x)
		{
			access(x);
			splay(x);
			node[x].rev^=1;
		}

		void link(int x,int y)
		{
			makeroot(x);
			node[x].f=&node[y];
		}

		void makeroad(int x,int y)
		{
			makeroot(x);
			access(y);
			splay(y);
		}

		int GetMaxval(int x)
		{
			return node[x].maxval;
		}

		int GetSumval(int x)
		{
			return node[x].sumval;
		}
};

class LinkCutTreeType LCT;

int n,m,u[maxn],v[maxn];

char buf[BUF],*Cget=buf;

inline void read(int &now)
{
	now=0;int if_z=1;
	while(*(Cget)>'9'||*Cget<'0')
	{
		if(*Cget=='-')if_z=-1;
		++Cget;
	}
	while(*Cget>='0'&&*Cget<='9')now=now*10+(*Cget)-'0',++Cget;
	now*=if_z;
}

int GT ()
{
    for (; (*Cget) != 'Q' && (*Cget) != 'C'; ++ Cget);
    if (*(Cget + 1) == 'M') return 2;
    else if (*(Cget + 1) == 'S') return 1; return 3;
}

int main()
{
	freopen("data.txt","r",stdin);
	fread(Cget,1,BUF,stdin);
	srand(time(0));
	read(n);
	int tmp,l,r;
	for(int i=1;i<n;i++) read(u[i]),read(v[i]);
	for(int i=1;i<=n;i++) read(tmp),LCT.makeit(tmp,i);
	for(int i=1;i<n;i++) LCT.link(u[i],v[i]);
	read(m);
	int op;
	for(int i=1;i<=m;i++)
	{
		if(i%50==0)
		{
			LCT.makeroot(rand()%n+1);
		}
		op=GT(),read(l),read(r);
		if(op==3) LCT.makeroot(l),LCT.remakeit(r,l);
		else if(op==1) LCT.makeroad(l,r),printf("%d\n",LCT.GetSumval(r));
		else LCT.makeroad(l,r),printf("%d\n",LCT.GetMaxval(r));
	}
	return 0;
}

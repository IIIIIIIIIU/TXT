#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=5e5+5;
const int noSuf=2147483647;
const int noPre=-2147483647;

class SplayTreeType
{
	private:
		struct SplayTreeNodeType
		{
			int w,key,size;
			
			SplayTreeNodeType *ch[2],*f;
			
			SplayTreeNodeType()
			{
				w=0;
				key=0;
				size=0;
				f=NULL;
				ch[0]=NULL;
				ch[1]=NULL;
			}
			
			SplayTreeNodeType(int key_,SplayTreeNodeType *f_)
			{
				w=1;
				f=f_;
				size=1;
				key=key_;
				ch[0]=NULL;
				ch[1]=NULL;
			}
			
			inline void updata()
			{
				size=w;
				if(ch[0]!=NULL)
					size+=ch[0]->size;
				if(ch[1]!=NULL)
					size+=ch[1]->size;
			}
			
			inline void rotate()
			{
				SplayTreeNodeType *fa=f,*ffa=f->f;
				int l=(fa->ch[1]==this),r=(l^1);
				if(ffa!=NULL)
					ffa->ch[ffa->ch[1]==fa]=this;
				this->f=ffa;
				fa->ch[l]=this->ch[r];
				this->ch[r]=fa;
				fa->f=this;
				if(fa->ch[l]!=NULL)
					fa->ch[l]->f=fa;
				fa->updata();
			}
			
			void splay(SplayTreeNodeType *&where)
			{
				SplayTreeNodeType *fa,*ffa;
				while(this->f!=NULL)
				{
					fa=this->f;
					ffa=fa->f;
					if(ffa!=NULL)
					{
						if(ffa->ch[1]==fa^fa->ch[1]==this)
							this->rotate();
						else fa->rotate();
					}
					this->rotate();
				}
				this->updata();
				where=this;
			}
		};
		
		struct SplayTreeNodeType *root;
	public:
		SplayTreeType()
		{
			root=NULL;
		}
		
		void insert(int x)
		{
			if(root==NULL)
			{
				root=new SplayTreeNodeType(x,NULL);
				return;
			}
			SplayTreeNodeType *now=root,*fa=NULL;
			while(true)
			{
				if(now->key==x)
				{
					now->w++;
					now->size++;
					now->splay(root);
					return;
				}
				fa=now;
				if(x<now->key)
					now=now->ch[0];
				else
					now=now->ch[1];
				if(now==NULL)
				{
					fa->ch[x>fa->key]=new SplayTreeNodeType(x,fa);
					fa->ch[x>fa->key]->splay(root);
					return;
				}
			}
		}
		
		int delete_root()
		{
			int res;
			if(root->ch[0]==NULL&&root->ch[1]==NULL)
			{
				res=root->key;
				delete root;
				root=NULL;
				return res;
			}
			SplayTreeNodeType *now=root;
			if(now->w>1)
			{
				now->w--;
				now->size--;
				return now->key;
			}
			if(now->ch[1]!=NULL&&now->ch[0]!=NULL)
			{
				SplayTreeNodeType *tmp=root->ch[1];
				root=root->ch[0];
				res=now->key;
				delete now;
				root->f=NULL;
				tmp->f=NULL;
				now=root;
				while(now->ch[1]!=NULL)
					now=now->ch[1];
				now->splay(root);
				now->ch[1]=tmp;
				tmp->f=now;
				root=now;
				root->updata();
			}
			else if(now->ch[1]!=NULL)
			{
				root=now->ch[1];
				res=now->key;
				delete now;
				root->f=NULL;
			}
			else
			{
				root=now->ch[0];
				res=now->key;
				delete now;
				root->f=NULL;
			}
			return res;
		}
		
		int get_pre(int x)
		{
			insert(x);
			if(root->ch[0]==NULL)
			{
				delete_root();
				return noPre;
			}
			SplayTreeNodeType *now=root->ch[0];
			while(now->ch[1]!=NULL)
				now=now->ch[1];
			delete_root();
			now->splay(root);
			return now->key;
		}
		
		int get_suf(int x)
		{
			insert(x);
			if(root->ch[1]==NULL)
			{
				delete_root();
				return noSuf;
			}
			SplayTreeNodeType *now=root->ch[1];
			while(now->ch[0]!=NULL)
				now=now->ch[0];
			delete_root();
			now->splay(root);
			return now->key;
		}
		
		int ArcRank(int x)
		{
			SplayTreeNodeType *now=root;
			while(true)
			{
				if(now->ch[0]!=NULL&&now->ch[0]->size>=x)
					now=now->ch[0];
				else
				{
					if(now->ch[0]!=NULL)
						x-=now->ch[0]->size;
					if(x<=now->w)
					{
						now->splay(root);
						return now->key;
					}
					x-=now->w;
					now=now->ch[1];
				}
			}
		}
		
		int Rank(int x)
		{
			SplayTreeNodeType *now=root;
			int res=0;
			while(true)
			{
				if(now==NULL)
					return noPre;
				if(x==now->key)
				{
					if(now->ch[0]!=NULL)
						res+=now->ch[0]->size;
					now->splay(root);
					return res+1;
				}
				if(x<now->key)
					now=now->ch[0];
				else
				{
					res+=now->size-now->ch[1]->size;
					now=now->ch[1];
				}
			}
		}
		
		bool find(int x)
		{
			SplayTreeNodeType *now=root;
			while(true)
			{
				if(now==NULL)
					return false;
				if(x==now->key)
				{
					now->splay(root);
					return true;
				}
				if(x<now->key)
					now=now->ch[0];
				else
					now=now->ch[1];
			}
		}
};

class SplayTreeType splay;

struct EdgeType
{
	int v,w,x;
	
	EdgeType *next;
	
	EdgeType(){}
	
	EdgeType(int v_,int w_,int x_,EdgeType *next_)
	{
		v=v_;
		w=w_;
		x=x_;
		next=next_;
	}
};

struct EdgeType *head[maxn];

int n,out[maxn];

bool need[maxn];

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

void dfs(int now,int fa)
{
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=fa)
		{
			if(i->w==1)
			{
				splay.insert(i->x);
				dfs(i->v,now);
				splay.find(i->x);
				splay.delete_root();
			}
			if(i->w==2)
			{
				bool can=splay.find(i->x);
				if(can)
					i->x=splay.delete_root();
				dfs(i->v,now);
				if(can)
					splay.insert(i->x);
			}
			if(i->w==3)
			{
				splay.insert(i->x);
				out[i->v]=splay.Rank(i->x);
				splay.delete_root();
				dfs(i->v,now);
			}
			if(i->w==4)
			{
				out[i->v]=splay.ArcRank(i->x);
				dfs(i->v,now);
			}
			if(i->w==5)
			{
				out[i->v]=splay.get_pre(i->x);
				dfs(i->v,now);
			}
			if(i->w==6)
			{
				out[i->v]=splay.get_suf(i->x);
				dfs(i->v,now);
			}
		}
}

int main()
{
	read(n);
	head[0]=NULL;
	for(int i=1,v,op,x;i<=n;i++)
	{
		head[i]=NULL;
		read(v);
		read(op);
		read(x);
		head[v]=new EdgeType(i,op,x,head[v]);
		if(op>2)
			need[i]=true;
	}
	dfs(0,-1);
	for(int i=1;i<=n;i++)
		if(need[i])
			printf("%d\n",out[i]);
	return 0;
}

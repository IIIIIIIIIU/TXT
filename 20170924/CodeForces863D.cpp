#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=400005;

struct NodeType
{
	int key,size;

	bool rev;

	NodeType *f,*ch[2];

	NodeType()
	{
		size=rev=0;
		f=ch[0]=ch[1]=NULL;
	}

	inline void updata()
	{
		size=1;
		if(ch[0]!=NULL) size+=ch[0]->size;
		if(ch[1]!=NULL) size+=ch[1]->size;
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
		if(fa->f!=NULL) ffa->ch[ffa->ch[1]==fa]=this;
		fa->ch[l]=this->ch[r],this->ch[r]=fa,this->f=ffa,fa->f=this;
		if(fa->ch[l]!=NULL) fa->ch[l]->f=fa;fa->updata();
	}
};

struct NodeType *root,*Stack[maxn];

int ai[maxn],n,m,q;

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

inline void splay(NodeType *now,bool OperationType)
{
	NodeType *Pos,*fa=now,*ffa;
	int top=0;
	Stack[++top]=fa;
	while(fa->f!=NULL) Stack[++top]=fa->f,fa=fa->f;
	while(top) Stack[top--]->pushdown();
	if(OperationType) Pos=NULL;
	else Pos=root;
	while(now->f!=Pos)
	{
		fa=now->f,ffa=fa->f;
		if(ffa!=Pos)
		{
			if((ffa->ch[1]==fa)^(fa->ch[1]==now)) now->rotate();
			else fa->rotate();
		}
		now->rotate();
	}
	if(OperationType) root=now;
}

void Build(NodeType *&now,int l,int r)
{
	int mid=l+r>>1;
	now->key=ai[mid];
	if(l<mid)
	{
		now->ch[0]=new NodeType;
		now->ch[0]->f=now;
		Build(now->ch[0],l,mid-1);
	}
	if(mid<r)
	{
		now->ch[1]=new NodeType;
		now->ch[1]->f=now;
		Build(now->ch[1],mid+1,r);
	}
	now->updata();
}

void find(int x,bool OperationType)
{
	NodeType *now=root;
	while(1)
	{
		now->pushdown();
		if(now->ch[0]!=NULL&&now->ch[0]->size>=x) now=now->ch[0];
		else
		{
			if(now->ch[0]!=NULL) x-=now->ch[0]->size;
			if(x==1)
			{
				splay(now,OperationType);
				return;
			}
			--x,now=now->ch[1];
		}
	}
}

int Throw()
{
	int GetRecoverKey=root->key;
	NodeType *now=root;
	now->pushdown();
	if(now->ch[1]!=NULL&&now->ch[0]!=NULL)
	{
		NodeType *tmp=now->ch[1];
		now=now->ch[0];
		now->f=NULL;
		while(1)
		{
			now->pushdown();
			if(now->ch[1]!=NULL) now=now->ch[1];
			else break;
		}
		splay(now,true);
		root->ch[1]=tmp;
		tmp->f=root;
		root->updata();
	}
	else if(now->ch[1]!=NULL) root=root->ch[1],root->f=NULL;
	else if(now->ch[0]!=NULL) root=root->ch[0],root->f=NULL;
	return GetRecoverKey;
}

void insert(int key,int pos)
{
	find(pos,true);
	NodeType *tmp=root->ch[1];
	root->ch[1]=new NodeType;
	root->ch[1]->key=key;
	root->ch[1]->f=root;
	root->ch[1]->ch[1]=tmp;
	tmp->f=root->ch[1];
	root->ch[1]->updata();
	root->updata();
}

void rever(int l,int r)
{
	find(l,true),find(r+2,false);
	root->ch[1]->ch[0]->rev^=1;
}

int main()
{
//	freopen("data.txt","r",stdin);
	read(n),read(q),read(m);
	for(int i=2;i<=n+1;i++) read(ai[i]);
	root=new NodeType,Build(root,1,n+2);
	int op,l,r;
	for(int i=1;i<=q;i++)
	{
//		printf("%d\n",i);
//		if(i==117)
//		{
//			int sdaw=0;
//		}
		read(op),read(l),read(r);
		if(op==1)
		{
			find(r+1,true);
			int tmp=Throw();
			insert(tmp,l);
		}
		else rever(l,r);
	}
	while(m--)
	{
		read(op);
		find(op+1,true);
		printf("%d ",root->key);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=205;

struct EdgeType
{
	int v,w;
	
	EdgeType *next;
	
	EdgeType() {}
	
	EdgeType(int v_,int w_,EdgeType *next_)
	{
		v=v_,w=w_,next=next_;
	}
};

struct EdgeType *head[maxn];

int n,m,ci[maxn],ui[maxn],que[maxn],deg[maxn];

inline void read(int &now)
{
	char Cget;now=0;int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')
		if(Cget=='-') if_z=-1;
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
	now*=if_z;
}

int main()
{
	read(n),read(m);
	int h=0,tail=0;
	for(int i=1;i<=n;i++)
	{
		head[i]=NULL;
		read(ci[i]),read(ui[i]);
		if(ci[i])
			que[tail++]=i;
		if(!ci[i])
			ci[i]-=ui[i];
	}
	for(int i=1,u,v,w;i<=m;i++)
	{
		read(u),read(v),read(w),deg[v]++;
		head[u]=new EdgeType(v,w,head[u]);
	}
	while(h<tail)
	{
		int now=que[h++];
		if(ci[now]<=0)
			continue;
		for(EdgeType *i=head[now];i!=NULL;i=i->next)
		{
			ci[i->v]+=i->w*ci[now];
			if(!(--deg[i->v]))
				que[tail++]=i->v;
		}
	}
	bool DID=true;
	for(int i=1;i<=n;i++)
		if(head[i]==NULL&&ci[i]>0)
		{
			DID=false;
			printf("%d %d\n",i,ci[i]);
		}
	if(DID)
		puts("NULL");
	return 0;
}

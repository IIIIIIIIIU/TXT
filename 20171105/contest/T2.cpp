#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=2005;
const int maxnm=1e5+5;
const int dx[9]={0,-1,-1,-1,0,1,1,1,0};
const int dy[9]={0,-1,0,1,1,1,0,-1,-1};

struct node
{
	int u,v,w;
	
	bool operator<(const node &tmp)const
	{
		return w>tmp.w;
	}
	
	node(){}
	
	node(int u_,int v_,int w_)
	{
		u=u_;
		v=v_;
		w=w_;
	}
};

struct node edge[maxnm*8];

struct EdgeType
{
	int v;
	
	EdgeType *next;
	
	EdgeType(){}
	
	EdgeType(int v_,EdgeType *next_)
	{
		v=v_;
		next=next_;
	}
};

struct EdgeType *head[maxnm];

struct NODE
{
	int h,w;
	
	NODE(){}
	
	NODE(int h_,int w_)
	{
		h=h_;
		w=w_;
	}
	
	bool operator<(const NODE &tmp)const
	{
		if(h==tmp.h)
			return w>tmp.w;
		return h>tmp.h;
	}
};

struct NODE ans[maxnm];

int n,m,ai[maxn][maxn],f[maxnm],size[maxnm],val[maxnm],num;
int id[maxn][maxn],cnt,quex[maxnm],quey[maxnm],Base[maxnm];
int cnt2,Max[maxnm],ansnum;

bool can[maxnm];

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

void bfs(int sx,int sy)
{
	++cnt;
	head[cnt]=NULL;
	can[cnt]=true;
	f[cnt]=cnt;
	int h=0,tail=1,nowx,nowy;
	quex[h]=sx;
	quey[h]=sy;
	id[sx][sy]=cnt;
	while(h<tail)
	{
		nowx=quex[h];
		nowy=quey[h++];
		for(int i=1,x,y;i<=8;i++)
		{
			x=nowx+dx[i];
			y=nowy+dy[i];
			if(x>0&&x<=n&&y>0&&y<=m)
			{
				if(ai[x][y]>ai[sx][sy])
					can[cnt]=false;
				if(ai[x][y]==ai[sx][sy]&&!id[x][y])
				{
					id[x][y]=cnt;
					quex[tail]=x;
					quey[tail++]=y;
				}
			}
		}
	}
	if(can[cnt])
	{
		size[cnt]=1;
		cnt2++;
		Max[cnt]=ai[sx][sy];
		Base[cnt]=ai[sx][sy];
	}
	else
		Max[cnt]=-1;
	val[cnt]=0;
}

int find(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=find(f[x]);
}

bool merge(int u,int v,int w)
{
	int x=find(u);
	int y=find(v);
	if(x==y)
		return false;
		head[y]=new EdgeType(x,head[y]);
		head[x]=new EdgeType(y,head[x]);
	if(Max[x]==Max[y])
	{
		f[y]=x;
		size[x]+=size[y];
	}
	else if(Max[x]>Max[y])
	{
		val[y]=w;
		f[y]=x;
		size[x]+=size[y];
	}
	else
	{
		val[x]=w;
		f[x]=y;
		size[y]+=size[x];
	}
	if(size[x]==cnt2||size[y]==cnt2)
		return true;
	return false;
}

void dfs(int now,int f,int w)
{
	if(can[now])
		ans[++ansnum]=NODE(Base[now],w);
	for(EdgeType *i=head[now];i!=NULL;i=i->next)
		if(i->v!=f)
			dfs(i->v,now,std::max(w,val[i->v]));
}

int main()
{
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		for(int v=1;v<=m;v++)
			read(ai[i][v]);
	for(int i=1;i<=n;i++)
		for(int v=1;v<=m;v++)
			if(!id[i][v])
				bfs(i,v);
	for(int i=1,v,e,x,y;i<=n;i++)
		for(v=1;v<=m;v++)
			for(e=1;e<=8;e++)
			{
				x=i+dx[e];
				y=v+dy[e];
				if(x>0&&x<=n&&y>0&&y<=m&&id[x][y]<id[i][v])
					edge[++num]=node(id[i][v],id[x][y],std::min(ai[i][v],ai[x][y]));
			}
	std::sort(edge+1,edge+num+1);
	for(int i=1;i<=num;i++)
		if(merge(edge[i].u,edge[i].v,edge[i].w))
			break;
	for(int i=1;i<=cnt;i++)
		if(size[i]==cnt2&&f[i]==i)
		{
			dfs(i,0,0);
			break;
		}
	std::sort(ans+1,ans+ansnum+1);
	printf("%d\n",ansnum);
	for(int i=1;i<=ansnum;i++)
		printf("%d %d\n",ans[i].h,ans[i].w);
	return 0;
}

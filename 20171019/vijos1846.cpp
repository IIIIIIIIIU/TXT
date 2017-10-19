#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int INF=0x3f3f3f3f;
const int dx[5]={0,-1,0,1,0};
const int dy[5]={0,0,1,0,-1};

struct EdgeType
{
	int v,w;
	
	EdgeType *next;
	
	EdgeType(int v_,int w_,EdgeType *next_)
	{
		v=v_;
		w=w_;
		next=next_;
	}
};

struct EdgeType *head[905*4+5];

int n,m,q,map[35][35],cnt,id[35][35][5],dis[35][35];
int quex[905],quey[905],que[905*905*4],dist[905*4];

bool vis[905*4];

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
	for(int i=1;i<=n;i++)
		for(int v=1;v<=m;v++)
			dis[i][v]=INF;
	dis[sx][sy]=0;
	int h=0,tail=1;
	int nowx,nowy;
	quex[0]=sx;
	quey[0]=sy;
	while(h<tail)
	{
		nowx=quex[h];
		nowy=quey[h++];
		for(int i=1,x,y;i<=4;i++)
		{
			x=nowx+dx[i];
			y=nowy+dy[i];
			if(map[x][y]&&dis[x][y]==INF)
			{
				dis[x][y]=dis[nowx][nowy]+1;
				quex[tail]=x;
				quey[tail++]=y;
			}
		}
	}
}

int main()
{
//	freopen("PuzzleNOIP2013.in","r",stdin);
//	freopen("PuzzleNOIP2013.out","w",stdout);
//	freopen("data.txt","r",stdin);
//	freopen("out1.txt","w",stdout);
	read(n);
	read(m);
	read(q);
	for(int i=1;i<=n;i++)
		for(int v=1;v<=m;v++)
			read(map[i][v]);
	for(int i=1;i<=n;i++)
		for(int v=1;v<=m;v++)
			if(map[i][v])
			{
				for(int e=1,x,y;e<=4;e++)
				{
					x=i+dx[e];
					y=v+dy[e];
					if(x>0&&x<=n&&y>0&&y<=m&&map[x][y])
						id[i][v][e]=++cnt;
				}
			}
	for(int i=1;i<=cnt;i++)
		head[i]=NULL;
	for(int i=1;i<=n;i++)
		for(int v=1;v<=m;v++)
			if(map[i][v])
			{
				map[i][v]=0;
				for(int e=1,x,y;e<=4;e++)
				{
					x=i+dx[e];
					y=v+dy[e];
					if(map[x][y])
					{
						bfs(x,y);
						for(int r=1,X,Y;r<=4;r++)
							if(r!=e)
							{
								X=i+dx[r];
								Y=v+dy[r];
								if(X>0&&X<=n&&Y>0&&Y<=m&&map[X][Y]&&dis[X][Y]<INF)
									head[id[i][v][e]]=new EdgeType(id[i][v][r],dis[X][Y],head[id[i][v][e]]);
							}
					}
				}
				map[i][v]=1;
			}
	for(int i=1;i<=n;i++)
		for(int v=1;v<=m;v++)
			for(int e=1,x,y;e<=4;e++)
			{
				x=i+dx[e];
				y=v+dy[e];
				if(x>0&&x<=n&&y>0&&y<=m&&map[x][y])
				{
					if(e==1)
						head[id[i][v][1]]=new EdgeType(id[x][y][3],1,head[id[i][v][1]]);
					if(e==2)
						head[id[i][v][2]]=new EdgeType(id[x][y][4],1,head[id[i][v][2]]);
					if(e==3)
						head[id[i][v][3]]=new EdgeType(id[x][y][1],1,head[id[i][v][3]]);
					if(e==4)
						head[id[i][v][4]]=new EdgeType(id[x][y][2],1,head[id[i][v][4]]);
				}
			}
	for(int i=1,ex,ey,sx,sy,tx,ty;i<=q;i++)
	{
		read(ex);
		read(ey);
		read(sx);
		read(sy);
		read(tx);
		read(ty);
		if(sx==tx&&sy==ty)
		{
			printf("0\n");
			continue;
		}
		map[sx][sy]=0;
		bfs(ex,ey);
		map[sx][sy]=1;
		for(int e=1;e<=cnt;e++)
		{
			dist[e]=INF;
			vis[e]=false;
		}
		int h=0,tail=0,now;
		for(int e=1,x,y;e<=4;e++)
		{
			x=sx+dx[e];
			y=sy+dy[e];
			if(x>0&&x<=n&&y>0&&y<=m&&map[x][y]&&dis[x][y]<INF)
			{
				vis[id[sx][sy][e]]=true;
				que[tail++]=id[sx][sy][e];
				dist[id[sx][sy][e]]=dis[x][y];
			}
		}
		EdgeType *e;
		while(h<tail)
		{
			now=que[h++];
			vis[now]=false;
			for(e=head[now];e!=NULL;e=e->next)
				if(dist[e->v]>dist[now]+e->w)
				{
					dist[e->v]=dist[now]+e->w;
					if(!vis[e->v])
					{
						vis[e->v]=true;
						que[tail++]=e->v;
					}
				}
		}
		int ans=INF;
		for(int v=1,x,y;v<=4;v++)
		{
			x=dx[v]+tx;
			y=dy[v]+ty;
			if(x>0&&x<=n&&y>0&&y<m&&map[x][y])
				ans=std::min(ans,dist[id[tx][ty][v]]);
		}
		if(ans==INF)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define turn(i,j) ((i)-1)*m+(j)

const int INF=0x3f3f3f3f;

int n,m,k,sx,sy,ex,ey,dis[1005][1005];
int quex[1000005],quey[1000005];

int faU[1000001],faD[1000001],faL[1000001],faR[1000001];

char map[1005][1005];

int find(int fa[1000001],int i)
{
	return fa[i]==i ? i : fa[i]=find(fa,fa[i]);
}

void unionn(int i,int j)
{
	int k=turn(i,j);
	if(i!=1) faU[k]=find(faU,turn(i-1,j));
	else faU[k]=0;
	if(i!=n) faD[k]=find(faD,turn(i+1,j));
	else faD[k]=0;
	if(j!=1) faL[k]=find(faL,turn(i,j-1));
	else faL[k]=0;
	if(j!=m) faR[k]=find(faR,turn(i,j+1));
	else faR[k]=0;
}

int bfs()
{
	for(int i=1;i<=n;i++)
		for(int v=1;v<=m;v++)
			dis[i][v]=INF;
	if(map[sx][sy]=='#'||map[ex][ey]=='#')
		return -1;
	dis[sx][sy]=0;
	int h=0,tail=1;
	quex[h]=sx;
	quey[h]=sy;
	unionn(sx,sy);
	int nowx,nowy;
	while(h<tail)
	{
		nowx=quex[h];
		nowy=quey[h++];
		for(int i=1,x=nowx,y=nowy;i<=k;i++)
		{
			y=find(faR,turn(x,y));
			if(!y) break;
			y%=m; if(!y) y=m;
			if(y-nowy>k) break;
			if(map[x][y]=='#') break;
			dis[x][y]=dis[nowx][nowy]+1;
			unionn(x,y);
			quex[tail]=x;
			quey[tail++]=y;
		}
		for(int i=1,x=nowx,y=nowy;i<=k;i++)
		{
			y=find(faL,turn(x,y));
			if(!y) break;
			y%=m; if(!y) y=m;
			if(nowy-y>k) break;
			if(map[x][y]=='#') break;
			dis[x][y]=dis[nowx][nowy]+1;
			unionn(x,y);
			quex[tail]=x;
			quey[tail++]=y;
		}
		for(int i=1,x=nowx,y=nowy;i<=k;i++)
		{
			x=find(faD,turn(x,y));
			if(!x) break;
			x=(x-1)/m+1;
			if(x-nowx>k) break;
			if(map[x][y]=='#') break;
			if(dis[x][y]!=INF) continue;
			dis[x][y]=dis[nowx][nowy]+1;
			unionn(x,y);
			quex[tail]=x;
			quey[tail++]=y;
		}
		for(int i=1,x=nowx,y=nowy;i<=k;i++)
		{
			x=find(faU,turn(x,y));
			if(!x) break;
			x=(x-1)/m+1;
			if(nowx-x>k) break;
			if(map[x][y]=='#') break;
			if(dis[x][y]!=INF) continue;
			dis[x][y]=dis[nowx][nowy]+1;
			unionn(x,y);
			quex[tail]=x;
			quey[tail++]=y;
		}
	}
	if(dis[ex][ey]==INF)
		return -1;
	return dis[ex][ey];
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	int k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			k=turn(i,j);
			faU[k]=faD[k]=faL[k]=faR[k]=k;
		}
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	std::cout<<bfs();
	return 0;
}

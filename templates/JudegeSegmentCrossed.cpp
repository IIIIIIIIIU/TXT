#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef double real;
typedef long long ll;

const int N=605;

int n,m,k,p[N][2][2],pi[N][2],cnt;

real val[N][N];
/**/
ll c_prod(int a,int b,int c,int d)
{
	return 1LL * a * d - 1LL * b * c;
}

bool cross(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	return c_prod(x3-x1,y3-y1 , x4-x1,y4-y1) * c_prod(x3-x2,y3-y2 , x4-x2,y4-y2) < 0
	&& c_prod(x1-x3,y1-y3 , x2-x3,y2-y3) * c_prod(x1-x4,y1-y4 , x2-x4,y2-y4) < 0 ;
}
/**/
void S(int x,int y){
	for(int i=1;i<=k;i++){
		if(cross(pi[x][0],pi[x][1],pi[y][0],pi[y][1],p[i][0][0],p[i][0][1],p[i][1][0],p[i][1][1]))
			return;
	}
	val[x][y]=std::sqrt((pi[x][0]-pi[y][0])*(pi[x][0]-pi[y][0])+(pi[x][1]-pi[y][1])*(pi[x][1]-pi[y][1]));
	val[y][x]=val[x][y];
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d%d%d",&p[i][0][0],&p[i][0][1],&p[i][1][0],&p[i][1][1]);
		++cnt;
		pi[cnt][0]=p[i][0][0];
		pi[cnt][1]=p[i][0][1];
		++cnt;
		pi[cnt][0]=p[i][1][0];
		pi[cnt][1]=p[i][1][1];
	}
	++cnt;
	scanf("%d%d",&pi[cnt][0],&pi[cnt][1]);
	++cnt;
	scanf("%d%d",&pi[cnt][0],&pi[cnt][1]);
	for(int i=1;i<=cnt;i++)
		for(int v=1;v<=cnt;v++)
			val[i][v]=-1;
	for(int i=1;i<=cnt;i++)
		for(int v=i+1;v<=cnt;v++)
			S(i,v);
	for(int e=1;e<=cnt;e++){
		for(int v=1;v<=cnt;v++){
			if(val[v][e]<0)
				continue;
			for(int i=1;i<=cnt;i++){
				if(val[e][i]<0)
					continue;
				if(val[i][v]<0||val[i][e]+val[e][v]<val[i][v])
					val[i][v]=val[i][e]+val[e][v];
			}
		}
	}
	printf("%.4lf\n",val[cnt-1][cnt]);
	return 0;
}

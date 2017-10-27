#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int xs,ys,xt,yt;
	scanf("%d%d%d%d",&xs,&ys,&xt,&yt);
	int u=max(ys,yt+1);
	int d=min(ys,yt-1);
	int l=min(xs,xt-1);
	int r=max(xs,xt+1);
	printf("%d",(u-d)*2+(r-l)*2);
}

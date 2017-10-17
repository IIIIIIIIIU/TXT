#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=50005;

int n,ch[maxn][2],C[maxn<<1],ans,seq[maxn],cnt;

bool vis[maxn];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n);
	ans=n;
	int tmp;
	bool can;
	for(int i=1;i<=n;i++)
	{
		for(int e=1;e<=2;e++)
		{
			can=false;
			read(tmp);
			for(int v=0;v<2;v++)
			{
				if(ch[i][v]==tmp)
				{
					can=true;
					break;
				}
				if(!ch[i][v])
				{
					ch[i][v]=tmp;
					can=true;
					break;
				}
			}
			if(!can)
			{
				puts("-1");
				return 0;
			}
		}
	}
	int now=1,last=0,next,cur=n;
	for(int i=1;i<=n;i++)
	{
		seq[++cnt]=now;
		cur-=(!vis[now]);
		vis[now]=true;
		if(ch[now][0]!=last)
			next=ch[now][0];
		if(ch[now][1]!=last)
			next=ch[now][1];
		last=now,now=next;
	}
	if(cur)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		C[(i-seq[i]+n)%n]++;
	for(int i=0;i<n;i++)
		ans=std::min(ans,n-C[i]);
	for(int l=1,r=n;l<r;l++,r--)
		std::swap(seq[l],seq[r]);
	memset(C,0,sizeof(C));
	for(int i=1;i<=n;i++)
		C[(seq[i]-i+n)%n]++;
	for(int i=0;i<=n;i++)
		ans=std::min(ans,n-C[i]);
	std::cout<<ans;
	return 0;
}

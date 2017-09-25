#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=300005;

int n,ai[maxn],bi[maxn],ci[maxn],cnt,size,ans,vis[maxn];

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("ans1.txt","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(ai[i]),bi[ai[i]]++;
		if(bi[ai[i]]>1) cnt++;
	}
	ans=cnt;
	for(int i=1;i<=n;i++)
		if(!bi[i]) ci[++size]=i;
	int h=1;
	for(int i=1;i<=n;i++)
		if(bi[ai[i]]>1)
		{
			if(ai[i]>ci[h]||vis[ai[i]])
			{
				bi[ai[i]]--;
				ai[i]=ci[h++];
			}
			else vis[ai[i]]=true;
		}
	h=size;
	for(int i=n;i>=1;i--)
	{
		if(bi[ai[i]]>1)
		{
			bi[ai[i]]--;
			ai[i]=ci[h--];
			vis[i]=true;
		}
	}
//	h=1;
//	for(int i=1;i<=n;i++) if(vis[i]) ai[i]=ci[h++];
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",ai[i]);
	return 0;
}

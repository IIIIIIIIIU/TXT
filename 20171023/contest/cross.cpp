#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e5+5;

int n,last[maxn],ai[maxn],ans;

char str[maxn];

bool vis[maxn];

int main()
{
//	freopen("data.txt","r",stdin);
	freopen("cross.in","r",stdin);
	freopen("cross.out","w",stdout);
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
		ai[i]=str[i]-'a'+1;
	for(int i=1;i<=26;i++)
	{
		int count=0,has=0;
		for(int v=1;v<=n;v++)
		{
			vis[v]=false;
			if(ai[v]==i)
			{
				has^=1;
				count=v;
				continue;
			}
			if(has)
				vis[v]=true;
			else
				vis[v]=false;
			if(vis[v])
			{
				if(last[ai[v]])
				{
					if(last[ai[v]]<count)
					{
						if(vis[last[ai[v]]])
							ans+=2;
						else
							ans++;
//						printf("%d %d\n",i,v);
					}
					last[ai[v]]=0;
				}
				else
					last[ai[v]]=v;
			}
			else
			{
				if(last[ai[v]])
				{
					if(vis[last[ai[v]]])
					{
						ans++;
//						printf("%d %d\n",i,v);
					}
					last[ai[v]]=0;
				}
				else
					last[ai[v]]=v;
			}
		}
	}
	std::cout<<(ans>>1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=55;

struct node
{
	int id,key;
	
	bool operator<(const node &tmp)const
	{
		if(key==tmp.key)
			return id<tmp.id;
		return key>tmp.key;
	}
};

struct node ai[maxn];

int n;

char str[maxn];

int main()
{
	freopen("soccer.in","r",stdin);
	freopen("soccer.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		ai[i].id=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int v=1;v<=n;v++)
			if(i==v)
				continue;
			else
			{
				if(str[v]=='W')
					ai[i].key+=3;
				else if(str[v]=='D')
				{
					ai[i].key++;
					ai[v].key++;
				}
				else
					ai[v].key+=3;
			}
	}
	std::sort(ai+1,ai+n+1);
	int tmp=ai[1].key;
	for(int i=1;i<=n;i++)
		if(ai[i].key==tmp)
			printf("%d ",ai[i].id);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

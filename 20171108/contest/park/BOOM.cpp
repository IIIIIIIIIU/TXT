#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e6+5;

int n,id[maxn],has[maxn],m;

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

int get(int now)
{
	int res=0x3f3f3f3f;
	if(now!=1)
	{
		int k=0;
		for(int i=now-1;i>=1;i--)
			if(!has[i])
				k++;
			else
				break;
		res=std::min(res,k);
	}
	if(now!=n)
	{
		int k=0;
		for(int i=now+1;i<=n;i++)
			if(!has[i])
				k++;
			else
				break;
		res=std::min(res,k);
	}
	return res;
}

int main()
{
	freopen("data.txt","r",stdin);
	freopen("ans2.txt","w",stdout);
	read(n);
	read(m);
	int op,x;
	for(int i=1;i<=m;i++)
	{
		read(op);
		read(x);
		if(op==1)
		{
			int tmp=-1,d=0,t;
			for(int i=1;i<=n;i++)
				if(!has[i]&&(t=get(i))>tmp)
				{
					d=i;
					tmp=t;
				}
			printf("%d\n",d);
			has[d]=x;
			id[x]=d;
		}
		else
			has[id[x]]=0;
	}
	return 0;
}

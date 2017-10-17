#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=1e5+5;

int n,m,q,u,v,t,ai[maxn];

ll C=0;

std::queue<ll>que1,que2,que3;

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

inline ll get()
{
	int tmp=0;
	ll res=-1;
	if(que1.size()&&que1.front()+C>res)
	{
		res=C+que1.front();
		tmp=1;
	}
	if(que2.size()&&que2.front()+C>res)
	{
		res=C+que2.front();
		tmp=2;
	}
	if(que3.size()&&que3.front()+C>res)
	{
		res=C+que3.front();
		tmp=3;
	}
	if(tmp==1)
		que1.pop();
	if(tmp==2)
		que2.pop();
	if(tmp==3)
		que3.pop();
	return res;
}

int main()
{
	read(n);
	read(m);
	read(q);
	read(u);
	read(v);
	read(t);
	for(int	i=1;i<=n;i++)
		read(ai[i]);
	std::sort(ai+1,ai+n+1);
	for(int i=n;i>=1;i--)
		que1.push(ai[i]);
	ll now,tmp;
	for(int i=1;i<=m;i++)
	{
		tmp=get();
		C+=q;
		if(i%t==0)
			printf("%lld ",tmp);
		que2.push(tmp*u/v-C);
		que3.push(tmp-tmp*u/v-C);
	}
	puts("");
	for(int i=1;i<=n+m;i++)
	{
		tmp=get();
		if(i%t==0)
			printf("%lld ",tmp);
	}
	return 0;
}

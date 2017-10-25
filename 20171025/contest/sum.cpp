#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef unsigned long long ll;

const int maxn=1e5+5;

int n,block_size,num,bel[maxn],L[maxn],R[maxn],ai[maxn];
int val[400][maxn],funcL[maxn],funcR[maxn],m;

ll count[maxn],tree[maxn];

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

#define lowbit(x) (x&(-x))

inline void add(int to,int x)
{
	while(to<=n)
	{
		tree[to]+=x;
		to+=lowbit(to);
	}
}

inline void minus(int to,int x)
{
	while(to<=n)
	{
		tree[to]-=x;
		to+=lowbit(to);
	}
}

inline ll query(int l,int r)
{
	ll res=0;
	l--;
	while(r)
	{
		res+=tree[r];
		r-=lowbit(r);
	}
	while(l)
	{
		res-=tree[l];
		l-=lowbit(l);
	}
	return res;
}

inline void out(ll x)
{
	if(x/10)
		out(x/10);
	putchar(x%10+'0');
}

int main()
{
//	freopen("data.txt","r",stdin);
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	block_size=sqrt(n);
	memset(L,0x3f,sizeof(L));
	for(int i=1;i<=n;i++)
	{
		bel[i]=((i-1)/block_size)+1;
		L[bel[i]]=std::min(L[bel[i]],i);
		R[bel[i]]=std::max(R[bel[i]],i);
	}
	num=bel[n];
	for(int i=1;i<=n;i++)
	{
		read(ai[i]);
		add(i,ai[i]);
	}
	for(int i=1;i<=n;i++)
	{
		read(funcL[i]);
		read(funcR[i]);
		++val[bel[i]][funcL[i]];
		--val[bel[i]][funcR[i]+1];
	}
	for(int i=1;i<=num;i++)
	{
		int now=0;
		for(int v=1;v<=n;v++)
		{
			now+=val[i][v];
			val[i][v]=now+val[i-1][v];
			count[i]+=(ll)ai[v]*now;
		}
	}
	read(m);
	ll tmp;
	for(int i=1,op,l,r;i<=m;i++)
	{
		read(op);
		read(l);
		read(r);
		if(op==1)
		{
			for(int v=1;v<=num;v++)
			{
				count[v]-=(ll)ai[l]*(val[v][l]-val[v-1][l]);
				count[v]+=(ll)r*(val[v][l]-val[v-1][l]);
			}
			minus(l,ai[l]);
			add(l,r);
			ai[l]=r;
		}
		else
		{
			tmp=0;
			for(int v=bel[l]+1;v<=bel[r]-1;v++)
				tmp+=count[v]; 
			if(bel[l]==bel[r])
			{
				for(int v=l;v<=r;v++)
					tmp+=query(funcL[v],funcR[v]);
			}
			else
			{
				for(int v=l;v<=R[bel[l]];v++)
					tmp+=query(funcL[v],funcR[v]);
				for(int v=L[bel[r]];v<=r;v++)
					tmp+=query(funcL[v],funcR[v]);
			}
			out(tmp);
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

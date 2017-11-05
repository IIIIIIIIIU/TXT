#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=1e5+5;

struct node
{
	int l,s;
	
	bool operator<(const node &tmp)const
	{
		if(s==tmp.s)
			return l>tmp.l;
		return s>tmp.s;
	}
	
	node(){}
	
	node(int l_,int s_)
	{
		l=l_;
		s=s_;
	}
};

struct node ai[maxn<<1|1];

int n;

ll ans;

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

bool cmp(const node &tmp1,const node &tmp2)
{
	if(tmp1.l==tmp2.l)
		return tmp1.s<tmp2.s;
	return tmp1.l<tmp2.l;
}

int main()
{
	read(n);
	for(int i=1,tmp1,tmp2;i<=(n<<1);i++)
	{
		read(tmp1);
		read(tmp2);
		if(tmp1<tmp2)
			std::swap(tmp1,tmp2);
		ai[i]=node(tmp1,tmp2);
		if(tmp2<ai[1].s||(tmp2==ai[1].s&&tmp1<ai[1].l))
			std::swap(ai[i],ai[1]);
	}
	std::sort(ai+2,ai+n+n+1,cmp);
	std::priority_queue<node>que;
	for(int i=n+n;i>1;i--)
	{
		que.push(ai[i]);
		if(que.size()>n)
		{
			ai[1].l=std::min(ai[1].l,que.top().l);
			que.pop();
		}
		if(que.size()==n)
		{
			int tmp=ai[1].l;
			if(i>2)
				tmp=std::min(tmp,ai[2].l);
			ans=std::max(ans,1LL*tmp*ai[1].s+1LL*ai[i].l*que.top().s);
		}
	}
	std::cout<<ans;
	return 0;
}

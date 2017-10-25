#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;

struct task
{
	int T,S;
	
	bool operator<(const task &tmp)const
	{
		if(S==tmp.S)
			return T<tmp.T;
		return S<tmp.S;
	}
};

struct task ai[maxn];

int n;

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

bool check(int lit)
{
	ll count=0;
	for(int i=1;i<=n;i++)
	{
		count+=ai[i].T;
		if(count>ai[i].S-lit)
			return false;
	}
	return true;
}

int main()
{
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	read(n);
	int l=0,r=INF,res=-1,mid;
	for(int i=1;i<=n;i++)
	{
		read(ai[i].T);
		read(ai[i].S);
		r=std::min(r,ai[i].S-ai[i].T);
	}
	std::sort(ai+1,ai+n+1);
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
		{
			res=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	std::cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int mod=1e9;
const int maxn=1005;

struct node
{
	int a,b,key;
	
	bool operator<(const node &tmp)const
	{
		return key<tmp.key;
	}
};

struct node ai[maxn];

struct Int
{
	int len;
	
	ll ai[2005];
	
	Int()
	{
		len=1;
		ai[1]=0;
	}
	
	Int(int x)
	{
		len=1;
		ai[1]=x;
	}
	
	Int operator*(const int &x)const
	{
		Int res;
		res.len=len;
		ll tmp=0;
		for(int i=1;i<=res.len;i++)
		{
			tmp+=ai[i]*x;
			res.ai[i]=tmp%mod;
			tmp/=mod;
		}
		while(tmp)
		{
			res.ai[++res.len]=tmp%mod;
			tmp/=mod;
		}
		return res;
	}
	
	Int operator/(const int &x)const
	{
		Int res;
		ll tmp=0;
		res.len=len;
		for(int i=len;i>=1;i--)
		{
			tmp+=ai[i];
			res.ai[i]=tmp/x;
			tmp%=x;
			tmp*=mod;
		}
		while(!res.ai[res.len]&&res.len>1)
			res.len--;
		return res;
	}
	
	bool operator<(const Int &tmp)const
	{
		if(len<tmp.len)
			return true;
		if(len>tmp.len)
			return false;
		for(int i=len;i>=1;i--)
			if(ai[i]==tmp.ai[i])
				continue;
			else if(ai[i]<tmp.ai[i])
				return true;
			else
				return false;
		return false;
	}
	
	void print()
	{
		printf("%lld",ai[len]);
		for(int i=len-1;i>=1;i--)
			printf("%09lld",ai[i]);
	}
};

Int ans,pos;

int n,sx,sb;

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

Int max(const Int &a,const Int &b)
{
	if(a<b)
		return b;
	return a;
}

int main()
{
	read(n);
	read(sx);
	read(sb);
	for(int i=1;i<=n;i++)
	{
		read(ai[i].a);
		read(ai[i].b);
		ai[i].key=ai[i].a*ai[i].b;
	}
	std::sort(ai+1,ai+n+1);
	pos=Int(sx);
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,pos/ai[i].b);
		pos=pos*ai[i].a;
	}
	ans.print();
	return 0;
}

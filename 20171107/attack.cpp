#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int mod=7;

struct MatrixType
{
	int n,m;
	
	ll ai[5][5];
	
	MatrixType operator*(const MatrixType &tmp)const
	{
		MatrixType res;
		res.n=n;
		res.m=tmp.m;
		for(int i=1,v,e;i<=res.n;++i)
			for(v=1;v<=res.m;++v)
			{
				res.ai[i][v]=0;
				for(e=1;e<=m;e++)
					(res.ai[i][v]+=ai[i][e]*tmp.ai[e][v])%=mod;
			}
		return res;
	}
};

ll n,a,b;

inline void read(ll &now)
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

MatrixType pow(MatrixType now,MatrixType c,ll mi)
{
	while(mi>0)
	{
		if(mi&1)
			now=now*c;
		c=c*c;
		mi=mi>>1;
	}
	return now;
}

int main()
{
	freopen("attack.in","r",stdin);
	freopen("attack.out","w",stdout);
	read(a);
	read(b);
	read(n);
	if(n<=2)
		std::cout<<1;
	else
	{
		MatrixType Base,C;
		Base.n=1;
		Base.m=2;
		Base.ai[1][1]=1;
		Base.ai[1][2]=1;
		C.n=2;
		C.m=2;
		C.ai[1][1]=a%mod;
		C.ai[2][1]=b%mod;
		C.ai[1][2]=1;
		C.ai[2][2]=0;
		std::cout<<pow(Base,C,n-2).ai[1][1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

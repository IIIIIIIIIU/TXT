#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxnum=10000000;

ll mod,phi[maxnum+5],pi[maxnum+5],si[maxnum+5],ti[maxnum+5];

bool vis[maxnum+5];

inline void read(int &now)
{
	char Cget;now=0;int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')if(Cget=='-')if_z=-1;
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
	now=now*if_z;
}

inline void read(ll &now)
{
	char Cget;now=0;int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')if(Cget=='-')if_z=-1;
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
	now=now*if_z;
}

ll Exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll d=Exgcd(b,a%b,x,y),tmp=x;
	x=y,y=tmp-a/b*y;
	return d;
}

void solve1()
{
	int T;
	read(T);
	ll a,b,x,y;
	while(T--)
	{
		read(a),read(b);
		ll tmp=Exgcd(a,b,x,y);
		while(x<0) x+=b;
		printf("%I64d\n",x);
	}
}

int pow(int a,int mi)
{
	ll res=1,pos=a;
	while(mi)
	{
		if(mi&1) res=(res*pos)%mod;
		mi>>=1,(pos*=pos)%=mod;
	}
	return res;
}

void solve2()
{
	int T;
	read(T);
	int a,p;
	while(T--)
	{
		read(a),read(p),mod=p;
		int lit=p-1,ans=p-1;
		for(int i=1;i<=sqrt(lit);i++)
		{
			if(lit%i) continue;
			if(pow(a,i)==1) ans=std::min(ans,i);
			if(pow(a,lit/i)==1) ans=std::min(ans,lit/i);
		}
		printf("%d\n",ans);
	}
}

void PrePrime3()
{
	int top=0;
	phi[1]=1;
	for(int i=2;i<=maxnum;i++)
	{
		if(!vis[i]) pi[++top]=i,phi[i]=i-1;
		for(int j=1;j<=top&&i*pi[j]<=maxnum;j++)
		{
			vis[i*pi[j]]=true;
			if(i%pi[j]==0)
			{
				phi[i*pi[j]]=phi[i]*pi[j];
				break;
			}
			phi[i*pi[j]]=phi[i]*(pi[j]-1);
		}
	}
}

void solve3()
{
	PrePrime3();
	for(int i=1;i<=maxnum;i++) phi[i]+=phi[i-1];
	int T,n,m;
	ll ans;
	read(T);
	while(T--)
	{
		ans=0;
		read(n),read(m);
		if(n>m) std::swap(n,m);
		int last;
		for(int i=1;i<=n;i=last+1)
		{
			int nn=n/i,mm=m/i;
			nn=n/nn,mm=m/mm;
			last=std::min(nn,mm);
			ans+=(phi[last]-phi[i-1])*(n/i)*(m/i);
		}
		printf("%I64d\n",ans);
	}
}

void PrePrime4()
{
	int top=0;
	si[1]=1;
	for(int i=2;i<=maxnum;i++)
	{
		if(!vis[i]) pi[++top]=i,si[i]=2,ti[i]=1;
		for(int j=1;j<=top&&i*pi[j]<=maxnum;j++)
		{
			vis[i*pi[j]]=true;
			if(i%pi[j]==0)
			{
				si[i*pi[j]]=si[i]/(ti[i]+1)*(ti[i]+2);
				ti[i*pi[j]]=ti[i]+1;
				break;
			}
			si[i*pi[j]]=si[i]*si[pi[j]];
			ti[i*pi[j]]=1;
		}
	}
}

void solve4()
{
	PrePrime4();
	for(int i=1;i<=maxnum;i++) si[i]+=si[i-1];
	int T,n;
	read(T);
	while(T--)
	{
		read(n);
		printf("%d\n",si[n]);
	}
}

int main()
{
    freopen("years.in","r",stdin);
    freopen("years.out","w",stdout);
	int type;
	read(type);
	if(type==1) solve1();
	else if(type==2) solve2();
	else if(type==3) solve3();
	else solve4();
	fclose(stdin),fclose(stdout);
	return 0;
}

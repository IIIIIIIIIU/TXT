#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef double real;
const int maxn=4e6+5;
const real pi=std::acos(-1.0);
struct node
{
	real a,b;
	node(){}
	node(real a_,real b_)
	{
		a=a_;
		b=b_;
	}
	node operator+(const node &tmp)const
	{
		return node(a+tmp.a,b+tmp.b);
	}
	node operator-(const node &tmp)const
	{
		return node(a-tmp.a,b-tmp.b);
	}
	node operator*(const node &tmp)const
	{
		return node(a*tmp.a-b*tmp.b,a*tmp.b+b*tmp.a);
	}
	node operator/(const real &tmp)const
	{
		return node(a/tmp,b/tmp);
	}
};
struct node ai[maxn],bi[maxn],ci[maxn];
int n,m;
inline void read(int &now)
{
	char Cget;
	now=0;
	while(!isdigit(Cget=getchar()));
	while(isdigit(Cget))
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
}
void fft(node *p,int len,int opt)
{
	for(int i=1,v=0,k;i<len;++i)
	{
		for(k=(len>>1);v&k;k>>=1)
			v^=k;
		v^=k;
		if(i<v)
			std::swap(p[i],p[v]);
	}
	for(int h=2;h<=len;h<<=1)
	{
		node wn=node(std::cos(opt*pi*2/h),std::sin(opt*pi*2/h));
		for(int v=0;v<len;v+=h)
		{
			node w=node(1.0,0.0);
			for(int t=0;t<h/2;++t,w=w*wn)
			{
				node tmp1=p[t+v],tmp2=p[t+v+h/2];
				p[t+v]=tmp1+tmp2*w;
				p[t+v+h/2]=tmp1-tmp2*w;
			}
		}
	}
	if(opt==-1)
		for(int i=0;i<len;++i)
			p[i]=p[i]/len;
}
int main()
{
	read(n);
	read(m);
	for(int i=0;i<=n;i++)
		scanf("%lf",&ai[i].a);
	for(int i=0;i<=m;i++)
		scanf("%lf",&bi[i].a);
	int len=2,tn=n+m+1;
	while(len<=tn)
		len<<=1;
	fft(ai,len,1);
	fft(bi,len,1);
	for(int i=0;i<len;i++)
		ci[i]=ai[i]*bi[i];
	fft(ci,len,-1);
	for(int i=0;i<n+m+1;i++)
		printf("%d ",(int)(ci[i].a+0.5));
	return 0;
}

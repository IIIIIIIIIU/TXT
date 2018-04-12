#include <cstdio>
#include <iostream>
typedef long long ll;
const int mn=1e6+5;
const int M=998244353;
int n;
ll a[mn],b[mn],c[mn],d[mn];
inline ll pw(ll x,ll e){
	ll r=1;
	for(;e>0;e>>=1,x=x*x%M)
		if(e&1)
			r=r*x%M;
	return r;
}
void FFT(ll *p,int l,int o){
	for(int i=0,v=0,k;i<l;i++){
		if(i>v)
			std::swap(p[i],p[v]);
		for(k=(l>>1);(v^=k)<k;k>>=1);
	}
	for(int h=2;h<=l;h<<=1){
		ll wn=pw(3,M-1+o*(M-1)/h),t1,t2;
		for(int i=0;i<l;i+=h){
			ll w=1;
			for(int v=0;v<(h>>1);v++,w=w*wn%M){
				t1=p[i+v];
				t2=p[i+v+(h>>1)]*w%M;
				p[i+v]=(t1+t2)%M;
				p[i+v+(h>>1)]=(t1-t2+M)%M;
			}
		}
	}
	if(o==-1)
	{
		ll inv=pw(l,M-2);
		for(int i=0;i<l;i++)
			p[i]=p[i]*inv%M;
	}
}
void so(int N){
	if(N==1){
		b[0]=pw(a[0],M-2);
		return;
	}
	so(N+1>>1);
	int l=2;
	for(;l<(N<<1);l<<=1);
	for(int i=0;i<N;i++)
		c[i]=a[i];
	for(int i=N;i<l;i++)
		c[i]=0;
	FFT(c,l,1);
	FFT(b,l,1);
	for(int i=0;i<l;i++)
		b[i]=(2-c[i]*b[i]%M+M)%M*b[i]%M;
	FFT(b,l,-1);
	for(int i=N;i<l;i++)
		b[i]=0;
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	so(n);
	for(int i=0;i<n;i++)
		printf("%lld ",(b[i]+M)%M);
	return 0;
}

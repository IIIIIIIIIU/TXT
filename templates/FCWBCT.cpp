#include<cstdio>
int n,pi[10000007],num;
unsigned int a[10000007],b[10000007];
bool vis[10000007];
void readin(){
	int A;
	unsigned int B,C=0;
	scanf("%d%d%u",&n,&A,&B);
	for(int i=1;i<=n;i++)a[i]=C=(C<<A)^(C>>32-A)^B;
	for(int i=1;i<=n;i++)b[i]=C=(C<<A)^(C>>32-A)^B;
}
inline void pre(){
	for(int i=2;i<=n;i++){
		if(!vis[i])
			pi[++num]=i;
		for(int v=1;v<=num&&pi[v]*i<=n;v++){
			vis[i*pi[v]]=true;
			if(i%pi[v]==0)
				break;
		}
	}
}
int main(){
	readin();
	pre();
	for(int i=1;i<=num;i++){
		for(int v=n/pi[i];v>=1;v--){
			a[v]+=a[v*pi[i]];
			b[v]+=b[v*pi[i]];
		}
	}
	for(int i=1;i<=n;i++)
		a[i]*=b[i];
	for(int i=1;i<=num;i++){
		for(int v=1;v*pi[i]<=n;v++)
			a[v]-=a[v*pi[i]];
	}
	unsigned int ans=0;
	for(int i=1;i<=n;i++)
		ans^=a[i];
	printf("%u\n",ans);
	return 0;
}

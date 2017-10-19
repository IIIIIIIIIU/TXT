#include <cstdio>
#define ll long long
#define Max(a,b) ((a)>(b)?(a):(b))
const int MAXN=1000000;
int n,m;
int a[MAXN+10];
ll sum[MAXN+10];
int solve(int k) {
	static int st[MAXN+10];
	int top=1,ret=0;
	for (int i=1; i<=n; i++) {
		sum[i]=sum[i-1]+a[i]-k;
		if (!top || sum[i]<sum[st[top]]) st[++top]=i;
	}
	for (int i=n; i>=1; i--) {
		while (top && sum[st[top]]<=sum[i]) top--;
		ret=Max(ret,i-st[top+1]);
	}
	return ret;
}
void init() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=m; i++){
		int q;
		scanf("%d",&q);
		printf("%lld ",solve(q));
	}
	return ;
}
int main() {
	freopen("blocks.in","r",stdin);
	freopen("blocks.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

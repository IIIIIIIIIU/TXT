#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int n,m,f[N];
int scan(){int i=0;scanf("%d",&i);return i;}
void print(int x,int t=7){
	if(!t)return;
	print(x/2,t-1);
	printf("%d",x&1);
}
int main(){
	int i,j,k,a,b;
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	n = scan();
	int t,ans;
	for(i=1;i<=n;i++){
		a = scan();b = scan();
		t = a;
		ans =0;
		do{
			if(f[t] < i-b)ans++;
			f[t] = i;
			//print(t);printf("\n");
			t = a&(t-1);
		}while(t);
		printf("%d\n",ans);
	}
	return 0;
}

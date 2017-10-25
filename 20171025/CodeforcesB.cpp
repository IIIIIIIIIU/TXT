#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define N 5002

int prea[N],sufa[N],preb[N],sufb[N];

char s[N];

int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++) prea[i]=prea[i-1]+(s[i]=='a'),preb[i]=preb[i-1]+(s[i]=='b');
	for(int i=len;i;i--) sufa[i]=sufa[i+1]+(s[i]=='a'),sufb[i]=sufb[i+1]+(s[i]=='b');
	int ans=len+1;
	for(int l=1;l<=len;l++)
		for(int r=l;r<=len;r++)
			ans=min(ans,prea[r]-prea[l-1]+preb[l-1]+sufb[r+1]);
	ans=min(ans,preb[len]);
	printf("%d",len-ans);
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005;

int n,m,ai[maxn],cnt[maxn],num0,num1,numelse,ans;

bool can[maxn];

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

inline void updata(int x,int d)
{
	x=ai[x];
	if(cnt[x]==0) num0--;
	if(cnt[x]==1) num1--;
	if(cnt[x]>1) numelse--;
	cnt[x]+=d;
	if(cnt[x]==0) num0++;
	if(cnt[x]==1) num1++;
	if(cnt[x]>1) numelse++;
}

int main()
{
	freopen("music.in","r",stdin);
	freopen("music.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;i++) read(ai[i]);
	num0=n;
	for(int i=m;i>=1;i--)
	{
		updata(i,1);
		if(i+n<=m) updata(i+n,-1);
		if(!numelse&&(i+n>m||can[i+n])) can[i]=true;
	}
	memset(cnt,0,sizeof(cnt));
	num0=n,num1=0,numelse=0;
	for(int i=0;i<=std::min(n-1,m);i++)
	{
		if(i) updata(i,1);
		if(numelse==0&&num0==n-i&&(i+1>m||can[i+1])) ans++;
		if(i==m&&numelse==0&&num0==n-i&&(i+1>m||can[i+1])) ans+=n-m-1;
	}
	std::cout<<ans;
	fclose(stdin),fclose(stdout);
	return 0;
}

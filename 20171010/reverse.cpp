#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005,INF=0x3f3f3f3f;

int num0[maxn],num1[maxn],n,ans=INF;

char str[maxn];

inline int get0(int l,int r)
{
	return num0[r]-num0[l-1];
}

inline int get1(int l,int r)
{
	return num1[r]-num1[l-1];
}

int main()
{
	freopen("reverse.in","r",stdin);
	freopen("reverse.out","w",stdout);
	std::cin>>str+1;
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
	{
		num0[i]+=num0[i-1];
		num1[i]+=num1[i-1];
		if(str[i]=='1') ++num1[i];
		else ++num0[i];
	}
	ans=std::min(get0(1,n),get1(1,n));
	for(int i=1;i<n;i++) ans=std::min(ans,get1(1,i)+get0(i+1,n));
	std::cout<<ans;
	fclose(stdin),fclose(stdout);
	return 0;
}

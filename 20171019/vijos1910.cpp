#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int mod1=15013;
const int mod2=15083;
const int mod3=30323;

int n,m,out[1000005],ai1[105],ai2[105],ai3[105],ans;

char str[100005];

inline void read(int &now)
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

int main()
{
	read(n);
	read(m);
	for(int i=0,len;i<=n;i++)
	{
		scanf("%s",str+1);
		len=strlen(str+1);
		int tmp1=0;
		int tmp2=0;
		int tmp3=0;
		int v,d;
		if(str[1]=='-')
		{
			v=2;
			d=-1;
		}
		else
		{
			v=1;
			d=1;
		}
		for(;v<=len;v++)
		{
			tmp1=(tmp1*10+(str[v]-'0')*d)%mod1;
			tmp2=(tmp2*10+(str[v]-'0')*d)%mod2;
			tmp3=(tmp3*10+(str[v]-'0')*d)%mod3;
		}
		ai1[i]=tmp1;
		ai2[i]=tmp2;
		ai3[i]=tmp3;
	}
	for(int i=1;i<=m;i++)
	{
		ll sum1=ai1[n],sum2=ai2[n],sum3=ai3[n];
		for(int v=n-1;v>=0;v--)
		{
			sum1=(sum1*i+ai1[v])%mod1;
			sum2=(sum2*i+ai2[v])%mod2;
			sum3=(sum3*i+ai3[v])%mod3;
		}
		if(!sum1&&!sum2&&!sum3)
			out[++ans]=i;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		printf("%d\n",out[i]);
	return 0;
}

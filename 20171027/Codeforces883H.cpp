#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=4e5+5;

int n,seq[maxn],cnt[65],count,ai[maxn],num,cnt2[65],bi[maxn];
int len,P1,P2;

char str[maxn];

int turn(char x)
{
	if(x>='0'&&x<='9')
		return x-'0'+1;
	if(x>='a'&&x<='z')
		return x-'a'+11;
	return x-'A'+37;
}

char back(int x)
{
	if(x>=1&&x<=10)
		return x-1+'0';
	if(x>=11&&x<=36)
		return x-11+'a';
	return x-37+'A';
}

int need(int x)
{
	int k=n/x;
	return (k>>1)*x;
}

int get2()
{
	while(1)
	{
		if(cnt2[P2])
		{
			cnt2[P2]-=2;
			return P2;
		}
		else
			P2++;
	}
}

int get1()
{
	while(1)
	{
		if(cnt[P1])
		{
			cnt[P1]--;
			return P1;
		}
		else
			P1++;
	}
}

void out()
{
	for(int i=1;i<=(len>>1);i++)
	{
		bi[i]=get2();
		putchar(back(bi[i]));
	}
	if(len&1)
		putchar(back(get1()));
	for(int i=(len>>1);i>=1;i--)
		putchar(back(bi[i]));
	putchar(' ');
}

int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)
	{
		seq[i]=turn(str[i]);
		cnt[seq[i]]++;
	}
	for(int i=1;i<=62;i++)
		count+=(cnt[i]>>1);
	for(int i=1;i<=std::sqrt(n);i++)
		if(n%i==0)
		{
			ai[++num]=i;
			ai[++num]=n/i;
		}
	std::sort(ai+1,ai+num+1);
	num=std::unique(ai+1,ai+num+1)-ai-1;
	for(int i=1,tmp;i<=num;i++)
		if((tmp=need(ai[i]))<=count)
		{
			for(int v=1,x;v<=62;v++)
			{
				x=std::min(tmp,cnt[v]>>1);
				cnt[v]-=x*2;
				cnt2[v]+=x*2;
				tmp-=x;
				if(!tmp)
					break;
			}
			len=n/ai[i];
			P1=1,P2=1;
			printf("%d\n",ai[i]);
			for(int v=1;v<=ai[i];v++)
				out();
			break;
		}
	return 0;
}

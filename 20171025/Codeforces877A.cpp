#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1000005;

int n,ans;

char str[maxn];

int main()
{
	std::cin>>str+1;
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='D'&&str[i+1]=='a'&&str[i+2]=='n'&&str[i+3]=='i'&&str[i+4]=='l')
		{
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='O'&&str[i+1]=='l'&&str[i+2]=='y'&&str[i+3]=='a')
		{
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='S'&&str[i+1]=='l'&&str[i+2]=='a'&&str[i+3]=='v'&&str[i+4]=='a')
		{
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='A'&&str[i+1]=='n'&&str[i+2]=='n')
		{
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='N'&&str[i+1]=='i'&&str[i+2]=='k'&&str[i+3]=='i'&&str[i+4]=='t'&&str[i+5]=='a')
		{
			ans++;
		}
	}
	if(ans==1)
		puts("YES");
	else
		puts("NO");
	return 0;
}

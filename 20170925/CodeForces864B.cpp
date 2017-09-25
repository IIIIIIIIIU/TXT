#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,len,num[1000],ans;

char str[10001];

using std::cin;

int main()
{
	cin>>n;
	cin>>str+1;
	len=strlen(str+1);
	for(int i=1;i<=len;)
	{
		memset(num,0,sizeof(num));
		int tmp=0,v;
		for(v=i;v<=len&&str[v]>='a'&&str[v]<='z';v++)
		{
			if(!num[str[v]]) num[str[v]]++,tmp++;
			ans=std::max(tmp,ans);
		}
		i=v+1;
	}
	std::cout<<ans;
	return 0;
}

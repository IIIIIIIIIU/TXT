#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int len1,len2;

char str1[1005],str2[1005];

int main()
{
	std::cin>>str1+1>>str2+1;
	len1=strlen(str1+1);
	len2=strlen(str2+1);
	int now=0;
	for(int i=1;i<=len2;i++)
	{
		if(str1[i]>='a'&&str1[i]<='z')
			str1[i]-='a';
		else
			str1[i]-='A';
	}
	for(int i=1;i<=len2;i++)
	{
		++now;
		if(now>len1)
			now=1;
		if(str2[i]>='a'&&str2[i]<='z')
			str2[i]=(str2[i]-'a'-str1[now]+26)%26+'a';
		else
			str2[i]=(str2[i]-'A'-str1[now]+26)%26+'A';
	}
	std::cout<<str2+1;
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,ans;

inline int get(int number)
{
	int res=0;
	while(number) res+=number%10,number/=10;
	return res;
}

int main()
{
	freopen("bit.in","r",stdin);
	freopen("bit.out","w",stdout);
	std::cin>>n;
	int BaseVal=get(n),tmp;
	for(int i=n-1;i>=0;i--)
	{
		tmp=get(i);
		if(tmp==BaseVal-1)
		{
			ans=i;
			break;
		}
	}
	std::cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int ai[13],sum,now;

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	for(int i=1;i<=12;i++)
	{
		now+=300;
		read(ai[i]);
		if(ai[i]>now)
		{
			printf("%d\n",-i);
			return 0;
		}
		now-=ai[i];
		sum+=100*(now/100);
		now=now%100;
	}
	printf("%d\n",now+sum+sum/5);
	return 0;
}

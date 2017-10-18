#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int point[5][5]={
		0,0,1,1,0,
		0,0,0,1,0,
		0,0,0,0,1,
		0,0,0,0,1,
		0,0,0,0,0
	};

int ai[205],bi[205],na,nb,n,ansa,ansb;

inline void read(int &now)
{
	char Cget;
	now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n);
	read(na);
	read(nb);
	for(int i=1;i<=na;i++)
		read(ai[i]);
	for(int i=1;i<=nb;i++)
		read(bi[i]);
	int nowa=0;
	int nowb=0;
	for(int i=1;i<=n;i++)
	{
		++nowa;
		if(nowa>na)
			nowa=1;
		++nowb;
		if(nowb>nb)
			nowb=1;
		if(ai[nowa]==bi[nowb])
			continue;
		if(ai[nowa]<bi[nowb])
		{
			if(point[ai[nowa]][bi[nowb]])
				ansa++;
			else
				ansb++;
		}
		else
		{
			if(point[bi[nowb]][ai[nowa]])
				ansb++;
			else
				ansa++;
		}
	}
	std::cout<<ansa<<' '<<ansb;
	return 0;
}

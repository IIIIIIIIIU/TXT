#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef double real;

int t,a,b;

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
	freopen("fseq.in","r",stdin);
	freopen("fseq.out","w",stdout);
	read(t);
	int sum=0;
	while(t--)
	{
		read(a);
		read(b);
		if(a<b)
			printf("%.6lf\n",0.0);
		else
		{
			printf("%.6lf\n",(real)(a+1-b)/(a+1));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

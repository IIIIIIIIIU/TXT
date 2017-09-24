#include <cstdio>

const int BUF=12341235;

char buf[BUF],*Cget=buf;

inline void read(int &now)
{
	now=0;int if_z=1;
	while(*Cget>'9'||*Cget<'0') if(*(Cget++)=='-') if_z=-1;
	while(*Cget>='0'&&*Cget<='9')now=now*10+(*(Cget++))-'0';
	now*=if_z;
}

int main()
{
	freopen("data.txt","r",stdin);
	fread(Cget,1,BUF,stdin);
	int a;
	read(a);
	printf("%d\n",a);
	return 0;
}

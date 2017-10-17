#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,ans1,ans2=-1,ans3;

char str[105][105];

inline void read(int &now)
{
	char Cget;now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
		now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
	read(n);
	int tmp1,tmp2,tmp3,tmp4;
	char op1[4],op2[4];
	for(int i=1;i<=n;i++)
	{
		std::cin>>str[i];
		std::cin>>tmp1>>tmp2>>op1>>op2>>tmp3;
		tmp4=0;
		if(tmp1>80&&tmp3>=1)
			tmp4+=8000;
		if(tmp1>85&&tmp2>80)
			tmp4+=4000;
		if(tmp1>90)
			tmp4+=2000;
		if(tmp1>85&&op2[0]=='Y')
			tmp4+=1000;
		if(tmp2>80&&op1[0]=='Y')
			tmp4+=850;
		if(tmp4>ans2)
			ans1=i,ans2=tmp4;
		ans3+=tmp4;
	}
	std::cout<<str[ans1]<<std::endl;
	std::cout<<ans2<<std::endl;
	std::cout<<ans3<<std::endl;
	return 0;
}

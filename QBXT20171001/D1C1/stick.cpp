#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n;

void getMin()
{
	int tmp=n/7;
	int temp=n%7;
	if(temp==0)
	{
		for(int i=1;i<=tmp;i++) putchar('8');
	}
	if(temp==1)
	{
		putchar('1'),putchar('0');
		for(int i=2;i<=tmp;i++) putchar('8');
	}
	if(temp==2)
	{
		putchar('1');
		for(int i=1;i<=tmp;i++) putchar('8');
	}
	if(temp==3)
	{
		if(n==3)
		{
			printf("7");
		}
		else
		{
			printf("22");
			for(int i=2;i<=tmp;i++) putchar('8');
		}
	}
	if(temp==4)
	{
		if(n==4) putchar('4');
		else
		{
			printf("20");
			for(int i=2;i<=tmp;i++) putchar('8');
		}
	}
	if(temp==5)
	{
		putchar('2');
		for(int i=1;i<=tmp;i++) putchar('8');
	}
	if(temp==6)
	{
		putchar('6');
		for(int i=1;i<=tmp;i++) putchar('8');
	}
	putchar(' ');
}

void getMax()
{
	int tmp=n%2;
	if(tmp)
	{
		putchar('7');
		for(int i=2;i<=n/2;i++) putchar('1');
	}
	else for(int i=1;i<=n/2;i++) putchar('1');
}

int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	std::cin>>n;
	getMin();
	getMax();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

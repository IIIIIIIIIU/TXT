#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

void LJJ_AK_NOIP_2018(int x)
{
	if(x==0)
	{
		putchar('0');
		return;
	}
	if(x==1)
	{
		putchar('2');
		return;
	}
	bool DID=false;
	for(int i=30;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(i==1)
			{
				if(DID)
				{
					putchar('+');
					putchar('2');
				}
				else
				{
					DID=true;
					putchar('2');
				}
			}
			else if(DID)
				{
					putchar('+');
					putchar('2');
					putchar('(');
					LJJ_AK_NOIP_2018(i);
					putchar(')');
				}
				else
				{
					DID=true;
					putchar('2');
					putchar('(');
					LJJ_AK_NOIP_2018(i);
					putchar(')');
				}
		}
	}
}

int main()
{
	int n;
	std::cin>>n;
	LJJ_AK_NOIP_2018(n);
	return 0;
}

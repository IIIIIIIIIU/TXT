#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e6+5;

int n,k;

char str[maxn];

int main()
{
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		scanf("%s",str+1);
		for(int i=1;i<n;i++)
		{
			if(!k)
				break;
			if(i<n-2)
			{
				if(i%2==1)
				{
					if(str[i]=='2'&&str[i+1]=='3'&&str[i+2]=='3')
					{
						if(k%2)
							str[i+1]='2';
						break;
					}
					if(str[i]=='2'&&str[i+1]=='2'&&str[i+2]=='3')
					{
						if(k%2)
							str[i+1]='3';
						break;
					}
					goto FLAG;
				}
				goto FLAG;
			}
			FLAG:;
			if(str[i]=='2'&&str[i+1]=='3')
			{
				if(i%2)
					str[i+1]='2';
				else
					str[i]='3';
				k--;
			}
		}
		puts(str+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

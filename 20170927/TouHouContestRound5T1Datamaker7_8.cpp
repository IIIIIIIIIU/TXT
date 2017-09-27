#include <bits/stdc++.h>

const int mod=1e9;

int main()
{
	freopen("seko8.in","w",stdout);
	int n=100000,m=100000;
	srand(time(0));
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d ",rand()%mod);
	printf("\n%d\n",m);
	int size=n,type,l,r,tag=0;
	for(int i=1;i<=m;i++)
	{
		int type=rand()%4+1;
		if(i%(m/11)==0) type=2;
		else while(type==2) type=rand()%4+1;
		if(type==1) printf("%d %d\n",type,rand()%mod),size++;
		if(type==2)
			printf("%d\n",type);
		if(type==3)
		{
			if(rand()%2) printf("%d 1 %d\n",type,size);
			else
			{
				l=rand()%(size>>1)+1,r=rand()%size+1;
				if(l>r) std::swap(l,r);
				printf("%d %d %d\n",type,l,r);
			}
		}
		if(type==4) printf("%d %d\n",type,rand()%mod);
	}
	return 0;
}

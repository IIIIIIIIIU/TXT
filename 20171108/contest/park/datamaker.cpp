#include <bits/stdc++.h>

std::set<int>Set,Set2;

int main()
{
	freopen("data.txt","w",stdout);
	srand(time(0));
	int n=1000,m=1000;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
		Set2.insert(i);
	int op,k;
	for(int i=1;i<=m;i++)
	{
		op=rand()%2+1;
		if(i&1)
			op=1;
		if((op==1&&Set.size()<n)||!Set.size())
		{
			std::set<int>::iterator it=Set2.lower_bound(rand()%n);
			while(it==Set2.end())
				it=Set2.lower_bound(rand()%n);
			printf("%d %d\n",1,*it);
			Set.insert(*it);
			Set2.erase(it);
		}
		else
		{
			std::set<int>::iterator it=Set.lower_bound(rand()%n);
			while(it==Set.end())
				it=Set.lower_bound(rand()%n);
			printf("%d %d\n",2,*it);
			Set2.insert(*it);
			Set.erase(it);
		}
	}
	return 0;
}

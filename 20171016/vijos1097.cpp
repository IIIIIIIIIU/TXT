#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,ans;

std::priority_queue<int>que;

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
	int tmp;
	for(int i=1;i<=n;i++)
	{
		read(tmp);
		que.push(-tmp);
	}
	for(int i=1;i<n;i++)
	{
		int k=que.top();
		que.pop();
		k+=que.top(),que.pop();
		ans+=-k,que.push(k);
	}
	std::cout<<ans;
	return 0;
}

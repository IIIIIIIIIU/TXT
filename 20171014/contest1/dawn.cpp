#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=100005;

struct node
{
	int ti,ci;

	bool operator<(const node &tmp)const
	{
		return ti<tmp.ti;
	}
};

struct node ai[maxn];

int n,cnt1,cnt2;

std::priority_queue<int>que;

inline void read(int &now)
{
	char Cget;now=0;while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')now=now*10+Cget-'0',Cget=getchar();
}

int main()
{
//	freopen("T2data.txt","r",stdin);
//	freopen("T2out1.txt","w",stdout);
	freopen("dawn.in","r",stdin);
	freopen("dawn.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		read(ai[i].ti),read(ai[i].ci);
	std::sort(ai+1,ai+n+1);
	for(int i=1;i<=n;i++)
	{
		if(ai[i].ci+cnt2>ai[i].ti)
		{
			if(que.size()&&ai[i].ci<que.top())
				cnt2-=que.top(),que.pop(),que.push(ai[i].ci),cnt2+=ai[i].ci;
		}
		else cnt1++,que.push(ai[i].ci),cnt2+=ai[i].ci;
	}
	std::cout<<cnt1;
	fclose(stdin),fclose(stdout);
	return 0;
}

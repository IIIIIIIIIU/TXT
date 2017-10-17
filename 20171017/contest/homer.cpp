#include<queue>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 110000
#define pr pair<ll,int>
using namespace std;
typedef long long ll;
priority_queue<pr,vector<pr>,greater<pr> >q;
int main()
{
	freopen("homer.in","r",stdin);
	freopen("homer.out","w",stdout);
	int n,m,i,j,k;
	ll ans,x;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		q.push(pr(x,0));
	}
	ans=0;
	if(q.size()==1)
	{
		ans=n;
		q.push(pr(0,1));
	}
	else
	{
		while((n-1)%(k-1)!=0)
			q.push(pr(0,0)),n++;
		while(q.size()!=1)
		{
			pr temp=pr(0,0);
			for(i=0;i<k;i++)
			{
				temp.first+=q.top().first;
				temp.second=max(temp.second,q.top().second+1);
				q.pop();
			}
			ans+=temp.first;
			q.push(temp);
		}
	}
	printf("%lld\n%d\n",ans,q.top().second);
	return 0;
}

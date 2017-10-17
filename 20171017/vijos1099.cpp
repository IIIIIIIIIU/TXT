#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,ai[55][3],S[55],vis[55];

char str[55];

bool Prediction(int x)
{
	for(int i=x,v1,v2,v3,tmp;i>=1;i--)
	{
		if(S[ai[i][1]]!=-1&&S[ai[i][2]]!=-1&&S[ai[i][3]]!=-1)
			if(S[ai[i][1]]+S[ai[i][2]]!=S[ai[i][3]]&&
				S[ai[i][1]]+S[ai[i][2]]+1!=S[ai[i][3]]&&
				S[ai[i][1]]+S[ai[i][2]]-n!=S[ai[i][3]]&&
				S[ai[i][1]]+S[ai[i][2]]-n+1!=S[ai[i][3]])
					return false;
		if(S[ai[i][1]]!=-1&&S[ai[i][2]]!=-1&&S[ai[i][3]]==-1)
		{
			v1=0,v2=0,v3=0;
			if(S[ai[i][1]]+S[ai[i][2]]>n)
			{
				tmp=S[ai[i][1]]+S[ai[i][2]]-n;
				if(tmp>=0&&tmp<n)
					v1+=vis[tmp];
				tmp++;
				if(tmp>=0&&tmp<n)
					v1+=vis[tmp];
				if(v1==2)
					return false;
			}
		}
	}
	return true;
}

void dfs(int N,int s,int t)
{
	if(!N)
	{
		if(!t)
		{
			for(int i=0;i<n;i++)
				printf("%d ",S[i]);
			exit(0);
		}
		return;
	}
	int k1=ai[N][1],k2=ai[N][2],k3=ai[N][3];
	if(s==3)
	{
		if(S[k3]!=-1)
		{
			if(S[k1]+S[k2]+t==S[k3])
				dfs(N-1,1,0);
			if(S[k1]+S[k2]+t-n==S[k3])
				dfs(N-1,1,1);
		}
		else
		{
			int tmp=S[k1]+S[k2]+t;
			if(tmp<n&&!vis[tmp])
			{
				S[k3]=tmp,vis[tmp]=1;
				if(Prediction(N))
					dfs(N-1,1,0);
				S[k3]=-1,vis[tmp]=0;
			}
			tmp-=n;
			if(tmp>=0&&tmp<n&&!vis[tmp])
			{
				S[k3]=tmp,vis[tmp]=1;
				if(Prediction(N))
					dfs(N-1,1,1);
				S[k3]=-1,vis[tmp]=0;
			}
		}
	}
	else
	{
		int k=ai[N][s];
		if(S[k]!=-1)
			dfs(N,s+1,t);
		else
		{
			for(int i=0;i<n;i++)
				if(!vis[i])
				{
					S[k]=i,vis[i]=1;
					if(Prediction(N))
						dfs(N,s+1,t);
					S[k]=-1,vis[i]=0;
				}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
	{
		scanf("%s",str+1);
		for(int v=1;v<=n;v++)
			ai[v][i]=str[v]-'A';
	}
	for(int i=0;i<n;i++)
		S[i]=-1;
	dfs(n,1,0);
	return 0;
}

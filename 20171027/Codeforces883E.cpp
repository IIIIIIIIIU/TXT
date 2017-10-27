#include<cstdio>
#include<cstring>

using namespace std;

char s[52],t[52];

bool use[26],start[26];

bool now[26];

int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<26;i++) use[i]=true,start[i]=true;
	for(int i=0;i<n;i++) use[s[i]-'a']=false,start[s[i]-'a']=false;
	scanf("%d",&m);
	bool ok;
	for(int i=1;i<=m;i++)
	{
		ok=true;
		scanf("%s",t);
		for(int j=0;j<n && ok ;j++)
		{
			if(s[j]!='*' && s[j]!=t[j]) ok=false;
			else if(s[j]=='*' && !start[t[j]-'a']) ok=false;
		}
		if(!ok) continue;
		memset(now,false,sizeof(now));
		for(int j=0;j<n;j++)
			if(s[j]=='*') now[t[j]-'a']=true;
		for(int j=0;j<26;j++)
			if(!now[j]) use[j]=false; 
	}
	int ans=0;
	for(int i=0;i<26;i++) if(use[i]) ans++;
	printf("%d",ans);
}

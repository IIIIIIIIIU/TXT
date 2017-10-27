#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

string s[401],t;

int main()
{
	int n;
	scanf("%d",&n);
	bool ok; int k,len;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		len=s[i].size();
		/*if(i==9)
		{
			int as=47;
		}*/
		t.clear();
		for(int j=0;j<len;j++)
		{
			if(s[i][j]=='u') t+="oo";
			else if(s[i][j]=='k')
			{
				ok=false; 
				for(k=j+1;k<len;k++)
					if(s[i][k]!='k' && s[i][k]!='h') break;
					else if(s[i][k]=='h') { ok=true;break; }				
				if(ok) t+='h',j=k; 
				else 
				{
					for(int h=j;h<k;h++) t+=s[i][h];
					j=k-1;
				} 
			}
			else t+=s[i][j];
		}
		s[i]=t;
	}
	sort(s+1,s+n+1);
	//for(int i=1;i<=n;i++) cout<<s[i]<<endl;
	int ans=0;
	t.clear();
	for(int i=1;i<=n;i++)
		if(s[i]!=t) ans++,t=s[i];
	printf("%d",ans);
	return 0;
}

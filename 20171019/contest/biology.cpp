#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef unsigned long long ll;

const int maxlen=1000005,maxn=150005,hpos=29;

int n,m,S[maxn],T[maxn],len[maxn],nowlen,top,Stack[maxn];

char Arc[maxlen];

ll Hash[maxlen];

inline void read(int &now)
{
	char Cget;
	now=0;
	while((Cget=getchar())>'9'||Cget<'0');
	while(Cget>='0'&&Cget<='9')
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
}

inline bool check(int lit)
{
	ll tmp=Hash[T[Stack[1]]-lit+1];
	for(int i=2;i<=top;i++)
		if(Hash[T[Stack[i]]-lit+1]!=tmp)
			return false;
	return true;
}

int main()
{
//	freopen("data.txt","r",stdin);
	freopen("biology.in","r",stdin);
	freopen("biology.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",Arc+nowlen);
		len[i]=strlen(Arc+nowlen);
		S[i]=nowlen;
		T[i]=nowlen+len[i]-1;
		nowlen+=len[i];
		Hash[T[i]]=Arc[T[i]]-'a'+1;
		for(int v=T[i]-1;v>=S[i];v--)
			Hash[v]=Hash[v+1]*hpos+(Arc[v]-'a'+1);
	}
	for(int i=1,op,l,r,mid,res;i<=m;i++)
	{
		read(op);
		if(op==1)
		{
			++n;
			scanf("%s",Arc+nowlen);
			len[n]=strlen(Arc+nowlen);
			S[n]=nowlen;
			T[n]=nowlen+len[n]-1;
			nowlen+=len[n];
			Hash[T[n]]=Arc[T[n]]-'a'+1;
			for(int v=T[n]-1;v>=S[n];v--)
				Hash[v]=Hash[v+1]*hpos+(Arc[v]-'a'+1);
		}
		else
		{
			read(top);
			l=1,r=maxlen,mid,res=0;
			for(int v=1;v<=top;v++)
			{
				read(Stack[v]);
				r=std::min(r,len[Stack[v]]);
			}
			while(l<=r)
			{
				mid=l+r>>1;
				if(check(mid))
				{
					res=mid;
					l=mid+1;
				}
				else
					r=mid-1;
			}
			printf("%d\n",res);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

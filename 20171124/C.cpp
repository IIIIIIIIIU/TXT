#include<cstdio>
#include<algorithm>
 
using namespace std;
 
#define N 151
 
int l[N],r[N];
 
char s[N];
 
bool have[N];
 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int endd=1;
    for(int i=1;i<=n;++i)
    {
        scanf("%s",s+1);
        for(int j=1;j<=m;++j)
            if(s[j]=='W')
            {
                if(!l[i]) l[i]=j;
                r[i]=j;
                have[i]=true;
                endd=i;
            }
    }
    int ans=0,last=1;
    if(r[1]) last=r[1],ans=r[1]-1;
    for(int i=2;i<=endd;++i)
    {
        if(!have[i])
        {
            ans++;
            continue;
        }
        if(i&1)
        {
            if(l[i]<last) ans+=last-l[i],last=l[i];
            ans+=r[i]-last+1;
            last=r[i];
        }
        else
        {
            if(r[i]>last) ans+=r[i]-last,last=r[i];
            ans+=last-l[i]+1;
            last=l[i];
        }
    }
    printf("%d",ans);
    return 0;
}

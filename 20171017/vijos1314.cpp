#include<cstdio>
#include<iostream>
#define M 2010
using namespace std;
int a[M],dao[M],vis[M][M],tim[M][M],mac[M][M],lon[M][M],n,m;
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n*m;i++)
      scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d",&mac[i][j]);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d",&tim[i][j]);
    for(int i=1;i<=n*m;i++)
    {
        int gj=a[i],gx=++dao[gj],jq=mac[gj][gx],ti=tim[gj][gx];
        int p=lon[gj][gx-1]+1;
        while(1)
        {
            int flag=0;
            for(int i=p;i<p+ti;i++)
              if(vis[jq][i])
              {
                  flag=1;
                  break;
              }
            if(!flag)
            {
                for(int i=p;i<p+ti;i++)
                  vis[jq][i]=1;
                lon[gj][gx]=p+ti-1;
                break;
            }
            p++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        ans=max(ans,lon[i][j]);
    printf("%d",ans);
    return 0;
}

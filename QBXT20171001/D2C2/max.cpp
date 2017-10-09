#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[200005],i,ansx,ansy;
long long  sum[200005],MAX,MAX1[200005],MAX2[200005],x2[200005],x1[200005];
int main()
{
    freopen("max.in","r",stdin);
    freopen("max.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    for (i=1; i<=n; i++)
        sum[i]=sum[i-1]+(long long)a[i];
   // return 0;
    for (i=m; i<=n; i++)
    {
        //if (i%1000==0)cout<<i<<endl;
        if (MAX1[i-1]>=sum[i]-sum[i-m])
        {
            x1[i]=x1[i-1];
            MAX1[i]=MAX1[i-1];
        }
        else
        {
            x1[i]=i-m+1;
            MAX1[i]=sum[i]-sum[i-m];
        }
    }
    for (i=n-m+1; i>=1; i--)
    {
        if (MAX2[i+1]>sum[i+m-1]-sum[i-1])
        {
            x2[i]=x2[i+1];
            MAX2[i]=MAX2[i+1];
        }
        else
        {
            x2[i]=i;
            MAX2[i]=sum[i+m-1]-sum[i-1];
        }
    }
    for (i=m; i<=n-m; i++)
    {
        if (MAX1[i]+MAX2[i+1]>MAX)
        {
            MAX=MAX1[i]+MAX2[i+1];
            ansx=x1[i]; ansy=x2[i+1];
        }
    }
    printf("%d %d\n",ansx,ansy);
    return 0;
}

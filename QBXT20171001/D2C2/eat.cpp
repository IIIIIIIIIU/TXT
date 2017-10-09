#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int f[100000005],c[25000005],cc[25000005];
int A,B,C,D,n,a[5005],b[5005],aa[5005],bb[5005],MAX,cnt,cntt,i,j,now;
long long ans;
int main()
{
    freopen("eat.in","r",stdin);
    freopen("eat.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
    if (n==0 && A==0 && B==0 && C==0 && D==0) return 0;
    for (i=1; i<=A; i++) scanf("%d",&a[i]);
    for (i=1; i<=B; i++) scanf("%d",&b[i]);
    MAX=0;
    cnt=cntt=0;
    for (i=1; i<=A; i++)
        for (j=1; j<=B; j++)
            if (a[i]+b[j]<=n)
            {
                f[a[i]+b[j]]++;
                MAX=max(MAX,a[i]+b[j]);
            }
    for (i=0; i<=MAX; i++)
    while (f[i])
        {
            f[i]--;
            c[++cnt]=i;
        }

    for (i=1; i<=C; i++) scanf("%d",&aa[i]);
    for (i=1; i<=D; i++) scanf("%d",&bb[i]);
    MAX=0;
    for (i=1; i<=C; i++)
        for (j=1; j<=D; j++)
            if (aa[i]+bb[j]<=n)
            {
                f[aa[i]+bb[j]]++;
                MAX=max(MAX,aa[i]+bb[j]);
            }
    for (i=0; i<=MAX; i++)
    while (f[i])
        {
            f[i]--;
            cc[++cntt]=i;
        }
    for (i=cntt; i>=1; i--) if (c[1]+cc[i]<=n) break;
    now=i;
    for (i=1; i<=cnt; i++)
    {
        ans+=now;
        while (now&& c[i+1]+cc[now]>n) now--;
    }
    cout<<ans<<endl;
    ans=0;
    return 0;
}

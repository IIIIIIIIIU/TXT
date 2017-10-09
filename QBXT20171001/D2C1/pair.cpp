#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int N=(1<<17)+5;
long long st[N][20],ST[N][20];
int p[N],i,sum,o,a[N],b[N],n,T,PP,now,j,A,RR[N];
void gb(int l,int r)
{
    if (l==r) return;
    int mid=(l+r)/2;
    gb(l,mid); gb(mid+1,r);
    int i=l,j=mid+1,o=l;
    for (i=l; i<=r; i++) b[i]=a[i];
    for (i=r; i>=mid; i--) {RR[i]=i; if (i!=r && b[i+1]==b[i]) RR[i]=RR[i+1];}
    i=l; j=mid+1;
    while (i<=mid && j<=r)
    {
        if (b[i]<=b[j]) {a[o++]=b[i];if (b[i]==b[j]) ST[l][p[r-l+1]]+=RR[j]-j+1; i++;} else
        {
            a[o++]=b[j]; st[l][p[r-l+1]]+=mid-i+1;

            j++;
        }
    }
    if (i<=mid) for (j=i; j<=mid; j++) a[o++]=b[j]; else
    if (j<=r) for (i=j; i<=r; i++) a[o++]=b[i];
}
long long t[105],TT[105];
int main()
{
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    scanf("%d",&n);
    sum=(1<<n);
    for (i=1; i<=sum; i++) scanf("%d",&a[i]);
    for (i=1; i<=17; i++) p[1<<i]=i;
    gb(1,sum);
    scanf("%d",&T);
    for (i=1; i<=n; i++)
      for (j=1; j<=(1<<n); j+=(1<<i))
      {
          t[i]+=st[j][i];
          TT[i]+=ST[j][i];
      }
    long long ans=0;
    while (T--)
    {
        int Q;
        scanf("%d",&Q);
        for (i=1; i<=Q; i++) t[i]=1ll*(1<<i-1)*(1<<i-1)*(1<<n-i)-TT[i]-t[i];
        for (i=1; i<=n; i++) ans+=t[i];
        printf("%I64d\n",ans); ans=0;
    }
    return 0;
}

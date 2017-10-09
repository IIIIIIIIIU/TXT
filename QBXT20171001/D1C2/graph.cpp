#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
double ans;
int A,B,C,n,m,a[100005],i;
int main()
{
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    for (i=1; i<=m; i++)
    {
        scanf("%d%d%d",&A,&B,&C);
        ans=max(ans,(a[A]+a[B])/(C+0.0));
    }
    printf("%.2f\n",ans);
    return 0;
}

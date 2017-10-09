#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
set<int> ::iterator sit;
int ans,sum,p[1005],i,a[1005],b[1005],cnt,CNT,j,ANS,n;
int cmp(int i,int j) {return i>j;}
bool FLAG;
int main()
{
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    ANS=1000000000;
    scanf("%d",&n);
    for (i=1; i<=n; i++)
      scanf("%d%d",&a[i],&b[i]);
    for (i=1; i<=1000; i++)
    {
        sum=0; FLAG=true; cnt=0; CNT=0;
        for (j=1; j<=n; j++)
          if (b[j]<=i && (a[j]<=b[j] || a[j]>i)) sum+=a[j]; else
            if (a[j]>i && b[j]>i) {FLAG=false; break;} else
              if (b[j]>i) {cnt++; sum+=b[j];} else
              {
                  p[++CNT]=a[j]-b[j];
                  sum+=a[j];
              }
        if (!FLAG) continue;
        if (cnt>n/2) continue;
        sort(p+1,p+CNT+1,cmp);
        for (j=1; j<=min(n/2-cnt,CNT); j++) sum-=p[j];
        ANS=min(ANS,sum*i);
    }
    cout<<ANS;
    return 0;
}

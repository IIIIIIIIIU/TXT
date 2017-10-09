#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
long long st[131073][18];
int next[18][131073],i,j,n,m,now,k,A,B;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=(1<<n); i++) cin>>st[i][0];
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=(1<<n); j+=(1<<i))
        {
            if (i % 2==1) st[j][i]=st[j][i-1]|st[j+(1<<(i-1))][i-1]; else
              st[j][i]=st[j][i-1]^st[j+(1<<(i-1))][i-1];
        }
    }
    for (i=1; i<=n; i++)
      for (j=1; j<=(1<<n); j+=(1<<i))
      {
          for (k=j; k<=j+(1<<i)-1; k++)
            next[i][k]=j;
      }
    for (i=1; i<=m; i++)
    {
        scanf("%d%d",&A,&B);
        st[A][0]=B;
        for (j=1; j<=n; j++)
        {
            now=next[j][A];
            if (j % 2==1) st[now][j]=st[now][j-1]|st[now+(1<<(j-1))][j-1]; else
                st[now][j]=(st[now][j-1]^st[now+(1<<(j-1))][j-1]);
        }
        cout<<st[1][n]<<endl;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int MOD=12345647;
int dp[10005][3][2][2][2],a[10005],b[10005],len1,len2,i,j,k,l,t,I,J,K,L,T,s1,s2,s3,ans;
char n[10005],LL[10005];
void ADD(int &A,int B) {A+=B; if (A>=MOD) A-=MOD;}
int main()
{
        freopen("candy.in","r",stdin);
        freopen("candy.out","w",stdout);
        scanf("%s",n);
        scanf("%s",LL);
        len1=strlen(n); len2=strlen(LL);
        for (i=0; i<len1; i++) a[i+1]=n[i]-'0';
        for (i=0; i<len1; i++) b[i+1]=0;
        for (i=0; i<len2; i++) b[1+i+len1-len2]=LL[i]-'0';
        for (i=0; i<=len1; i++)
          for (j=0; j<=2; j++)
            for (k=0; k<=1; k++)
              for (l=0; l<=1; l++)
                for (t=0; t<=1; t++) dp[i][j][k][l][t]=0;
        dp[0][0][0][0][0]=1;
        for (i=0; i<len1; i++)
          for (j=0; j<=2; j++)
            for (k=0; k<=1; k++)
              for (l=0; l<=1; l++)
                for (t=0; t<=1; t++)
                if (dp[i][j][k][l][t])
                {
                    for (s1=0; s1<=9; s1++)
                      if (s1!=3)
                        for (s2=0; s2<=9; s2++)
                          if (s2!=3)
                            for (s3=0; s3<=9; s3++)
                            if (s3!=3)
                            {
                                I=i+1;
                                J=j*10+a[i+1]-s1-s2-s3;
                                if (J>2 || J<0) continue;
                                if (k==0 && s1<b[i+1]) continue;
                                K=(k || s1>b[i+1]);
                                if (l==0 && s2<b[i+1]) continue;
                                L=(l || s2>b[i+1]);
                                if (t==0 && s3<b[i+1]) continue;
                                T=(t || s3>b[i+1]);
                                ADD(dp[I][J][K][L][T],dp[i][j][k][l][t]);
                            }
                }
        for (k=0; k<=1; k++) for (l=0; l<=1; l++) for (t=0; t<=1; t++) ADD(ans,dp[len1][0][k][l][t]);
        cout<<ans<<endl; ans=0;
    return 0;
}

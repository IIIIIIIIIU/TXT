#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
char s[100005];
int len,sum,i,j,FLAG;
int main()
{
    freopen("bit.in","r",stdin);
    freopen("bit.out","w",stdout);
        scanf("%s",s); FLAG=0;
        if (s[0]!='-')
        {
        len=strlen(s); sum=0;
        for (i=len-1; i>=0; i--)
        {
            if (s[i]>='1' && sum>=2)
            {
                s[i]=char(s[i]-1);
                sum=2;
                for (j=i+1; j<len; j++)
                {
                    while (sum && s[j]<'9')
                    {
                        sum--;
                        s[j]=char(s[j]+1);
                    }
                }
                int SS=0;
                for (j=i+1; j<len; j++) SS+=s[j]-'0';
                for (j=i+1; j<len; j++)
                {
                    if (SS>=9) {s[j]='9'; SS-=9;} else {s[j]=char(SS+'0'); SS=0;}
                }
                FLAG=1;
                break;
            }
            sum+='9'-s[i];
        }
        if (FLAG)
        {
            for (i=0; i<len; i++) if (s[i]!='0') break;
            for (j=min(len-1,i); j<len; j++) cout<<s[j]; cout<<endl;
            return 0;
        }
        cout<<'-';
        for (i=len-1; i>=0; i--)
        {
            if (s[i]<'9')
            {
                s[i]=char(s[i]+1);
                FLAG=1;
                break;
            }
        }
        if (FLAG)
        {
            for (i=0; i<len; i++) if (s[i]!='0') break;
            for (j=min(len-1,i); j<len; j++) cout<<s[j]; cout<<endl;
            return 0;
        }
        cout<<1;
            for (i=0; i<len; i++) if (s[i]!='0') break;
            for (j=min(len-1,i); j<len; j++) cout<<s[j]; cout<<endl;
        return 0;
        }

        FLAG=0;
        cout<<'-';
        len=strlen(s);
        for (i=len-1; i>=1; i--)
        {
            if (s[i]<'9')
            {
                s[i]=char(s[i]+1);
                FLAG=1;
                break;
            }
        }
        if (FLAG)
        {
            for (i=1; i<len; i++) if (s[i]!='0') break;
            for (j=min(len-1,i); j<len; j++) cout<<s[j]; cout<<endl;
            return 0;
        }
        cout<<1;
            for (i=1; i<len; i++) if (s[i]!='0') break;
            for (j=min(len-1,i); j<len; j++) cout<<s[j]; cout<<endl;
    return 0;
}

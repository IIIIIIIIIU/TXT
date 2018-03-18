#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const int maxn=2e6+5;

int n,f[maxn],len[maxn],ch[maxn][26],tot=1,last=1;
int r[maxn],v[maxn],sa[maxn];

char str[maxn];

ll ans;

void extend(int c)
{
    int np,p,q,nq;
    len[np=++tot]=len[last]+1;
    for(p=last;p&&!ch[p][c];p=f[p])
        ch[p][c]=np;
    if(!p)
        f[np]=1;
    else
    {
        q=ch[p][c];
        if(len[q]==len[p]+1)
            f[np]=q;
        else
        {
            nq=++tot;
            memcpy(ch[nq],ch[q],sizeof(ch[nq]));
            f[nq]=f[q];
            f[q]=f[np]=nq;
            len[nq]=len[p]+1;
            for(;ch[p][c]==q;p=f[p])
                ch[p][c]=nq;
        }
    }
    last=np;
}

int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        r[tot+1]=1;
        extend(str[i]-'a');
    }
    for(int i=1;i<=tot;i++)
        v[len[i]]++;
    for(int i=1;i<=tot;i++)
        v[i]+=v[i-1];
    for(int i=1;i<=tot;i++)
        sa[v[len[i]]--]=i;
    for(int i=tot;i>=1;i--)
        r[f[sa[i]]]+=r[sa[i]];
    for(int i=1;i<=tot;i++)
        if(r[i]>1)
            ans=std::max(ans,1LL*len[i]*r[i]);
    std::cout<<ans<<std::endl;
    return 0;
}

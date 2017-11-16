#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

const ll maxn=3e5+5;

class SegTreeType
{
    private:
        
        ll L,R;
        
        struct SegTreeNodeType
        {
            ll val;
            
            SegTreeNodeType *lc,*rc;
            
            SegTreeNodeType()
            {
                lc=NULL;
                rc=NULL;
            }
        };
        
        struct SegTreeNodeType *root;
        
        ll get(SegTreeNodeType *&now,ll l,ll r,ll k)
        {
            if(now==NULL)
            {
                now=new SegTreeNodeType;
                now->val=r-l+1;
            }
            now->val--;
            if(l==r)
                return l;
            ll mid=l+r>>1,dis=0;
            if(now->lc==NULL)
                dis=mid-l+1;
            else
                dis=now->lc->val;
            if(k<=dis)
                return get(now->lc,l,mid,k);
            return get(now->rc,mid+1,r,k-dis);
        }
        
    public:
        SegTreeType(){}
        
        void build(ll l,ll r)
        {
            root=NULL;
            L=l;
            R=r;
        }
        
        ll size()
        {
            if(R<L)
                return 0;
            if(root==NULL)
                return R-L+1;
            return root->val;
        }
        
        ll getk(ll k)
        {
            return get(root,L,R,k);
        }
};

class SegTreeType tree1[maxn];

class SplayTreeType
{
    private:
        
        ll cnt;
        
        struct TreeNodeType
        {
            ll val;
            
            ll size,key;
            
            TreeNodeType *f,*ch[2];
            
            TreeNodeType(ll key_,ll val_)
            {
                size=1;
                f=NULL;
                key=key_;
                val=val_;
                ch[0]=NULL;
                ch[1]=NULL;
            }
            
            void updata()
            {
                size=1;
                if(ch[0]!=NULL)
                    size+=ch[0]->size;
                if(ch[1]!=NULL)
                    size+=ch[1]->size;
            }
            
            void rotate()
            {
                TreeNodeType *fa=f,*ffa=fa->f;
                ll l=(f->ch[1]==this),r=(l^1);
                if(ffa!=NULL)
                    ffa->ch[ffa->ch[1]==fa]=this;
                fa->ch[l]=ch[r];
                ch[r]=fa;
                f=ffa;
                fa->f=this;
                if(fa->ch[l]!=NULL)
                    fa->ch[l]->f=fa;
                fa->updata();
            }
        };
        
    public:
        struct TreeNodeType *root;
        
        void splay(TreeNodeType *now)
        {
            TreeNodeType *fa,*ffa;
            while(now->f!=NULL)
            {
                fa=now->f;
                ffa=fa->f;
                if(ffa!=NULL)
                {
                    if(ffa->ch[1]==fa^fa->ch[1]==now)
                        now->rotate();
                    else
                        fa->rotate();
                }
                now->rotate();
            }
            now->updata();
            root=now;
        }
        
        ll getk(ll k)
        {
            TreeNodeType *now=root;
            while(true)
            {
                if(now->ch[0]!=NULL&&now->ch[0]->size>=k)
                    now=now->ch[0];
                else
                {
                    if(now->ch[0]!=NULL)
                        k-=now->ch[0]->size;
                    if(k==1)
                    {
                        splay(now);
                        return now->val;
                    }
                    k--;
                    now=now->ch[1];
                }
            }
        }
        
        void insert(ll X)
        {
            ll x=++cnt;
            if(root==NULL)
            {
                root=new TreeNodeType(x,X);
                return;
            }
            TreeNodeType *now=root,*fa=NULL;
            while(true)
            {
                fa=now;
                if(x<now->key)
                    now=now->ch[0];
                else
                    now=now->ch[1];
                if(now==NULL)
                {
                    fa->ch[x>fa->key]=new TreeNodeType(x,X);
                    fa->ch[x>fa->key]->f=fa;
                    splay(fa->ch[x>fa->key]);
                    return;
                }
            }
        }
        
        void del()
        {
            if(root->ch[0]==NULL&&root->ch[1]==NULL)
            {
                delete root;
                root=NULL;
                return;
            }
            if(root->ch[0]!=NULL&&root->ch[1]==NULL)
            {
                root=root->ch[0];
                delete root->f;
                root->f=NULL;
                return;
            }
            if(root->ch[1]!=NULL&&root->ch[0]==NULL)
            {
                root=root->ch[1];
                delete root->f;
                root->f=NULL;
                return;
            }
            TreeNodeType *tmp1=root->ch[1],*now;
            root=root->ch[0];
            delete root->f;
            root->f=NULL;
            now=root;
            while(now->ch[1]!=NULL)
                now=now->ch[1];
            splay(now);
            now->ch[1]=tmp1;
            tmp1->f=now;
            now->updata();
        }
        
        void Build(ll l,ll r,ll *arr)
        {
            build(root,l,r,arr);
        }
        
        void build(TreeNodeType *&now,ll l,ll r,ll *arr)
        {
            ++cnt;
            ll mid=l+r>>1;
            now=new TreeNodeType(mid,arr[mid]);
            if(l<mid)
                build(now->ch[0],l,mid-1,arr);
            if(r>mid)
                build(now->ch[1],mid+1,r,arr);
            if(now->ch[0]!=NULL)
                now->ch[0]->f=now;
            if(now->ch[1]!=NULL)
                now->ch[1]->f=now;
            now->updata();
        }
};

class SplayTreeType tree2[maxn],another;

int n,m,q;

ll id_tmp[maxn];

inline void read(int &now)
{
    char Cget;
    now=0;
    while((Cget=getchar())>'9'||Cget<'0');
    while(Cget>='0'&&Cget<='9')
    {
        now=now*10+Cget-'0';
        Cget=getchar();
    }
}

inline void read(ll &now)
{
    char Cget;
    now=0;
    while((Cget=getchar())>'9'||Cget<'0');
    while(Cget>='0'&&Cget<='9')
    {
        now=now*10+Cget-'0';
        Cget=getchar();
    }
}

int main()
{
	freopen("2017phalanx.in","r",stdin);
	freopen("2017phalanx.out","w",stdout);
    read(n);
    read(m);
    read(q);
    for(ll i=1;i<=n;i++)
    {
        tree1[i].build(1,m-1);
        id_tmp[i]=i*m;
    }
    another.Build(1,n,id_tmp);
    ll tmp,tmp2;
    for(int i=1,x,y;i<=q;i++)
    {
        read(x);
        read(y);
        if(y==m)
        {
            tmp=another.getk(x);
            if(n!=1)
            {
                another.del();
                another.insert(tmp);
            }
            printf("%lld\n",tmp);
        }
        else
        {
            if(tree1[x].size()<y)
            {
                y-=tree1[x].size();
                tmp=tree2[x].getk(y);
                tree2[x].del();
                tmp2=another.getk(x);
                another.del();
                tree2[x].insert(tmp2);
                another.insert(tmp);
                printf("%lld\n",tmp);
            }
            else
            {
                tmp=tree1[x].getk(y)+1LL*(x-1)*m;
                tmp2=another.getk(x);
                another.del();
                tree2[x].insert(tmp2);
                another.insert(tmp);
                printf("%lld\n",tmp);
            }
        }
    }
    return 0;
}

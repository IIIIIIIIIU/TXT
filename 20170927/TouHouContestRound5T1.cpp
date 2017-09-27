#include <cstdio>
#include <iostream>

const int BUF = 10000010;
char Buf[10000010], *buf = Buf;

void read (int &now)
{
    int temp = 0;
    for (now = 0; !isdigit (*buf); ++ buf)
        if (*buf == '-')
            temp = 1;
    for (; isdigit (*buf); now = now * 10 + *buf - '0', ++ buf);
    if (temp)
        now = -now;
}

#define Max 200009

struct T_D
{
    T_D *child[2];
    int size, thb[31];
};

int sum[Max][31], number[Max];
int _Total, _Swap, Count, Times;

class DuLiu_Type
{
    private :
    
        T_D poor[Max * 31], *Tail, *Root, *null;

        inline T_D *New ()
        {
            T_D *now = Tail ++;
            now->child[0] = now->child[1] = null;
            now->size = 0;
            return now;
        }

    public :
        
        DuLiu_Type ()
        {
            Tail = poor;
            null = Tail ++;
            null->child[0] = null->child[1] = null;
            null->size = 0;
            Root = New ();
        }

        void Insert (const int &key)
        {
            T_D *now = Root;
            ++ Times;
            for (int i = 30; i >= 0; -- i)
            {
                if (now->child[(key >> i) & 1] == null)
                    now->child[(key >> i) & 1] = New ();
                now = now->child[(key >> i) & 1];
                ++ now->size;
                for (int j = 0; j <= 30; ++ j)
                    now->thb[j] += (key >> j) & 1;
            }
        }

        inline void Push (const int &key)
        {
            number[++ Count] = key;
            for (int i = 0; i <= 30; ++ i)
                sum[Count][i] = sum[Count - 1][i] + ((key >> i) & 1);
        }

        inline void ReBuild ()
        {
            for (; Count; ) 
                this->Insert (number[Count --]);
            _Swap = _Total;
        }

        long long Find (int k)
        {
            T_D *now = Root;
            long long res = 0;
            for (int i = 30; i >= 0; -- i)
            {
                if (k == 0)
                    break;
                if (k < now->child[(_Swap >> i) & 1]->size)
                    now = now->child[(_Swap >> i) & 1];
                else
                {
                    T_D *pos = now->child[(_Swap >> i) & 1];
                    k -= pos->size;
                    for (int j = 0; j <= 30; ++ j)
                        if ((_Total >> j) & 1)
                            res += (long long)(pos->size - pos->thb[j]) << j;
                        else
                            res += (long long)pos->thb[j] << j;
                    now = now->child[(_Swap >> i) & 1 ^ 1];
                }
            }
            for (int i = 0; i <= 30; ++ i)
            {
                if (((_Total >> i) & 1) && now->thb[i] == 0)
                    res += (long long) k << i;
                if (((_Total >> i) & 1) == 0 && now->thb[i])
                    res += (long long) k << i;
            }
            return res;
        }
        
        long long Query (int key)
        {
            if (key <= Times)
                return this->Find (key);
            long long res = this->Find (Times);
            key -= Times;
            for (int i = 0; i <= 30; ++ i)
                if ((_Total >> i) & 1)
                    res += (long long) (key - sum[key][i]) << i;
                else
                    res += (long long) sum[key][i] << i;
            return res;
        }

        void Change (const int key)
        {
            _Total ^= key;
            return ;
        }
};

DuLiu_Type Duliu;

int main (int argc, char *argv[])
{
	freopen("seko.in","r",stdin);
	freopen("seko.out","w",stdout);
    fread (buf, 1, BUF, stdin);
    int N, M;
    read (N);
    
    int x;    
    for (int i = 1; i <= N; ++ i)
    {
        read (x);
        Duliu.Push (x);
    }

    read (M);
    int y, type;
    for (; M; -- M)
    {
        read (type);
        if (type == 1)
        {
            read (x);
            Duliu.Push (x ^ _Total);
        }
        else if (type == 3)
        {
            read (x);
            read (y);
            printf ("%I64d\n", Duliu.Query(y) - Duliu.Query(x - 1));
        }
        else if (type == 4)
        {
            read (x);
            Duliu.Change (x);
        }
        else
            Duliu.ReBuild ();
    }    
    
    return 0;
}

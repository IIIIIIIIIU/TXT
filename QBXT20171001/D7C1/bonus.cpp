#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXK = 120;
const int MAXN = 16;
const int MAXST = 1 << 15;

long double f[MAXK][MAXST] = {{0}};
int value[MAXN], need[MAXN] = {0};
int k, n;

int main()
{
    freopen("bonus.in", "r", stdin);
    freopen("bonus.out", "w", stdout);
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &value[i]);
        int x;
        scanf("%d", &x);
        while (x)
        {
            need[i] += 1 << (x - 1);
            scanf("%d", &x);
        }
    }
    for (int i = k; i >= 1; i--)
    for (int j = 0; j < 1 << n; j++)
    {
        for (int p = 1; p <= n; p++)
            if ((j & need[p]) == need[p])
                f[i][j] += max(f[i + 1][j], f[i + 1][j | (1 << (p - 1))] + value[p]);
            else
                f[i][j] += f[i + 1][j];
        f[i][j] /= (double)n;
    }
    printf("%.6f\n", (double)f[1][0]);
}

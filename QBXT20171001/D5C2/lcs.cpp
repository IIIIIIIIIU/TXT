#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

#define st first
#define nd second
using namespace std;

typedef long long LL;

const int N = 1010;
const int M = 1E6 + 10;
const int INF = 1E9;
char a[N];
char b[M];
int f[N][N];
int nxt[M][26];
int n, m;

void solve() {
    f[0][1] = nxt[0][a[0] - 'a'];
    for (int i = 0; i <= n; ++i) f[i][0] = -1;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j <= n && f[i][j] < INF; ++j) {
            f[i + 1][j] = min(f[i + 1][j], f[i][j]);
            if (j < n)
                f[i + 1][j + 1] = min(f[i + 1][j + 1], nxt[f[i][j] + 1][a[i + 1] - 'a']);
        }
}

int main() {
    freopen("lcs.in", "r", stdin);
    freopen("lcs.out", "w", stdout);
    scanf("%s%s", a, b);
    n = strlen(a);
    m = strlen(b);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            f[i][j] = INF;
    for (int i = 0; i < 26; ++i)
        nxt[m][i] = INF;
    for (int i = m - 1; i >= 0; --i) {
        memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
        nxt[i][b[i] - 'a'] = i;
    }
    solve();
    int ans = 0;
    for (int i = n; i; --i)
        if (f[n - 1][i] < INF) {
            ans = i;
            break;
        }
    printf("%d\n", ans);
}

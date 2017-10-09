#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

#define st first
#define nd second
using namespace std;

struct edge {
    int x;
    int nxt;
};
typedef long long LL;

const int N = 1E5 + 10;
edge e[2 * N];
int lca[N][17], hd[N], fa[N], sons[N], nxt[N], cnt[N][17], f[N][17];
int n, m, x, y, l;
LL ans;

void link(int x, int y) {
    e[++l].x = y;
    e[l].nxt = hd[x];
    hd[x] = l;
}

void dfs_lca(int x) {
    lca[x][0] = fa[x];
    sons[x] = 1;
    for (int i = 1; i <= 16; ++i)
        lca[x][i] = lca[lca[x][i - 1]][i - 1];
    for (int p = hd[x]; p; p = e[p].nxt)
        if (e[p].x != fa[x]) {
            fa[e[p].x] = x;
            dfs_lca(e[p].x);
            sons[x] += sons[e[p].x];
        }
}

void dfs_ans(int x) {
    for (int p = hd[x]; p; p = e[p].nxt)
        if (e[p].x != fa[x]) nxt[x] = e[p].x, dfs_ans(e[p].x);
    for (int i = 0; i <= 16; ++i) {
        ans += sons[lca[x][i]] - sons[nxt[lca[x][i]]];
        cnt[lca[x][i]][i]++;
        f[lca[x][i]][i]++;
    }
    for (int i = 1; i <= 16; ++i)
        for (int j = 0; j <= i - 1; ++j) {
            ans += LL(cnt[x][i] + f[x][i]) * LL(sons[lca[x][j]] - sons[nxt[lca[x][j]]]);
            cnt[lca[x][j]][j] += cnt[x][i];
            f[lca[x][j]][j] += f[x][i] + cnt[x][i];
        }
}

int main() {
    freopen("bitcount.in", "r", stdin);
    freopen("bitcount.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        link(x, y);
        link(y, x);
    }
    dfs_lca(1);
    sons[0] = sons[1];
    nxt[0] = 1;
    dfs_ans(1);
    printf("%I64d\n", ans);
}

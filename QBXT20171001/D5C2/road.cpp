#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>

#define st first
#define nd second
using namespace std;

typedef long long LL;

const int N = 2E5 + 10;
const LL MD = 1E9 + 7;
int con[N], deg[N], seq[N];
int n, m;
LL ans;

LL pwr(LL x, LL y) {
    LL now = 1;
    while (y > 0) {
        if (y & 1) (now *= x) %= MD;
        (x *= x) %= MD;
        y /= 2;
    }
    return now;
}

void dfs(int x) {
    ++m;
    deg[x] = 0;
    if (deg[con[x]]) dfs(con[x]);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", con + i);
        ++deg[con[i]];
    }
    int h = 1, t = 0;
    for (int i = 1; i <= n; ++i)
        if (!deg[i]) seq[++t] = i;
    while (h <= t) {
        if (!(--deg[con[seq[h]]])) seq[++t] = con[seq[h]];
        ++h;
    }
    ans = pwr(2, t);

    for (int i = 1; i <= n; ++i)
        if (deg[i]) {
            m = 0;
            dfs(i);
            (ans *= (pwr(2, m) - 2)) %= MD;
        }

    printf("%I64d\n", (ans + MD) % MD);
}

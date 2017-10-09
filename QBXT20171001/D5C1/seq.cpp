#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

#define st first
#define nd second
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pr;

LL n;
LL m, md;
LL l, r, u, v;

pr solve(LL rr, LL l, LL r, LL x, LL y) {
    if (x > rr || l > r) return make_pair(0, 0);
    if (l == 1 && r == rr) {
        x = max(x, 1LL);
        y = min(y, rr);
        LL s;
        if ((x + y) % 2 == 0) s = ((x + y) / 2) % md * ((y - x + 1) % md) % md;
        else s = ((x + y) % md) * ((y - x + 1) / 2 % md) % md;
        return make_pair(s % md, y - x + 1);
    }
    LL mid = (rr + 1) / 2;
    if (r <= mid) {
        pr ret = solve(mid, l, r, x / 2 + 1, (y + 1) / 2);
        return make_pair((ret.st * 2 - ret.nd) % md, ret.nd);
    } else if (l > mid) {
        pr ret = solve(rr - mid, l - mid, r - mid, (x + 1) / 2, y / 2);
        return make_pair(ret.st * 2 % md, ret.nd);
    } else {
        pr ret1 = solve(mid, l, mid, x / 2 + 1, (y + 1) / 2);
        pr ret2 = solve(rr - mid, 1, r - mid, (x + 1) / 2, y / 2);
        return make_pair((ret1.st * 2 - ret1.nd + ret2.st * 2) % md,
                         (ret1.nd + ret2.nd) % md);
    }
}

int main() {
    freopen("seq.in", "r", stdin);
    freopen("seq.out", "w", stdout);
    scanf("%I64d%I64d%I64d", &n, &m, &md);
    for (int i = 0; i < m; ++i) {
        scanf("%I64d%I64d%I64d%I64d", &l, &r, &u, &v);
        pr ans = solve(n, l, r, u, v);
        printf("%I64d\n", (ans.st + md) % md);
    }
}

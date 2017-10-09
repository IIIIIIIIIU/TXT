#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int x, n, m, y;

int gcd(int x, int y) {
    if (!x) return y;
    else return gcd(y % x, x);
}

bool solve() {
    scanf("%d%d", &n, &m);
    x = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &y);
        x = gcd(x, abs(y));
    }
    if (n == 1) return y == m;
    if (!x) return !m;
    return !(abs(m) % x);
}

int main() {
    freopen("det.in", "r", stdin);
    freopen("det.out", "w", stdout);
    int tot;
    scanf("%d", &tot);
    for (int i = 0; i < tot; ++i)
        if (solve()) printf("Y\n");
        else printf("N\n");
}

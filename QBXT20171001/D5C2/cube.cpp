#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <cstdlib>

#define st first
#define nd second
using namespace std;

const int N = 25;
struct group {
    int gp[N];

    group() {
        for (int i = 1; i < N; ++i)
            gp[i] = i;
    }
    group(const int* sq) {
        for (int i = 1; i < N; ++i)
            gp[i] = sq[i];
    }
    group operator *(const group& b) {
        group t;
        for (int i = 1; i < N; ++i)
            t.gp[i] = b.gp[gp[i]];
        return t;
    }
    group& operator =(const group& b) {
        for (int i = 1; i < N; ++i)
            gp[i] = b.gp[i];
        return *this;
    }
    bool is_over(const int* a) {
        int x = 1, y = 2, z = 3, w = 4;
        for (int i = 0; i < 6; ++i) {
            if (a[gp[x]] != a[gp[y]] || a[gp[x]] != a[gp[z]] || a[gp[x]] != a[gp[w]])
                return 0;
            x += 4;
            y += 4;
            z += 4;
            w += 4;
        }
        return 1;
    }
    void prt() {
        for (int i = 0; i < 6; ++i) {
            for (int j = 1; j <= 4; ++j)
                printf("%d ", gp[i * 4 + j]);
            printf("\n");
        }
    }
    void prt(int* a) {
        int x = 1, y = 2, z = 3, w = 4;
        for (int i = 0; i < 6; ++i) {
            printf("%d %d %d %d\n", a[gp[x]], a[gp[y]], a[gp[z]], a[gp[w]]);
            x += 4;
            y += 4;
            z += 4;
            w += 4;
        }
    }
};

const int cat[10] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3};
group op[10];
int ans[10];
int a[N];
int m;
bool over = false;

void prepare() {
    int* ptr = op[1].gp;
    ptr[1] = 3;
    ptr[2] = 1;
    ptr[3] = 4;
    ptr[4] = 2;
    ptr[10] = 6;
    ptr[6] = 14;
    ptr[14] = 23;
    ptr[23] = 10;
    ptr[9] = 5;
    ptr[5] = 13;
    ptr[13] = 24;
    ptr[24] = 9;
    op[2] = op[1] * op[1];
    op[3] = op[1] * op[2];

    ptr = op[4].gp;
    ptr[9] = 11;
    ptr[10] = 9;
    ptr[12] = 10;
    ptr[11] = 12;
    ptr[1] = 21;
    ptr[21] = 17;
    ptr[17] = 5;
    ptr[5] = 1;
    ptr[3] = 23;
    ptr[23] = 19;
    ptr[19] = 7;
    ptr[7] = 3;
    op[5] = op[4] * op[4];
    op[6] = op[4] * op[5];

    ptr = op[7].gp;
    ptr[5] = 7;
    ptr[6] = 5;
    ptr[8] = 6;
    ptr[7] = 8;
    ptr[4] = 10;
    ptr[10] = 17;
    ptr[17] = 15;
    ptr[15] = 4;
    ptr[3] = 12;
    ptr[12] = 18;
    ptr[18] = 13;
    ptr[13] = 3;
    op[8] = op[7] * op[7];
    op[9] = op[7] * op[8];
}

void prt(int len) {
    printf("%d", ans[1]);
    for (int i = 2; i < len; ++i)
        printf(" %d", ans[i]);
    printf("\n");
}

void dfs(int d, int ct, group now) {
    if (now.is_over(a)) {
        prt(d);
        over = 1;
        return;
    }
    if (d > m) return;
    for (int i = 1; i < 10; ++i)
        if (!over && cat[i] != ct) {
            ans[d] = i;
            dfs(d + 1, cat[i], op[i] * now);
        }
}

int main() {
    freopen("cube.in", "r", stdin);
    freopen("cube.out", "w", stdout);
    prepare();
    scanf("%d", &m);
    for (int i = 1; i < N; ++i)
        scanf("%d", a + i);
    dfs(1, 0, group());
}

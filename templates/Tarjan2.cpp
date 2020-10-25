#include <cstdio>
#include <iostream>
#define Max 2000007
int N, M;

inline void cmin (int &a, int b) {
	if (b < a) a = b;
}
	int res = 0;

int _n[Max], _v[Max], list[Max], EC, dfn[Max], low[Max], DC;
inline void In (int u, int v) {
	_v[++ EC] = v, _n[EC] = list[u], list[u] = EC;
}
int bel[Max];
int root, cl, sz[Max], count[Max];
void dfs (int now, int fa) {
	bel[now] = res;
	++ count[res];
	dfn[now] = low[now] = ++ DC;
	for (int i = list[now]; i; i = _n[i]) {
		if (dfn[_v[i]] == 0) {
			dfs (_v[i], now);
			low[now] = std :: min (low[now], low[_v[i]]);
			if (now == root) {
				++ cl;
			}
			else if (low[_v[i]] >= dfn[now]) {
				++ sz[now];
			}
		}
		else if (_v[i] != fa) {
			low[now] = std :: min (low[now], dfn[_v[i]]);
		}
	}
}
int ct[Max];
bool is[Max];
/*
6 7
1 2
2 3
1 4
4 3
4 5
4 6
5 6
*/

int main (int argc, char *argv[]) {
	freopen("dat.txt","r",stdin);
	freopen("1.txt","w",stdout);
	scanf ("%d%d", &N, &M);
	int x, y;
	for (int i = 1; i <= M; ++ i) {
		scanf ("%d%d", &x, &y);
		In (x, y), In (y, x);
	}
	for (int i = 1; i <= N; ++ i) {
		if (!dfn[i]) {
			++ res;
			root = i;
			dfs (i, -1);
			if (cl) {
				sz[i] = cl - 1;
			}
			if (count[res] == 1) {
				sz[i] = -1;
			}
			cl = 0;
		}
	}
	
	for (int i = 1; i <= N; ++ i) {
		printf ("%d ", res - 1 + (sz[i] + 1));
	}
	
	return 0;
}

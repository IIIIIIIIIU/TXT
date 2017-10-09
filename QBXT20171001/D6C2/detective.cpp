#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
const int POINT_SIZE = 32768;
const int EDGE_SIZE = 131072;

struct edge {
	int u, v, d;
};
inline bool operator < (const edge & a, const edge & b) {
	return a.d < b.d;
}

int N, M;
int f[POINT_SIZE], s[POINT_SIZE];
edge e[EDGE_SIZE];

void prepare() {
	for (int i = 1; i <= N; i++)
		f[i] = i, s[i] = 1;
}
int find(int u) {
	if (f[u] == u)
		return f[u];
	return f[u] = find(f[u]);
}
void merge(int u, int v) {
	s[u] += s[v];
	f[v] = u;
}

int main() {
	freopen("detective.in", "r", stdin);
	freopen("detective.out", "w", stdout);
	unsigned long long cnt = 0, sum = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].d);
	std::sort(e, e + M);
	prepare();
	int tot = 0;
	for (int i = 0; i < M; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u == v) continue;
		sum += e[i].d;
		cnt += 1ULL * s[u] * s[v] * e[i].d;
		merge(u, v);
	}
	double ans = sum - 2.0 * cnt / N / (N - 1);
	printf("%.2lf\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

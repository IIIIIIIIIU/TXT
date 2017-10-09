#include <cstdio>
#include <vector>
#include <bitset>
using std::vector;
using std::bitset;
const int QUERY_SIZE = 600006;
const int MAP_SIZE = 511;

int N, M, Q;
char map[MAP_SIZE][MAP_SIZE];
int ans[QUERY_SIZE];
bitset<MAP_SIZE> f[MAP_SIZE][MAP_SIZE], g[MAP_SIZE][MAP_SIZE];
struct query {
	int x1, y1, x2, y2, id;
};

query q;
void solve(vector<query> v, int l, int r) {
	int m = (l + r) >> 1;
	if (l > r) return ;
	for (int i = m; i >= l; i--)
		for (int j = M; j >= 1; j--) {
			f[i][j] = 0;
			if (map[i][j] == '.') {
				if (i == m) f[i][j].set(j);
				else f[i][j] |= f[i + 1][j];
				if (j != M) f[i][j] |= f[i][j + 1];
			}
		}
	for (int i = m; i <= r; i++)
		for (int j = 1; j <= M; j++) {
			g[i][j] = 0;
			if (map[i][j] == '.') {
				if (i == m) g[i][j].set(j);
				else g[i][j] |= g[i - 1][j];
				if (j != 1) g[i][j] |= g[i][j - 1];
			}
		}
	vector<query> vl, vr;
	for (vector<query>::iterator it = v.begin(); it != v.end(); it++) {
		q = *it;
		if (q.x2 < m) vl.push_back(q);
		else if (q.x1 > m) vr.push_back(q);
		else ans[q.id] = (f[q.x1][q.y1] & g[q.x2][q.y2]).any();
	}
	solve(vl, l, m - 1);
	solve(vr, m + 1, r);
}

int main() {
	freopen("boardgame.in", "r", stdin);
	freopen("boardgame.out", "w", stdout);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%s", map[i] + 1);
	vector<query> v;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d %d", &q.x1, &q.y1, &q.x2, &q.y2);
		q.id = i;
		v.push_back(q);
	}
	solve(v, 1, N);
	for (int i = 0; i < Q; i++)
		puts(ans[i] ? "Yes" : "No");
	return 0;
}

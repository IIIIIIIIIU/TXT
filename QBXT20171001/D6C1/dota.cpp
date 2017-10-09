#include <cstdio>
const int NUMSIZE = 2097152;

int N, A, B, K;
int x[NUMSIZE];
int l[NUMSIZE], r[NUMSIZE];
bool check(int);

int main() {
	freopen("dota.in", "r", stdin);
	freopen("dota.out", "w", stdout);
	int left, mid, right;
	scanf("%d %d %d %d", &N, &A, &B, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &x[i]);
		if (x[i] > right)
			right = x[i];
	}
	left = 1, right = right + 1;
	while (left + 1 < right) {
		int mid = (left + right) >> 1;
		if (check(mid))
			left = mid;
		else
			right = mid;
	}
	printf("%d\n", left);
	return 0;
}

bool check(int c) {
	for (int i = 1; i <= N; i++)
		if (x[i] >= c)
			l[i] = l[i - 1] + 1;
		else
			l[i] = 0;
	for (int i = N; i >= 1; i--)
		if (x[i] >= c)
			r[i] = r[i + 1] + 1;
		else
			r[i] = 0;
	for (int i = 1; i <= N; i++)
		if (l[i - 1] >= A && r[i + K] >= A && l[i - 1] + r[i + K] >= B)
			return true;
	return false;
}

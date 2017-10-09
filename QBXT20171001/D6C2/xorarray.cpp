#include <cstdio>
const int ARRSIZE = 131072;
const int mod = 1000000007;

int n;
int A[ARRSIZE], B[ARRSIZE];
int a[32][2], b[32][2];
long long C[ARRSIZE];

int main() {
	freopen("xorarray.in", "r", stdin);
	freopen("xorarray.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &B[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 30; j++) {
			a[j][(A[i] >> j) & 1]++;
			b[j][(B[i] >> j) & 1]++;
			long long c = 1ll * a[j][0] * b[j][1] + 1ll * a[j][1] * b[j][0];
			c = c % mod;
			c = c * (1 << j) % mod;
			C[i] = (C[i] + c) % mod;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", C[i]);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}

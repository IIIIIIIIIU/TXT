#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int max_n = 1e5 + 10;
int n, k, a[max_n];

int main() {
	freopen("del.in", "r", stdin);
	freopen("del.out", "w", stdout);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	int multi = 0;
	for (int i = 2; i <= n; i++)
		if (a[i] == a[i - 1]) multi++;
	if (k <= multi) cout << n - multi << endl;
	else cout << n - multi - (k - multi) << endl;
}

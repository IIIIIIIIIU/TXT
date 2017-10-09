#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 1e5 + 10;

struct card {
	int color, value;
	bool operator < (const card &o) const {
		return color < o.color || (color == o.color && value < o.value);
	}
	bool operator == (const card &o) const {
		return color == o.color && value == o.value;
	}
} a[max_n];
int n;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].color >> a[i].value;
	}

	sort(a + 1, a + 1 + n);
	int ori_n = n;
	n = unique(a + 1, a + 1 + n) - (a + 1);

	int last_one = 1;
	int max_ans = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || a[i].color != a[i - 1].color)
			last_one = i;
		while (a[i].value - a[last_one].value + 1 > ori_n)
			last_one++;
		max_ans = max(max_ans, i - last_one + 1);			
	}

	cout << ori_n  - max_ans << endl;
}

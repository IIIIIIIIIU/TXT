#include <cstdio>
#include <cstring>
const int STRSIZE = 131072;

int n, l, m;
char str[STRSIZE];

int main() {
	int t;
	freopen("kakutani.in", "r", stdin);
	freopen("kakutani.out", "w", stdout);
	for (scanf("%d", &n); n; n--) {
		scanf("%s", str);
		l = strlen(str), m = 0, t = 0;
		for (int i = 0; i < l; i++)
			if (str[i] == '1')
				t++;
			else if (str[i] == '4' || str[i] == '7')
				continue;
			else if (str[i] == '3') {
				if (t > 0)
					t--;
				else
					str[m++] = str[i];
			}
			else {
				for ( ; t > 0; t--)
					str[m++] = '1';
				str[m++] = str[i];
			}
		for ( ; t > 0; t--)
			str[m++] = '1';
		str[m] = '\0';
		if (m == 0)
			puts("0");
		else
			printf("%s\n", str);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

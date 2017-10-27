#include <cstdio>
#include <iostream>
#include <cmath>

typedef long long LL;
inline void cmin (LL &a, LL b) { if (b < a) a = b; }
LL f, T, t0, a1, t1, p1, a2, t2, p2, Answer = 7e18;
inline LL max (LL a, LL b) { return a > b ? a : b; }
bool Check (LL key)
{
	LL l = 0, r = f % a2 ? (f / a2 + 1) : (f / a2);
	LL V = key * a1, C = key * t1 * a1;
	LL res; bool F = false;
	for (LL m = 0; m <= r; ++ m)
	{
		LL d = max (((f - (V + m * a2)) * t0), 0);
		if ((C + m * t2 * a2 + d <= T)) 
		{
			r = m - 1, cmin (Answer, p1 * key + p2 * m), F = true; 
		}
		else if ((C + (m - 1) * t2 * a2 + d <= T) && ((m - 1) >= 0))
		{
			LL now = T - (C + (m - 1) * t2 * a2 + d);
			LL Val = V + (m - 1) * a2 + max (f - (V + m * a2), 0);
			if (f - Val > a2) l = m + 1; 
			else if (now - (f - Val) * t2 >= 0) r = m - 1, cmin (Answer, p1 * key + p2 * m), F = true;  
			else l = m + 1;
		}
		else if ((key - 1) * t1 * a1 + m * t2 * a2 + d <= T && (key - 1 >= 0))
		{
			LL now = T - ((key - 1) * t1 * a1 + m * t2 * a2 + d);
			LL Val = (key - 1) * a1 + m * a2 + max (f - (V + m * a2), 0);
			if (f - Val > a1) l = m + 1; 
			else if (now - (f - Val) * t1 >= 0) r = m - 1, cmin (Answer, p1 * key + p2 * m), F = true;  
			else l = m + 1;
		}
		else l = m + 1;
	}
	return F == true;
}
int main (int argc, char *argv[])
{
	scanf ("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &f, &T, &t0, &a1, &t1, &p1, &a2, &t2, &p2);
	bool F1 = false, F2 = false;
	if (f * t0 <= T) return puts ("0"), 0;
	LL l = 0, r = f % a1 ? (f / a1 + 1) : (f / a1);
	LL m;
	for (; l <= r; )
	{
		m = l + r >> 1;
		if (Check (m)) r = m - 1; else l = m + 1;
	}
	printf (Answer == 7e18 ? "-1" : "%lld", Answer); return 0;
}

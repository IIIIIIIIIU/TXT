#include<cstdio>
#include<cmath>
#include<complex>
#include<algorithm>

using namespace std;

#define point complex<double>

const double eps = 1e-7;

double t1, t2;
point c, a, b;

void readpoint(point &p) {
  double x, y;
  scanf("%lf %lf", &x, &y);
  p = point(x, y);
}

bool inter(point a, double r_a, point b, double r_b, point c, double r_c) { //ÒÔcÎªÖ÷Ô²Çóa b½¹µãÅÐÏà½»
  if (abs(c - a) <= r_a && abs(c - b) <= r_b) return true;
  b -= a; c -= a; //ÒÔaÎªÔ­µã
  point r = point(b.real() / abs(b), b.imag() / abs(b)); //½«xÖáÕý·½ÏòÖÃÎªb
  b /= r; c /= r;
  double d = (r_a * r_a - r_b * r_b + abs(b) * abs(b)) / (2 * abs(b));
  double h = sqrt(max(r_a * r_a - d * d, 0.0));
  if (abs(h * h + (d - abs(b)) * (d - abs(b))) - r_b * r_b > eps) return false;
  if (abs(point(d, h) - c) <= r_c || abs(point(d, -h) - c) <= r_c) return true;
  return false;
}

bool check(point a, double r_a, point b, double r_b, point c, double r_c) { //ÅÐ¶ÏÈýÔ²ÊÇ·ñÏà½»
  if (r_a <= eps || r_b <= eps || r_c <= eps) return false; //ÓÐ¿Õ¼¯
  if (inter(a, r_a, c, r_c, b, r_b)) return true;
  if (inter(b, r_b, a, r_a, c, r_c)) return true;
  if (inter(c, r_c, b, r_b, a, r_a)) return true;
  return false;
}

int main() {
    scanf("%lf %lf", &t2, &t1);
    readpoint(a); readpoint(b); readpoint(c);
    double T1 = t1+abs(a-b), T2 = t2+abs(a-c)+abs(c-b);
    if(T1>=abs(a-c)+abs(b-c)) {
        printf("%.5f\n", min(T1, T2));
        return 0;
    }
    double l = 0, r = min(T2, T1);
    while(fabs(r-l)>eps) {
        double m = (l+r)/2;
        if(check(a, m, b, T1-m, c, T2-abs(b-c)-m))
            l = m;
        else
            r = m;
    }
    printf("%.6f\n", l);
    return 0;
}

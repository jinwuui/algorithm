#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pdd = pair<double, double>;

double ccw(pdd &p1, pdd &p2, pdd &p3) {
	return p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y - (p1.Y * p2.X + p2.Y * p3.X + p3.Y * p1.X);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pdd> v(n);
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &v[i].X, &v[i].Y);

	double ret = 0;
	for (int i = 1; i < n - 1; i++) {
		double val = ccw(v[0], v[i], v[i + 1]);
		ret += val;
	}
	printf("%.1lf", abs(ret) / 2);
	return 0;
}
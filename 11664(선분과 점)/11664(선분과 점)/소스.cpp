#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

struct point {
	double x, y, z;
};

point a, b, c;

double cal(point now) {
	return sqrt((now.x - c.x) * (now.x - c.x) + (now.y - c.y) * (now.y - c.y) + (now.z - c.z) * (now.z - c.z));
}

int main() {
	cin >> a.x >> a.y >> a.z;
	cin >> b.x >> b.y >> b.z;
	cin >> c.x >> c.y >> c.z;

	double ans = 987654321;

	while (true) {
		point mid;
		mid.x = (a.x + b.x) / 2.0;
		mid.y = (a.y + b.y) / 2.0;
		mid.z = (a.z + b.z) / 2.0;

		double ld = cal(a);
		double d = cal(mid);
		double rd = cal(b);
		
		ans = min(ans, d);

		if (abs(rd - ld) <= 0.000000000001) break;

		

		if (rd < ld) {
			a.x = mid.x;
			a.y = mid.y;
			a.z = mid.z;
		}
		else {
			b.x = mid.x;
			b.y = mid.y;
			b.z = mid.z;
		}
	}

	printf("%.10lf", ans);
}
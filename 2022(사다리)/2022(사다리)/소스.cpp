#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

double a, b, c;
double low = 0, high = 0;

double func(double mid) {
	double x = sqrt(a * a - mid * mid);
	double y = sqrt(b * b - mid * mid);

	return (x * y) / (x + y);
}

int main() {
	cin >> a >> b >> c;

	high = min(a, b);
	double result = 0;

	while (high - low >= 0.00001) {
		double mid = (low + high) / 2.0;

		if (func(mid) >= c) {
			result = mid;
			low = mid;
		}
		else high = mid;
	}

	printf("%.3lf", result);
}
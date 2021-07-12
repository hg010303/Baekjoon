#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int a, b, c;

int main() {
	int cnt = 1e7;
	cin >> a >> b >> c;

	double low = max((double)(c-b)/a,(double)0);
	double high = (double)(b+c)/a;
	double result = 0;


	while (high - low >= 1e-10&&cnt) {
		double mid = (low + high) / 2;

//		cout << mid << endl;

		double ans = a * mid + b * sin(mid);

		result = mid;
		if (ans < c) low = mid;
		if (ans > c)high = mid;
		cnt--;
	}
	printf("%.11f", result);
	
}
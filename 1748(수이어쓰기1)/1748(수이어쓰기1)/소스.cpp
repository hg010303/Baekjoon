#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 0;
	int b = 1;
	int n1 = n;
	while (n1 != 0) {
		n1 /= 10;
		a++;
		b *= 10;
	}
	b /= 10;
	int ans = 0;
	int c = 1;
	for (int i = 1; i < a; i++) {

		ans += i * 9 * c;
		c *= 10;
	}

	ans += a * (n - b + 1);

	cout << ans;






}
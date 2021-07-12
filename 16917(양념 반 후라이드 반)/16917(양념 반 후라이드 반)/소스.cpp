#include<iostream>
#include<algorithm>

using namespace std;

int a, b, c;
int x, y;

int main() {
	cin >> a >> b >> c;
	cin >> x >> y;
	
	int ans = 0;

	if (a >= 2 * c && b >= 2 * c) {
		if (x >= y) cout << 2 * x * c;
		else cout<< 2 * y * c;
	}
	else if (a >= 2 * c) {
		if (x >= y) cout << 2 * x * c;
		else cout << 2 * x * c + (y - x) * b;
	}

	else if (b >= 2 * c) {
		if (y >= x) cout << 2 * y * c;
		else cout << 2 * y * c + (x - y) * a;
	}
	else if (a + b >= 2 * c) {
		if (x >= y) cout << 2 * y * c + a * (x - y);
		else cout << 2 * x * c + b * (y - x);
	}
	else {
		cout << x * a + y * b;
	}

}
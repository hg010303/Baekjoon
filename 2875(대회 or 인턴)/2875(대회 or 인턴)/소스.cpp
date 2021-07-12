#include<iostream>
#include<algorithm>

using namespace std;

int ans = 0;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	while (true) {
		if (k <= (n + m - 3) && n >= 2 && m >= 1) {
			n -= 2;
			m -= 1;
			ans++;
		}
		else break;
	}
	cout << ans;
}
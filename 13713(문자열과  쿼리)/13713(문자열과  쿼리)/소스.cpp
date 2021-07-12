#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int MX = 1e6 + 5;
const long long D = (1ll << 50);
char a[MX];
long long b[MX];
long long ha[MX];

int n, m;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	cin >> a + 1;
	n = strlen(a + 1);
	b[0] = 1;

	for (i = 1; i <= n; i++) {
		b[i] = b[i - 1] * 26 % D;
		ha[i] = (ha[i - 1] * 26 + a[i] - 'a') % D;
	}

	cin >> m;

	while (m--) {
		int k;
		cin >> k;

		int ans = 0;
		int left = 1;
		int right = k;

		while (right >= left) {
			int mid = (left + right) / 2;
			if ((ha[n] - ha[n - mid] * b[mid] % D + D) % D == (ha[k] - ha[k - mid] * b[mid] % D + D) % D) {
				ans = mid;
				left = mid + 1;
			}
			else right = mid - 1;
		}
		cout << ans << '\n';
	}


}
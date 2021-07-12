#include<iostream>
#include<algorithm>

using namespace std;

long long n, k;

bool chk(long long mid) {
	long long cnt = 0;

	for (long long i = 1; i <= n; i++) {
		cnt += min(n, mid / i);
	}

	if (cnt >= k) return true;
	else return false;
}

int main() {
	cin >> n >> k;

	long long low = 1;
	long long high = n * n;
	long long ans = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;

		if (chk(mid)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}

	cout << ans << endl;

}
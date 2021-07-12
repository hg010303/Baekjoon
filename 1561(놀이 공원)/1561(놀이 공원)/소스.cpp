#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> v;

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	long long low = 0;
	long long high = 60000000000;
	long long ans = 0;
	long long ans1 = 0;
	if (n <= m) {
		cout << n;
		return 0;
	}

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long cnt = m;
		for (int i = 0; i < m; i++) {
			cnt += mid / v[i];
		}

		if (cnt >= n) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
		
	}

	ans1 = m;
	for (int i = 0; i < m; i++) ans1 += (ans - 1) / v[i];

	for (int i = 0; i < m; i++) {
		if (ans % v[i] == 0) ans1++;
		if (ans1 == n) {
			cout << i + 1 << endl;
			break;
		}
	}
}
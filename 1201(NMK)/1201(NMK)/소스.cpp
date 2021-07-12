#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	if (m + k - 1 <= n && n <= m * k) {
		vector<int> arr(n);
		for (int i = 0; i < n; i++) arr[i] = i + 1;

		int idx = 0;

		for (int i = 1; i <= m;i++) {
			int tmp = min(idx + k, n - m + i);

			reverse(arr.begin() + idx, arr.begin() + tmp);
			idx = tmp;
		}

		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << '\n';
	}
	else {
		cout << -1;
	}
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	for (int a = 0; a <= n; a++) {
		int b = n - a;
		if (a * b < k) continue;

		vector<int> a_cnt(b + 1, 0);
		for (int i = 0; i < a; i++) {
			int x = min(k, b);
			a_cnt[x]++;
			k -= x;
		}

		for (int i = b; i >= 0; i--) {
			for (int j = 0; j < a_cnt[i]; j++) cout << 'A';
			if (i > 0)cout << 'B';
		}
		return 0;
	}

	cout << -1;
}
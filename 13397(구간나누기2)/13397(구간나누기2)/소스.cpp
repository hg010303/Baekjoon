#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> v;
int m1=0, m2=978654321;

bool chk(int mid) {
	int cnt = 1;
	int mini = 987654321;
	int maxi = 0;

	for (int i = 0; i < n; i++) {
		mini = min(mini, v[i]);
		maxi = max(maxi, v[i]);

		if (maxi - mini > mid) {
			cnt++;
			mini = v[i];
			maxi = v[i];
		}
	}

	if (cnt <= m) return true;
	else return false;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		m1 = max(a, m1);
		m2 = min(a, m2);
	}

	int low = 0;
	int high = m1 - m2;
	int ans = 0;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (chk(mid)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}

	cout << ans << endl;
}
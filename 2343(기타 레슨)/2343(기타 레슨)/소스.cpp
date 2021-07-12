#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> v;
int maxi = 0;
int sum = 0;

bool chk(int mid) {
	int cnt = 1;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += v[i];
		if (tmp > mid) {
			cnt++;
			tmp = v[i];
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
		maxi = max(maxi, a);
		sum += a;
	}

	int low = maxi;
	int high = sum;
	int ans = 0;

	while (low <= high) {
		int mid = (high + low) / 2;

		if (chk(mid)) {
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}

	cout << ans << endl;

}
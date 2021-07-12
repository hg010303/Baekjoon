#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, k;
vector<int> v;

bool f(int mid) {
	int cnt = 0;
	for (int i = 0; i < v.size()-1; i++) {
		int dist = v[i + 1] - v[i];
		if (dist < mid) continue;
		if (dist % mid == 0) cnt += dist / mid - 1;
		else cnt += dist / mid;
	}
//	cout << cnt << endl;
	return cnt <= m;
}

int main() {
	cin >> n >> m >> k;

	v.push_back(0);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	v.push_back(k);

	sort(v.begin(),v.end());


	int low = 1;
	int high = k-1;
	int ans = high;

	while (low <= high) {
		int mid = low + high >> 1;

//		cout << mid << endl;
		if (f(mid)) {
			ans = min(ans, mid);
			high = mid - 1;
			
		}
		else {
			low = mid + 1;
		}
	}
	cout << ans << endl;
}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int k, l;
vector<int> v;

bool f(int mid) {
	int start = v[0];
	int cnt = 1;

	for (int i = 1; i < v.size(); i++) {
		if (v[i] >= start + mid) {
			cnt++;
			start = v[i];
		}
	}

	return k >= cnt;
}

int main() {
	cin >> n >> m;
	cin >> k >> l;
	
	int low = 1;
	int high = max(n, m);
	int maxi = 0;
	for (int i = 0; i < l; i++) {
		int a, b;
		cin >> a >> b;
		
		v.push_back(b);

		maxi = max(maxi, a);
	}
	sort(v.begin(), v.end());
	low = maxi;
	int ans = high;


	while (low <= high) {
		int mid = (low + high) / 2;

		if (f(mid)) {
			ans = min(ans, mid);
			high = mid - 1;
		}
		else low = mid + 1;
	}

	cout << ans << endl;
}
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, tmp, cnt = 0;
	vector<int> v;

	v.push_back(INT_MIN);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp > v.back()) {
			v.push_back(tmp);
			cnt++;
		}
		else {
			vector<int>::iterator low = lower_bound(v.begin(), v.end(), tmp);
			*low = tmp;
		}
	}
	cout << cnt;
}
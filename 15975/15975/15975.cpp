#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long> point[100100];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		point[b].push_back(a);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		sort(point[i].begin(), point[i].end());
		if (point[i].size() == 0 || point[i].size() == 1) continue;

		for (int j = 1; j < point[i].size()-1; j++) {
			if (point[i][j] - point[i][j - 1] > point[i][j + 1] - point[i][j]) ans += point[i][j + 1] - point[i][j];
			else ans += point[i][j] - point[i][j - 1];
		}
		ans += point[i][1] - point[i][0];
		ans += point[i][point[i].size() - 1] - point[i][point[i].size() - 2];
	}
	cout << ans << endl;
}
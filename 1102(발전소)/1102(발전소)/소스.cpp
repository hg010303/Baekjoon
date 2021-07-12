#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

const int INF = 987654321;

int n;
int arr[17][17];
int dp[(1 << 16)];
int p = 0;
int cnt = 0;


int f(int idx, int bin) {
	if (idx == p) {
		return 0;
	}

	int& ret = dp[bin];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 0; i < n; i++) {
		if (bin & (1 << i)) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;

				if ((bin & (1 << j)) == 0) ret = min(ret, f(idx + 1, bin | (1 << j)) + arr[i][j]);
			}
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	string str;

	cin >> str;

	int bin = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'Y') {
			bin = bin | (1 << i);
			cnt++;
		}
	}
	cin >> p;

	if (cnt == 0) {
		if (p == 0) cout << 0;
		else cout << -1;
	}
	else if (cnt >= p) cout << 0;
	else cout << f(cnt, bin);
	
}
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
	int n, s, m;
	cin >> n >> s >> m;

	int arr[110];
	int dp[110][1100];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1][s] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j] == 1) {
				if (j - arr[i] >= 0) dp[i + 1][j - arr[i]] = 1;
				if (j + arr[i] <= m) dp[i + 1][j + arr[i]] = 1;
			}
		}
	}

	int ans = -1;
	for (int i = 0; i <= m; i++) {
		if (dp[n+1][i] == 1) ans = i;
	}
	cout << ans << endl;
}
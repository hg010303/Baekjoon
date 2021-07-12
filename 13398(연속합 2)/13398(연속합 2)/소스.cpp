#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[100100];
int dp[100100][2];
int ans = -2000000000;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[1][0] = arr[1];
	dp[1][1] = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 1; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}
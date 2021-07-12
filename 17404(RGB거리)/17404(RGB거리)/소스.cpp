#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[1010][3];
int dp[1010][3][3];
int i;
int n;

int main() {
	cin >> n;
	memset(dp, 98765432, sizeof(dp));
	int ans = 987654321;

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	dp[0][0][0] = arr[0][0];
	dp[0][1][1] = arr[0][1];
	dp[0][2][2] = arr[0][2];

	for (i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][0][j] = min(dp[i - 1][1][j], dp[i - 1][2][j]) + arr[i][0];
			dp[i][1][j] = min(dp[i - 1][0][j], dp[i - 1][2][j]) + arr[i][1];
			dp[i][2][j] = min(dp[i - 1][0][j], dp[i - 1][1][j]) + arr[i][2];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) {
				ans = min(dp[n - 1][i][j], ans);
			}
		}
	}

	cout << ans;
	
}
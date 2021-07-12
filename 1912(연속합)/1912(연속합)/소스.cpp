#include<iostream>

using namespace std;

int arr[100100];
int dp[100100];

int main() {
	int n;
	cin >> n;


	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] = arr[0];
	int ans = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (ans < dp[i]) ans = dp[i];
	}

	cout << ans;

}
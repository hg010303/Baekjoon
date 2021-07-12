#include<iostream>

using namespace std;

int main() {
	int n, maxi = 0;

	cin >> n;

	int arr[1010];
	int dpi[1010] = { 0, };
	int dpd[1010] = { 0, };
	dpd[n + 1] = 0;
	int dp[1010];

	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		dpi[i] = 1;
		dpd[n - i + 1] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dpi[j] + 1 > dpi[i]) dpi[i] = dpi[j] + 1;
			if (arr[n - i + 1] > arr[n - j + 1] && dpd[n - j + 1] + 1 > dpd[n - i + 1]) dpd[n - i + 1] = dpd[n - j + 1] + 1;

		}
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = dpi[i] + dpd[i];
		maxi = max(maxi, dp[i]);
	}
	cout << maxi - 1;
}
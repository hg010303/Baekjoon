#include<iostream>
#include<cstring>

using namespace std;

int arr1[550];
int arr2[550];
int dp[550][550];


int go(int i, int j) {
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int ans = dp[i][j];

	for (int t = i; t < j; t++) {
		int tmp = go(i,t) + go(t + 1,j) + arr1[i]*arr2[t]*arr2[j];
		if (ans == -1 || ans > tmp) ans = tmp;
	}
	return dp[i][j]=ans;
}

int main() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) cin >> arr1[i]>>arr2[i];

	cout << go(0, n - 1) << endl;

}
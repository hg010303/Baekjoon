#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int arr[1010];
int dp[1010][31];
int t, w;


int go(int i, int j) {
	if (i == t + 1 && j <= w) return 0;
	if (j > w) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = max(go(i + 1, j), go(i + 1, j + 1)) + ((j % 2 == arr[i] - 1) ? 1 : 0);
	return dp[i][j];
}

int main() {

	cin >> t >> w;

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= t; i++) cin >> arr[i];

	cout << max(go(1,0),go(1,1)) << endl;
}
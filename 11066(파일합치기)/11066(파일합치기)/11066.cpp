#include<iostream>
#include<cstring>

using namespace std;
int arr[510] = {};
int dp[510][510] = {};
int sum[510] = {};

int go(int i, int j) {
	if (i == j) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	int &tmp = dp[i][j];
	
	for (int t = i; t < j; t++) {
		int cmd = go(i, t) + go(t + 1, j) + sum[j] - sum[i - 1];
		if (tmp == -1 || tmp > cmd) {
			tmp = cmd;
		}
		
	}
	return tmp;
}

int main() {
	int T;
	cin >> T;

	while(T--){
		int n;
		cin >> n;
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		cout << go(1, n) << endl;
	

	}

}
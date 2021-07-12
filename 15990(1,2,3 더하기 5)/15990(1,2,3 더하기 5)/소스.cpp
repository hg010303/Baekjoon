#include<iostream>
#include<cstring>
#define CON 1000000009

using namespace std;

int dp[100100][3];



int main() {
	int n;
	cin >> n;

	dp[1][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = dp[3][1] = dp[3][2] = 1;

	for (int i = 4; i <= 100000; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % CON;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % CON;
		dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % CON;
	}

	while (n--) {
		int a;
		cin >> a;

		long long ans = dp[a][0];
		ans += dp[a][1];
		ans %= CON;
		ans += dp[a][2];
		ans %= CON;

		cout << ans<<endl;
	}
}
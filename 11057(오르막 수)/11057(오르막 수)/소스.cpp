#include<iostream>
#define CON 10007
using namespace std;

int dp[1010][10];

int f(int n, int k) {
	if (dp[n][k]) return dp[n][k];
	if (n == 0) return 0;

	int ans = 0; 
	for (int j = 0; j <= k; j++) {
		ans += f(n - 1, j);
	}
	ans %= CON;

	return dp[n][k]=ans;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++) dp[1][i] = 1;

	int ans = 0;

	for (int i = 0; i < 10; i++) ans += f(n, i);

	ans %= CON;

	cout << ans;
	
}
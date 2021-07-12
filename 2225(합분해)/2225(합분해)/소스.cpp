#include<iostream>
#include<algorithm>
#define CON 1000000000
using namespace std;

long long dp[202][202];
int n, k;

long long f(int n, int k) {
	if (dp[n][k]) return dp[n][k];
	if (k == 1) return 1;
	if (n == 0) return 1;
	int ans = 0;

	for (int i = n; i >= 0; i--) {
		ans += f(n - i, k-1);
		ans %= CON;
	}

	dp[n][k] = ans;
	return ans;

}

int main() {
	cin >> n >> k;

	cout << f(n, k);
}
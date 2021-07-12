#include<iostream>
#define CON 9901

using namespace std;

int dp[100100][2];

int f(int n, int k) {
	if (dp[n][k]) return dp[n][k];
	if (n == 0) return 0;
	int ans = 0;
	if (k == 0) {
		ans += f(n - 1, 1)*2 + f(n - 1, 0);
		ans %= CON;
	}
	if (k == 1) {
		ans += f(n - 1, 1)+ f(n - 1, 0);
		ans %= CON;
	}
	return dp[n][k]=ans;
}


int main() {
	int n;
	cin >> n;
	dp[1][0] = 2;
	dp[1][1] = 1;

	cout << (f(n,0)+f(n,1))%CON;
}
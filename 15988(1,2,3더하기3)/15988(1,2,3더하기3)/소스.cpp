#include<iostream>
#define CON 1000000009

using namespace std;

long long dp[1000100] = { 0,1,2,4 };

long long f(int n) {
	if (dp[n]) return dp[n];
	if (n <= 0) return 0;
	long long ans = f(n - 1) + f(n - 2);
	ans %= CON;
	ans += f(n - 3);
	ans %= CON;
	return dp[n] = ans;

}

int main() {
	int n;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;

		cout << f(a) << endl;
	}
}
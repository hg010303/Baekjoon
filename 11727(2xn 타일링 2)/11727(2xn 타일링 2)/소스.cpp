#include<iostream>
using namespace std;

int dp[1010];

int f(int n) {
	if (dp[n]) return dp[n];
	if (n == 1) return 1;
	if (n == 0) return 0;
	if (n == 2) return 3;

	return dp[n] = (f(n - 2) * 2 + f(n - 1)) %10007;

}


int main() {
	int n;
	cin >> n;

	cout << f(n);
}
#include<iostream>
#include<algorithm>

using namespace std;

const int CON = 1000000007;

long long dp[5100];

long long f(int a) {
	if (a == 0) return 1;
	if ( a % 2 == 1) return 0;
	if (a == 2) return 1;
	if (dp[a]) return dp[a];

	long long su = 0;

	for (int i = 2; i <= a; i += 2) {
		long long k = f(i-2) * f(a - i);
		k %= CON;
		su += k;
		su %= CON;
	}

	return dp[a]=su;

	
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;

		cout << f(a) << '\n';
	}
}
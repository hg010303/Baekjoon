#include<iostream>
#include<algorithm>

using namespace std;

long long dp[31][31];

long long f(int a, int b) {
	if (b < 0 || a < 0) return 0;
	if (a==0) return 1;

	long long &ret = dp[a][b];
	if (ret) return ret;

	ret = f(a - 1, b + 1) + f(a, b - 1);
	return ret;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int n;
		cin >> n;

		if (n == 0) return 0;

		cout << f(n, 0)<<'\n';
	}
}
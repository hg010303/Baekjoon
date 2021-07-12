#include<iostream>
#include<cstring>

using namespace std;

const int CON = 1000000007;
int n;
int a, b, c;
long long dp[55][55][55][55];

long long f(int n,int a, int b, int c) {
	if (a < 0 || b < 0 || c < 0) return 0;
	if (dp[n][a][b][c] != -1) return dp[n][a][b][c];

	if (n == 0) {
		if (a == 0 && b == 0 && c == 0) return 1;
		else return 0;
	}
	if (n > a + b + c) return 0;

	long long tmp = 0;

	tmp += f(n - 1, a - 1, b, c);
	tmp += f(n - 1, a, b - 1, c);
	tmp %= CON;
	tmp += f(n - 1, a, b, c - 1);
	tmp %= CON;
	tmp += f(n - 1, a - 1, b-1, c);
	tmp %= CON;
	tmp += f(n - 1, a - 1, b, c-1);
	tmp %= CON;
	tmp += f(n - 1, a , b-1, c - 1);
	tmp %= CON;
	tmp += f(n - 1, a-1, b - 1, c - 1);
	tmp %= CON;

	return dp[n][a][b][c]=tmp;
}

int main() {
	cin >> n;
	cin >> a >> b >> c;
	memset(dp, -1, sizeof(dp));

	cout<<f(n, a, b, c);
}
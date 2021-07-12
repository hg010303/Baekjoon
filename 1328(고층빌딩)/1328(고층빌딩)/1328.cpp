#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[103][103][103];
int n, l, r;

int go(int n, int l, int r) {
	if (dp[n][l][r] != 0) return dp[n][l][r];

	if (n <= 0) return 0;
	if (n == 1 && l == 1 && r == 1) return 1;

	if(n>=3) dp[n][l][r] +=(n-2)* go(n - 1, l, r);
	if (l > 1) dp[n][l][r] += go(n - 1, l - 1, r);
	if (r > 1) dp[n][l][r] += go(n - 1, l, r - 1);

	return dp[n][l][r];
	
}

int main() {

	cin >> n >> l >> r;

	d[1][1][1] = 1LL;

}
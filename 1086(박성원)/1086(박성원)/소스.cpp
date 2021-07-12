#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n, k;
string arr[20];
int arr_mod[20];
int length[20];
int ten_mod[51];
long long dp[(1 << 15)][101];

int integerlen(int n) {
	int cnt = 0;
	while (n) {
		cnt++;
		n /= 10;
	}
	return cnt;
}

long long gcd(long long a, long long b) {
	if (a < b) {
		long long tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) return a;

	return gcd(b, a % b);
}

long long factorial(int n) {
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		length[i] = arr[i].size();
	}
	cin >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < length[i]; j++) {
			arr_mod[i] *= 10;
			arr_mod[i] += arr[i][j] - '0';
			arr_mod[i] %= k;
		}
	}
	ten_mod[0] = 0;
	ten_mod[1] = 10%k;
	for (int i = 2; i <= 50; i++) {
		ten_mod[i] = (ten_mod[i - 1] * 10) % k;
	}

	dp[0][0] = 1;

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < n; l++) {
				if ((i & (1 << l)) == 0) {
					int next = j * ten_mod[length[l]];
					next %= k;
					next += arr_mod[l];
					next %= k;
					dp[i | (1 << l)][next] += dp[i][j];
				}
			}
		}
	}

	long long ans = dp[(1 << n) - 1][0];
	long long ans2 = factorial(n);

	long long g = gcd(ans, ans2);
	ans /= g;
	ans2 /= g;

	cout << ans << '/' << ans2 << endl;

}
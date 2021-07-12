#include<iostream>
#include<algorithm>

using namespace std;

int n;
double arr[21][21];
double dp[(1 << 20)] = { 1, };

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;

			arr[i][j] = a / (double)100;
		}
	}

	for (int i = 0; i < (1<<n); i++) {
		int cnt = 0;
		int tmp = i;

		while (tmp > 0) {
			if (tmp % 2 == 1) cnt++;
			tmp /= 2;
		}
		
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) == 0) {
				dp[i | (1 << j)] = max(dp[(i | (1 << j))], dp[i] * arr[j][cnt]);
			}
		}
	}

	printf("%.8lf", dp[(1 << n) - 1] * 100);
}
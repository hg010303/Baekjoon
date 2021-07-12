#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define MAX 251

using namespace std;

int n;
int a[MAX];
int b[MAX];
int dp[100000][252];



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	memset(dp, -1, sizeof(dp));

	dp[a[0]][0] = 0;
	dp[0][0] = b[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 62500; j++) {
			if (dp[j][i - 1]!=-1) {
				int t1 = j;
				int t2 = dp[j][i - 1];
				
				t1 += a[i];
				int mini = t1;
				if (t1 > t2) mini = t2;

				if (dp[t1][i]==-1) dp[t1][i] = t2;
				else {
					if (dp[t1][i] > t2) dp[t1][i] = t2;
				}

				////////////

				t1 = j;
				t2 = dp[j][i - 1];

				t2 += b[i];
				mini = t1;
				if (t1 > t2) mini = t2;

				if (dp[t1][i]==-1) dp[t1][i] = t2;
				else {
					if (dp[t1][i] > t2) dp[t1][i] = t2;
				}

			}
		}
	}

	int ans = 987654321;
	int a;
	for (int i = 1; i <=62500; i++) {
		if (n>=1&&dp[i][n - 1]==-1)continue;
		if (n >= 1) {
			if (i > dp[i][n - 1]) a = i;
			else a = dp[i][n - 1];
		}

		if (ans > a) ans = a;
	}

	cout << ans;
}
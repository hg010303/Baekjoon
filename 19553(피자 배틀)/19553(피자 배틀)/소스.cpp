#include<iostream>
#include<algorithm>

using namespace std;

int dp[1010][1010][202];
int n;
int arr[1010];
int su[1010];

int f(int l, int r, int t) {
	if (t < 0) {
		int sum = 0;
		int i = l;

		if (l <= r) sum = su[r] - su[l - 1];
		else {
			sum = su[n]  - su[l - 1] + su[r];
		}
		return sum - f(l, r, -t);
	}


	if (dp[l][r][t]) return dp[l][r][t];
	if (l == r) {
		 return dp[l][r][t]=arr[l];
	}

		int a, b;
		if (l == n ) a = f(1, r, t - 2 * arr[n]) + arr[n];
		else a = f(l + 1, r, t - 2 * arr[l]) + arr[l];
		if (r == 1) b = f(l, n , t - 2 * arr[1]) + arr[1];
		else b = f(l, r - 1, t - 2 * arr[r]) + arr[r];
		
		return dp[l][r][t]= max(a, b);
		
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		su[i] = su[i - 1] + arr[i];
	}

	if (n == 1) {
		cout << arr[1] << endl;
		return 0;
	}



	int ans = f(2, n , 1-2*arr[1])+arr[1];
	ans=max(ans, f(1, n - 1, 1 - 2 * arr[n]) + arr[n]);
	for (int i = 2; i < n ; i++) {
		ans=max(ans,f(i + 1, i - 1, 1-2*arr[i])+arr[i]);
	}
	
	cout << ans << endl;
}
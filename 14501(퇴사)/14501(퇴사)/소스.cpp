#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int t[16];
int p[16];
int memo[30];


int main() {
	int maxi = 0;
	cin >> n;
	memset(memo, 0, sizeof(memo));

	for (int i = 0; i < n; i++) cin >> t[i] >> p[i];

	for (int i = 0; i < n; i++) {
		maxi = max(maxi, memo[i]);
		memo[i + t[i]] = max(memo[i + t[i]], maxi + p[i]);
		memo[i + t[i]] = max(memo[i+t[i]],memo[i] + p[i]);
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) ans=max(ans, memo[i]);

	cout << ans;
}
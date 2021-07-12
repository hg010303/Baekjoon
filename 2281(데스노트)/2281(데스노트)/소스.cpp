#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m;
int dp[1010][1010];
int arr[1010];

int f(int idx, int col) {
	if (idx == n) return 0;

	if (col >= m) return f(idx + 1, arr[idx] + 1) + (col == m ? 1 : 0);

	int& ret = dp[idx][col];

	if (ret != -1) return ret;

	ret = f(idx + 1, arr[idx] + 1) + (m - col + 1) * (m - col + 1);

	if (col + arr[idx] <= m) ret = min(ret, f(idx+1,col + arr[idx] + 1));
	return ret;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));

	cout<<f(1,arr[0]+1);

}
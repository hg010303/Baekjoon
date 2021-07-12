#include<iostream>
#include<cstring>

using namespace std;

int dp[100100][3];
int n;
int arr[100100][2];

//k:0 µÑ´Ù ¾È¾¸, k=1 ¾Æ·¡²¨¸¸ ¾¸, k=2 À§¿¡²¨¸¸ ¾¸

int f(int n, int k) {
	if (dp[n][k]!=-1) return dp[n][k];
	if (n < 0) return 0;

	if (k == 0) {
		return dp[n][k]=max(max(f(n - 1, 0), f(n - 1, 1)), f(n - 1, 2));
	}
	if (k == 1) {
		return dp[n][k] = max(f(n - 1, 0), f(n - 1, 2)) + arr[n][1];
	}
	else return dp[n][k] = max(f(n - 1, 0), f(n - 1, 1)) + arr[n][0];

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) cin >> arr[i][0];
		for (int i = 0; i < n; i++) cin >> arr[i][1];

		cout << max(max(f(n-1, 1),f(n-1,0)),f(n-1,2))<<"\n";
	}
}
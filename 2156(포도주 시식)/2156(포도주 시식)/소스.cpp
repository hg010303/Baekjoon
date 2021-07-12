#include<iostream>
#include <cstring>

using namespace std;

int arr[10100];
int dp[10100][3];

//k:0 ���� �� ���� ����, k:1 ���� �� ù��° ������ k:2 ������ 2��° ������

int f(int n, int k) {
	if (dp[n][k] != -1) return dp[n][k];
	if (n < 0) return 0;

	if (k == 0) return dp[n][k] = max(f(n - 1, 0), f(n - 1, 1));
	else if (k == 1) return dp[n][k] = max(f(n - 1, 0), f(n - 1, 2)) + arr[n];
	else return dp[n][k] = f(n - 1, 0) + arr[n];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	memset(dp, -1, sizeof(dp));

	cout << max(f(n-1, 0), f(n-1, 1));
}
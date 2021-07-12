#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

const int CON = 5000;
int n, m;
int N;
int dp[CON + 10];
int arr[12];

void f(int x) {
	if (x >= n) return;

	for (int i = 0; i < m; i++) {
		int now = x - arr[i];
	}
}

int main() {
	cin >> N;

	while (N--) {



		memset(dp, -1, sizeof(dp));
		cin >> n >> m;
		
		for (int i = 0; i < m; i++) cin >> arr[i];

		sort(arr, arr + n, less<int>());
		f(n);
	}
}
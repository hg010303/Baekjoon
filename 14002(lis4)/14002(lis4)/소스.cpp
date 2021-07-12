#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dp[1010];
int arr[1010];
int f[1010];

vector<int> v;


void go(int n) {
	if (n == 0) return;
	v.push_back(arr[n]);
	go(f[n]);
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		if (dp[i] == 0) dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					f[i] = j;
				}
			}
		}
	}

	int maxi = 0;
	int a = 0;
	for (int i = 1; i <= n; i++) {
		if (maxi < dp[i]) {
			maxi = dp[i];
			a = i;
		}
	}

	cout << maxi << endl;
	go(a);
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}
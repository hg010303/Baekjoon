#include<iostream>
#include<algorithm>

using namespace std;

int n, k;
int arr[11];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[n-1-i];

	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += k / arr[i];
		k %= arr[i];
	}

	cout << ans;
}
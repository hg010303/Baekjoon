#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1010];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += arr[i] * (n - i);
	}

	cout << ans;
}
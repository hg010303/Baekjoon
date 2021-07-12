#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;

	int arr[10];
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += (abs(arr[i] - arr[i + 1]));
		}
		ans = max(sum, ans);
	} while (next_permutation(arr, arr + n));

	cout << ans;

}
#include<iostream>
#include<algorithm>

using namespace std;
int arr[500500];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int k;
	cin >> k;

	while (k--) {
		int a;
		cin >> a;

		cout << upper_bound(arr, arr + n, a) - lower_bound(arr, arr + n, a)<<" ";
	}
}
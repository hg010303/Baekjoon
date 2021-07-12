#include<iostream>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int t;
	cin >> t;

	int arr[101];

	while (t--) {
		int n;
		long long ans = 0;
		cin >> n;

		for (int i = 0; i < n; i++) cin >> arr[i];

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				ans+=gcd(arr[i], arr[j]);
			}
		}
		cout << ans << endl;
	}
}
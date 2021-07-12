#include<iostream>

using namespace std;

int main() {
	int n, m;
	int arr[101];
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				if (ans < arr[i] + arr[j] + arr[k] && arr[i] + arr[j] + arr[k] <= m)
					ans = arr[i] + arr[j] + arr[k];
			}
		}
	}
	cout << ans;
}
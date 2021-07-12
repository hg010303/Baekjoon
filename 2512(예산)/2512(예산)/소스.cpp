#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[10100];
int m;

int maxi = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}
	cin >> m;

	int low = 0;
	int high = maxi;
	int result = 0;

	while (low <= high) {
		int mid = (low + high) / 2;

		int ans = 0;

		for (int i = 0; i < n; i++) {
			if (mid > arr[i]) ans += arr[i];
			else ans += mid;
		}

		
		if (ans <= m) {
			result = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << result << endl;

}
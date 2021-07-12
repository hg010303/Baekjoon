#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
long long arr[100100];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int left = 0;
	int right = n - 1;

	long long ans = arr[0] + arr[n - 1];

	int answer[2];
	answer[0] = arr[0];
	answer[1] = arr[n - 1];

	while (left < right) {
		long long now = arr[left] + arr[right];
		
		if (abs(ans) > abs(now)) {
			answer[0] = arr[left];
			answer[1] = arr[right];
			ans = now;
		}

		if (now == 0) break;
		else if (now > 0) right--;
		else left++;
	}

	cout << answer[0] << " " << answer[1];
}

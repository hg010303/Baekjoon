#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 270;

int n;
int arr[MAX];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;

	for (int i = n - 1; i > 0; i--) {
		int biggest = 0;
		int now = 0;
		for (int j = 0; j <= i; j++) {
			if (biggest < arr[j]) {
				biggest = arr[j];
				now = j;
			}
		}

		if (now == 0) ans += (biggest - arr[1]);
		else if (now == i) (ans += biggest - arr[i - 1]);
		else {
			ans += (biggest - max(arr[now - 1], arr[now + 1]));
		}

		for (int j = now + 1; j <= i; j++) {
			arr[j - 1] = arr[j];
		}


	}

	cout << ans << endl;
}
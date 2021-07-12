#include<iostream>
#include<algorithm>

using namespace std;

int arr[10010];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	int i = n - 1;
	while (i > 0 && arr[i - 1] > arr[i]) --i;

	if (i == 0) {
		cout << "-1";
		return 0;
	}

	int near = 10001;
	int index;

	for (int j = i; j < n; j++) {
		if (arr[i - 1] < arr[j] && arr[j] < near) {
			near = arr[j];
			index = j;
		}
	}

	int tmp = arr[i - 1];
	arr[i - 1] = arr[index];
	arr[index] = tmp;
	sort(arr + i, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";


}
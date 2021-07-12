#include<iostream>
#include<algorithm>

using namespace std;

int n, i, k, arr[10010];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (n == 1) {
		cout << "-1";
		return 0;
	}

	int p = n - 1;

	while (arr[p - 1] < arr[p]) {
		p--;
		if (p == 0) break;
	}
	if (p == 0) {
		cout << "-1";
		return 0;
	}

	for (k = n - 1; arr[p - 1] < arr[k]; k--);

	int tmp = arr[p - 1];
	arr[p - 1] = arr[k];
	arr[k] = tmp;

	sort(arr + p, arr + n, greater<int>());

	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
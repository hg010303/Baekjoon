#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[10000001];

int main() {
	for (int i = 1; i <= 10000000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= 10000000; i++) {
		if (arr[i] != i) continue;
		int tmp = i;

		for (int j = 2; tmp * j <= 10000000; j++) {
			arr[tmp * j] = tmp;
		}
	}

	int n;
	cin >> n;
	if (n == 1) {
		return 0;
	}
	vector<int> v;
	while (arr[n] != n) {
		v.push_back(arr[n]);
		n /= arr[n];
	}
	v.push_back(arr[n]);
	reverse(v.begin(), v.end());
	for (auto i : v) {
		cout << i << endl;
	}
}
#include<iostream>
#include<cstring>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	int arr[110];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int memo[10100] = {};
	memo[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			if (j + arr[i] <= k) memo[j + arr[i]] += memo[j];
	}

	cout << memo[k]<<endl;

	return 0;
}
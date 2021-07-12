#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	int arr[110];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int memo[10100];
	memset(memo, -1, sizeof(memo));
	memo[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			if (j + arr[i] <= k && memo[j] != -1)
			{
				if (memo[j + arr[i]] == -1)
					memo[j + arr[i]] = memo[j] + 1;
				else memo[j + arr[i]] = min(memo[j] + 1, memo[j + arr[i]]);
			}
	}

	cout << memo[k] << endl;

	return 0;
}
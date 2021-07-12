#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = -987654321;

int n;
int arr[410][2];
int length[2];
int memo[410][410][410];

int f(int i, int j, int k) {
	if (i == length[0] || j == length[1]) return 0;

	int& ret = memo[i][j][k];
	if (ret != INF) return ret;

	if (length[0] - i + k < n) ret = max(ret, f(i, j + 1, k + 1));
	if (length[1] - j + k < n) ret = max(ret, f(i + 1, j, k + 1));
	ret = max(ret, arr[i][0] * arr[j][1] + f(i + 1, j + 1, k + 1));
	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;

			if (a != 0) {
				arr[length[i]++][i] = a;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) memo[i][j][k] = INF;
		}
	}

	cout << f(0, 0, 0);
}
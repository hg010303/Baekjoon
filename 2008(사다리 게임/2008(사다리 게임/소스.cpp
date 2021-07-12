#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int INF = 987654321;

int n, m;
int a, b, x, y;

int arr[510];
int memo[510][110];

int main() {
	cin >> n >> m;
	cin >> a >> b >> x >> y;

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) memo[i][j] = INF;
	}


	for (int i = 1; i <= m; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		if (a == i) memo[0][i] = 0;
		else {
			memo[0][i] = y * abs(i - a);
		}
	}

	

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k) {
					if (arr[i] == j || arr[i] == j - 1) memo[i][k] = min(memo[i][k], memo[i - 1][j] + x);
					else memo[i][k] = min(memo[i][k],memo[i - 1][j]);
				}

				else if (j <= arr[i] && k <= arr[i]) memo[i][k] = min(memo[i][k], memo[i - 1][j] + y * abs(k - j));
				else if (j >= arr[i] + 1 && k >= arr[i] + 1) memo[i][k] = min(memo[i][k], memo[i - 1][j] + y * abs(k - j));
				else memo[i][k] = min(memo[i][k], memo[i - 1][j] + y * abs(k - j)-y);
			}
		}
	}

	//for (int i = 1; i <= n; i++) cout << memo[1][i] << " ";

	cout << memo[m][b];
}
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 50;
const int INF = 987654321;

int n, m;
bool arr[MAX][MAX];
bool result[MAX][MAX];

void f(int y, int x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			arr[i][j] = 1 - arr[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < m; j++)  arr[i][j] = str[j] - '0';
	}

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < m; j++)  result[i][j] = str[j] - '0';
	}

	int cnt = 0;
	bool change = false;

	if (n >= 3 && m >= 3) {
		for (int i = 0; i <= n - 3; i++) {
			for (int j = 0; j <= m - 3; j++) {
				if (arr[i][j] != result[i][j]) {
					f(i, j);
					cnt++;
				}

				bool same = true;
				for (int y = 0; y < n; y++) {
					for (int x = 0; x < m; x++) {
						if (arr[y][x] != result[y][x]) {
							same = false;
							break;
						}
					}
				}

				if (same == true) {
					change = true;
					break;
				}
			}
			if (change) break;
		}
	}

	else {
		change = true;
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				if (arr[y][x] != result[y][x]) change = false;
	}

	if (change) cout << cnt;
	else cout << -1;
}
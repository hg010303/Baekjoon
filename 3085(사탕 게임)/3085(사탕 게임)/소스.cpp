#include<iostream>
#include<algorithm>

using namespace std;

char map[52][52];
int ans = 0;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	int b = 1;

	for (int i = 1; i <= n; i++) {
		b = 1;
		for (int j = 2; j < n; j++) {
			
			if (map[i][j] == map[i][j-1]) b += 1;
			else {
				ans = max(b, ans);
				b = 1;
			}
			
		}
		ans = max(b, ans);
	}
	for (int j = 1; j <= n; j++) {
		b = 1;
		for (int i = 2; i <= n; i++) {
			if (map[i][j] == map[i-1][j]) b += 1;
			else {
				ans = max(b, ans);
				b = 1;
			}

		}
		ans = max(b, ans);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			int a = 1;
			swap(map[i][j], map[i + 1][j]);
			for (int k = 2; k <= n; k++) {
				if (map[i][k] == map[i][k - 1]) a += 1;
				else {
					ans = max(ans, a);
					a = 1;
				}
			}
			ans = max(ans, a);
			a = 1;
			for (int k = 2; k <= n; k++) {
				if (map[i+1][k] == map[i+1][k - 1]) a += 1;
				else {
					ans = max(ans, a);
					a = 1;
				}
			}
			ans = max(ans, a);
			a = 1;
			for (int k = 2; k <= n; k++) {
				if (map[k][j] == map[k-1][j]) a += 1;
				else {
					ans = max(ans, a);
					a = 1;
				}
			}
			ans = max(ans, a);
			swap(map[i][j], map[i + 1][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			int a = 1;
			swap(map[i][j], map[i][j+1]);
			for (int k = 2; k <= n; k++) {
				if (map[k][j] == map[k-1][j]) a += 1;
				else {
					ans = max(ans, a);
					a = 1;
				}
			}
			ans = max(ans, a);
			a = 1;
			for (int k = 2; k <= n; k++) {
				if (map[k][j+1] == map[k-1][j+1]) a += 1;
				else {
					ans = max(ans, a);
					a = 1;
				}
			}
			ans = max(ans, a);
			a = 1;
			for (int k = 2; k <= n; k++) {
				if (map[i][k] == map[i][k-1]) a += 1;
				else {
					ans = max(ans, a);
					a = 1;
				}
			}
			ans = max(ans, a);
			swap(map[i][j], map[i][j+1]);
		}
	}

	cout << ans;

	
}
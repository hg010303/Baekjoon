#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n, m;
int arr[4][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	int ans = 0;
	
	for (int b = 0; b < (1 << (n * m)); b++) {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int now = 0;
			for (int j = 0; j < m; j++) {
				int k = i * m + j;

				if ((b & (1 << k)) == 0) now = now * 10 + arr[i][j];
				else {
					sum += now;
					now = 0;
				}
			}
			sum += now;
		}

		for (int j = 0; j < m; j++) {
			int now = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;

				if ((b & (1 << k)) != 0) now = now * 10 + arr[i][j];
				else {
					sum += now;
					now = 0;
				}
			}
			sum += now;
		}
		if (ans < sum)ans = sum;
	}

	cout << ans;
}
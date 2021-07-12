#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int memo[22][22][22][22][22];
int n, l;
int arr[22][22];
int n1[8] = { 1,1,1,0,0,-1,-1,-1 };
int n2[8] = { 1,0,-1,1,-1,1,0,-1 };

int f(int x1, int y1, int x2, int y2, int cnt) {
	if (cnt == 0) return 1;
	if (cnt == 1) {
		if (x1 == x2 && y1 == y2) return 1;
		else return 0;
	}
	if (cnt == 2) {
		for (int i = 0; i < 8; i++) {
			int nx1 = x1 + n1[i];
			int ny1 = y1 + n2[i];

			if (nx1 < 0 || ny1 < 0 || nx1 >= n || ny1 >= n) continue;

			if (nx1 == x2 && ny1 == y2) return 1;
		}
		return 0;
	}

	int& ret = memo[x1][y1][x2][y2][cnt];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 8; i++) {
		int nx1 = x1 + n1[i];
		int ny1 = y1 + n2[i];

		if (nx1 < 0 || ny1 < 0 || nx1 >= n || ny1 >= n) continue;

		for (int j = 0; j < 8; j++) {
			int nx2 = x2 + n1[j];
			int ny2 = y2 + n2[j];

			if (nx2 < 0 || ny2 < 0 || nx2 >= n || ny2 >= n) continue;

			if (arr[nx1][ny1] == arr[nx2][ny2]) ret += f(nx1, ny1, nx2, ny2, cnt - 2);
		}
	}

	return ret;
}

int main() {
	cin >> n >> l;

	memset(memo, -1, sizeof(memo));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			memo[i][j][i][j][1] = 1;
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int m = 0; m < n; m++) {
					if (arr[i][j] == arr[k][m]) {
						ans += f(i, j, k, m, l);
					}
				}
			}


		}
	}

	cout << ans << endl;

}

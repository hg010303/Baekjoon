#include<iostream>
#include<algorithm>

using namespace std;

int arr[9][9];
bool col[9][10];
bool row[9][10];
bool square[9][10];

int func(int x, int y) {
	return (x / 3) * 3 + y / 3;
}

void dfs(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}

	int x = cnt / 9;
	int y = cnt % 9;

	if (arr[x][y]) dfs(cnt + 1);
	else {
		for (int k = 1; k <= 9; k++) {
			if (!col[y][k] && !row[x][k] && !square[func(x, y)][k]) {
				arr[x][y] = k;
				col[y][k] = true;
				row[x][k] = true;
				square[func(x, y)][k] = true;
				dfs(cnt + 1);
				arr[x][y] =0;
				col[y][k] = false;
				row[x][k] = false;
				square[func(x, y)][k] = false;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				col[j][arr[i][j]] = true;
				row[i][arr[i][j]] = true;
				square[func(i, j)][arr[i][j]] = true;
			}
		}
	}
	dfs(0);


}
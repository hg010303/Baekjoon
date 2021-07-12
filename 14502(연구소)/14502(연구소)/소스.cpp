#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int arr[8][8];
int tmp[8][8];
int n1[4] = { 0,0,-1,1 };
int n2[4] = { -1,1,0,0 };
int answer = 0;

void bfs() {
	int after[8][8];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) after[i][j] = tmp[i][j];

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (after[i][j] == 2) q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + n1[i];
			int ny = y + n2[i];

			if (ny < 0 || nx < 0 || nx >= n || ny >= m) continue;

			if (after[nx][ny] == 0) {
				after[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}
	int empty = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (after[i][j] == 0) empty++;

	answer = max(answer, empty);
}

void f(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				f(cnt + 1);
				tmp[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for(int j=0;j<m;j++)
			if (arr[i][j] == 0) {
				for (int k = 0; k < n; k++)
					for (int l = 0; l < m; l++) tmp[k][l] = arr[k][l];

				tmp[i][j] = 1;
				f(1);
				tmp[i][j] = 0;
			}

	cout << answer << endl;
}
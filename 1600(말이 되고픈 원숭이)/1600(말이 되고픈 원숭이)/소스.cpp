#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

struct node {
	int x, y, dir;
	node(int x, int y, int dir) : x(x), y(y), dir(dir) {};
};

int k;
int n, m;
int arr[210][210];

int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };

int k1[8] = { 2,2,1,1,-1,-1,-2,-2 };
int k2[8] = { 1,-1,2,-2,2,-2,1,-1 };
int visit[210][210][33];
int ans = 0;

void bfs(int i, int j) {
	queue<node> q;

	q.push(node(0, 0, k));
	visit[0][0][k] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;

		q.pop();

		if (x == n - 1 && y == m - 1) {
			ans = visit[n - 1][m - 1][dir];
			break;
		}

		if (dir >= 1) {
			for (int i = 0; i < 8; i++) {
				int nx = x + k1[i];
				int ny = y + k2[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

				if (visit[nx][ny][dir - 1]||arr[nx][ny]==1) continue;

				q.push(node(nx,ny, dir -1));
				visit[nx][ny][dir - 1] = visit[x][y][dir] + 1;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + n1[i];
			int ny = y + n2[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (visit[nx][ny][dir] || arr[nx][ny] == 1) continue;

			q.push(node(nx, ny, dir));
			visit[nx][ny][dir] = visit[x][y][dir] + 1;
		}
	}



}

int main() {
	cin >> k;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	if (arr[0][0] == 1) {
		cout << -1;
		return 0;
	}
	bfs(0, 0);

	cout << ans-1 << endl;

}
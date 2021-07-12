#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

struct point {
	int x, y, num, d;
	point(int x, int y, int num, int d) :x(x), y(y), num(num), d(d) {}
};
typedef pair<int, int> pii;

int n;
int arr[10][10];
int visit[10][10][103][3]; //0: ³ªÀÌÆ®, 1: ºñ¼ó, 2: ·è
int change[10][10][103][3];
pii start;
int n1[8] = { 2,2,1,1,-1,-1,-2,-2 };
int n2[8] = { 1,-1,2,-2,2,-2,1,-1 };
int b1[4] = { 1,-1,1,-1 };
int b2[4] = { 1,1,-1,-1 };
int l1[4] = { 1,-1,0,0 };
int l2[4] = { 0,0,-1,1 };

int main() {
	cin >> n;

	memset(visit, -1, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) start = { i,j };
		}
	}

	queue<point> q;
	q.push(point(start.first, start.second, 1, 0));
	q.push(point(start.first, start.second, 1, 1));
	q.push(point(start.first, start.second, 1, 2));

	visit[start.first][start.second][1][0]=0;
	visit[start.first][start.second][1][1]=0;
	visit[start.first][start.second][1][2]=0;
	change[start.first][start.second][1][0] = 0;
	change[start.first][start.second][1][1] = 0;
	change[start.first][start.second][1][2] = 0;
	int ans = 0;
	int visitans = 0;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		if (now.num == n * n) {
			if (ans == 0) {
				ans = visit[now.x][now.y][now.num][now.d];
				visitans = change[now.x][now.y][now.num][now.d];
			}
			else {
				visitans = min(visitans, change[now.x][now.y][now.num][now.d]);
			}

		}
		if (ans != 0) {
			if (visit[now.x][now.y][now.num][now.d] > ans) {
				cout << ans << " " << visitans;
				return 0;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (visit[now.x][now.y][now.num][i] == visit[now.x][now.y][now.num][now.d] + 1) {
				change[now.x][now.y][now.num][i] = min(change[now.x][now.y][now.num][i], change[now.x][now.y][now.num][now.d] + 1);
				q.push(point(now.x, now.y, now.num, i));
			}

			if (visit[now.x][now.y][now.num][i] != -1) continue;
			visit[now.x][now.y][now.num][i] = visit[now.x][now.y][now.num][now.d] + 1;
			change[now.x][now.y][now.num][i] = change[now.x][now.y][now.num][now.d] + 1;
			q.push(point(now.x, now.y, now.num, i));
		}

		if (now.d == 0) {
			for (int i = 0; i < 8; i++) {
				int nx = now.x + n1[i];
				int ny = now.y + n2[i];
				int nnum = now.num;
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				
				if (arr[nx][ny] == now.num + 1) nnum = now.num + 1;

				if (visit[nx][ny][nnum][now.d] == visit[now.x][now.y][now.num][now.d] + 1) {
					change[nx][ny][nnum][now.d] = min(change[now.x][now.y][now.num][now.d], change[nx][ny][nnum][now.d]);
					q.push(point(nx, ny, nnum, now.d));
				}

				if (visit[nx][ny][nnum][now.d] != -1) continue;
				visit[nx][ny][nnum][now.d] = visit[now.x][now.y][now.num][now.d] + 1;
				change[nx][ny][nnum][now.d] = change[now.x][now.y][now.num][now.d];
				q.push(point(nx, ny, nnum, now.d));
			}
		}
		else if (now.d == 1) {
			for (int i = 0; i < 4; i++) {
				for (int k = 1;; k++) {
					int nx = now.x + b1[i] * k;
					int ny = now.y + b2[i] * k;
					int nnum = now.num;

					if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;

					if (visit[nx][ny][now.num][now.d] != -1) continue;

					if (arr[nx][ny] == now.num + 1) nnum = now.num + 1;

					if (visit[nx][ny][nnum][now.d] == visit[now.x][now.y][now.num][now.d] + 1) {
						change[nx][ny][nnum][now.d] = min(change[now.x][now.y][now.num][now.d], change[nx][ny][nnum][now.d]);
						q.push(point(nx, ny, nnum, now.d));
					}

					if (visit[nx][ny][nnum][now.d] != -1) continue;
					visit[nx][ny][nnum][now.d] = visit[now.x][now.y][now.num][now.d] + 1;
					change[nx][ny][nnum][now.d] = change[now.x][now.y][now.num][now.d];
					q.push(point(nx, ny, nnum, now.d));
				}
			}
		}
		else if (now.d == 2) {
			for (int i = 0; i < 4; i++) {
				for (int k = 1;; k++) {
					int nx = now.x + l1[i] * k;
					int ny = now.y + l2[i] * k;
					int nnum = now.num;

					if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;

					if (visit[nx][ny][now.num][now.d] != -1) continue;

					if (arr[nx][ny] == now.num + 1) nnum = now.num + 1;

					if (visit[nx][ny][nnum][now.d] == visit[now.x][now.y][now.num][now.d] + 1) {
						change[nx][ny][nnum][now.d] = min(change[now.x][now.y][now.num][now.d], change[nx][ny][nnum][now.d]);
						q.push(point(nx, ny, nnum, now.d));
					}

					if (visit[nx][ny][nnum][now.d] != -1) continue;
					visit[nx][ny][nnum][now.d] = visit[now.x][now.y][now.num][now.d] + 1;
					change[nx][ny][nnum][now.d] = change[now.x][now.y][now.num][now.d];
					q.push(point(nx, ny, nnum, now.d));
				}
			}
		}
	}

}
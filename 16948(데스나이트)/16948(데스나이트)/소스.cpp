#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n;
int r1, r2, c1, c2;
int visit[201][201];

int n1[6] = { -2,-2,0,0,2,2 };
int n2[6] = { -1,1,-2,2,-1,1 };

int main() {
	memset(visit, -1, sizeof(visit));
	cin >> n;

	cin >> r1 >> r2 >> c1 >> c2;

	queue<pair<int,int>> q;
	q.push({ r1,r2 });
	visit[r1][r2] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == c1 && y == c2) break;

		for (int i = 0; i < 6; i++) {
			int nx = x + n1[i];
			int ny = y + n2[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visit[nx][ny] != -1) continue;

			visit[nx][ny] = visit[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	cout << visit[c1][c2] << endl;
}
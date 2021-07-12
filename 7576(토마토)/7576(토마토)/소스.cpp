#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int map[1030][1030] = {  };
int visit[1030][1030] = {};
queue<pair<int,int> > q;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

void bfs() {
	while (!q.empty()) {
		pair<int, int> point = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = point.first + x[i];
			int ny = point.second + y[i];
			if (visit[point.first+x[i]][point.second+y[i]]||(map[point.first+x[i]][point.second+y[i]]==1)|| (map[point.first + x[i]][point.second + y[i]] == -1)) continue;

			q.push({ point.first + x[i],point.second + y[i] });
			visit[point.first + x[i]][point.second + y[i]] = visit[point.first][point.second] + 1;
			map[point.first + x[i]][point.second + y[i]] = 1;
		}
	}


}

int main() {
	int m, n;

	cin >> m >> n;

	memset(map, -1, sizeof(map));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}

	bfs();

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (ans < visit[i][j]) ans = visit[i][j];
		}
	}

	cout << ans-1;
	
}

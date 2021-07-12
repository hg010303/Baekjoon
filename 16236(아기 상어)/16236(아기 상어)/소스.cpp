#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n;
int map[20][20];
int size;
pair<int, int> now;
int ans = 0;
int visit[20][20];

int n1[4] = { 0,0,-1,1 };
int n2[4] = { -1,1,0,0 };

int main() {
	int n;
	cin >> n;
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				now = { i,j };
				map[i][j] = 0;
			}
		}
	}
/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
*/
	int size = 2;
	queue<pair<int, int> > q;
	q.push(now);
	visit[now.first][now.second] = 0;
	int cnt = 0;
	int min_x=0, min_y=0;
	int count = 0;
	while (true) {
		if (q.empty() && cnt == 0) break;

		if (q.empty() && cnt != 0) {
			ans += cnt;
			count += 1;
			if (count == size) {
				count = 0;
				size += 1;
			}
			map[min_x][min_y] = 0;
			memset(visit, -1, sizeof(visit));
			visit[min_x][min_y] = 0;
			cnt = 0;
			q = queue<pair<int, int> >();
			q.push({ min_x,min_y });
			continue;
		}

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
//		std::cout << x << " " << y << " "<<visit[x][y]<<" "<<ans<< endl;

		if (cnt != 0 && cnt < visit[x][y]) {
			ans += cnt;
			count += 1;
			if (count == size) {
				count = 0;
				size += 1;
			}
			map[min_x][min_y] = 0;
			memset(visit, -1, sizeof(visit));
			visit[min_x][min_y] = 0;
			cnt = 0;
			q = queue<pair<int, int> >();
			q.push({ min_x,min_y });
			continue;
		}

		if (map[x][y] != 0 && map[x][y] < size) {
			if (cnt == 0) {
				cnt = visit[x][y];
				min_x = x;
				min_y = y;
			}
			else {
				if (min_x > x) {
					min_x = x;
					min_y = y;
				}
				else if (min_x == x && min_y > y) {
					min_y = y;
				}
			}
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + n1[i];
			int ny = y + n2[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visit[nx][ny] != -1) continue;
			if (map[nx][ny] > size) continue;

			visit[nx][ny] = visit[x][y] + 1;
			q.push({ nx, ny });
		}

	}
	ans += cnt;


	std::cout << ans;
}
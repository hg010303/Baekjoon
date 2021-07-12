#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int arr[110][110];
queue<pair<int, int> > q;
int n1[4] = { 0,0,1,-1 };
int n2[4] = { 1,-1,0,0 };
bool visit[110][110];
bool visit1[110][110];
int cnt = 0;
int pre = 0;
int ans = 0;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			visit1[i][j] = true;

			if (arr[i][j] == 1) cnt++;
		}
	}

	while (cnt>0) {
		ans++;
		queue < pair<int, int >> q;

		q.push({ 0,0 });
		visit[0][0] = true;

		while (!q.empty()) {
			auto now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = now.first + n1[i];
				int ny = now.second + n2[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (visit[nx][ny] == true) continue;
				if (arr[nx][ny] == 1) continue;

				visit[nx][ny] = true;
				visit1[nx][ny] = false;
				q.push({ nx,ny });
			}
		}

		queue<pair<int, int> >q1;
		int now = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visit[i][j] = false;

				if (arr[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int nx = i + n1[k];
						int ny = j + n2[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (visit1[nx][ny]) continue;

						q1.push({ i,j });
						break;
					}
				}
			}
		}
		now = q1.size();

		while (!q1.empty()) {
			auto now = q1.front();
			q1.pop();

			visit1[now.first][now.second] = false;
			arr[now.first][now.second] = 0;
		}

		if (cnt - now == 0) pre = now;
		cnt -= now;
	}
	
	cout << ans << endl;
	cout << pre << endl;
}
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

const int MAX = 1501;
typedef pair<int, int> pii;

int n, m;
int arr[MAX][MAX];
bool visit[MAX][MAX];
pii start, finish;
int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool flag = false;
	cin >> n >> m;
	queue<pii> water;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];

			if (arr[i][j] == 'L') {
				if (flag == false) {
					start = { i,j };
					flag = true;
				}
				else {
					finish = { i,j };
				}
				arr[i][j] = '.';
			}
			if (arr[i][j] == '.') water.push({ i,j });
		}
	}
	
	queue<pii> q;
	q.push(start);

	visit[start.first][start.second] = true;

	while (true) {
		queue<pii> nextQ;

		bool flag = false;

		while (!q.empty()) {
			auto now = q.front();
			q.pop();

			if (now == finish) {
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = now.first + n1[i];
				int ny = now.second + n2[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (visit[nx][ny]) continue;

				visit[nx][ny] = true;

				if (arr[nx][ny] == 'X') {
					nextQ.push({ nx,ny });
					continue;
				}
				q.push({ nx,ny });
			}
		}
		if (flag) break;

		q = nextQ;

		int watersize = water.size();

		while (watersize--) {
			auto now = water.front();
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nx = now.first + n1[i];
				int ny = now.second + n2[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

				if (arr[nx][ny] == 'X') {
					arr[nx][ny] = '.';
					water.push({ nx,ny });
				}
			}
		}
		cnt++;
	}
	cout << cnt << endl;
	

}
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;

struct point {
	int x,y,d,k,c;

	point(int x, int y, int d, int c, int k):x(x), y(y), d(d), c(c), k(k){};
};

int n, m;
char arr[52][52];
int visit[52][52][5][2][2];

pii start;
bool flag = false;
pii finish[2];

int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };

int main() {
	memset(visit, -1, sizeof(visit));
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == 'S') {
				start = { i,j };
				arr[i][j] = '.';
			}
			else if (str[j] == 'C') {
				if (flag == false) {
					finish[0] = { i,j };
					flag = true;
				}
				else {
					finish[1] = { i,j };
				}
				arr[i][j] = '.';
			}
			else {
				arr[i][j] = str[j];
			}
		}
	}
	queue<point> q;
	q.push(point(start.first, start.second, 4, 0, 0));
	visit[start.first][start.second][4][0][0] = 0;

/*	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}*/
	int ans = 0;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();

	//	cout << now.x << " " << now.y <<" "<<now.d<<" "<<now.c<<" "<<now.k<<" "<<visit[now.x][now.y][now.d][now.c][now.k]<< endl;

		if (now.c == 1 && now.k == 1) {
			cout<<visit[now.x][now.y][now.d][now.c][now.k];
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			if (now.d == i) continue;

			int nx = now.x + n1[i];
			int ny = now.y + n2[i];
			int nc = now.c;
			int nk = now.k;

			if (nx == finish[0].first && ny == finish[0].second) nc = 1;
			if (nx == finish[1].first && ny == finish[1].second) nk = 1;

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny][i][nc][nk]!=-1) continue;
			if (arr[nx][ny] == '#') continue;

			
			visit[nx][ny][i][nc][nk] = visit[now.x][now.y][now.d][now.c][now.k] + 1;

			q.push(point(nx, ny, i, nc, nk));
		}
	}

	cout << -1;

}
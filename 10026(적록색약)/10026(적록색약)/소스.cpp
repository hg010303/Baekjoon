#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

int n;
char map[110][110];
int cnt = 0;
int cnt1 = 0;
bool visit[110][110];
bool visit1[110][110];

int n1[4] = { 0,0,1,-1 };
int n2[4] = { -1,1,0,0 };

void bfs1(int i, int j, char cnt) {
	visit1[i][j] = true;
	queue<pair<int,int> > q;
	q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + n1[k];
			int ny = y + n2[k];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (cnt == 'B') {
				if (map[nx][ny] != 'B')
					continue;
			}
			else {
				if (map[nx][ny] == 'B')
					continue;
			}
			if (visit1[nx][ny] == true) continue;
			
			visit1[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

void bfs(int i, int j, char cnt) {
	visit[i][j] = true;
	queue<pair<int, int> > q;
	q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
//		cout << x << " " << y << endl;

		for (int k = 0; k < 4; k++) {
			int nx = x + n1[k];
			int ny = y + n2[k];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (map[nx][ny] != cnt) continue;
			if (visit[nx][ny] == true) continue;
			visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) map[i][j]=str[j];
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				bfs(i, j,map[i][j]);
				cnt++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit1[i][j] == false) {
				bfs1(i, j, map[i][j]);
				cnt1++;
			}
		}
	}

	cout << cnt << " " << cnt1;
}
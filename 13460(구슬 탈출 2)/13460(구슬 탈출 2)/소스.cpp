#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct ball {
	int dep;
	pair<int, int> red,blue;
};

int n, m;
char arr[11][11];
pair<int, int> red, blue, hall;
bool visit[10][10][10][10];
int ans = -1;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void move(int& x, int& y, int d) {
	while (1) {
		x += dir[d][0]; y += dir[d][1];
		if (arr[x][y] == '#') {
			x -= dir[d][0]; y -= dir[d][1];
			break;
		}
		else if (arr[x][y] == 'O') break;
	}
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') red = { i,j };
			if (arr[i][j] == 'B') blue = { i,j };
			if (arr[i][j] == 'O') hall = { i,j };
		}
	}

	queue<ball> q;
	q.push({ 0,red,blue });
	visit[red.first][red.second][blue.first][blue.second] = true;
	
	while (!q.empty()) {
		ball cur = q.front();
		q.pop();

		if (cur.dep > 10) break;
		if (cur.red == hall) {
			ans = cur.dep;
			break;
		}

		for (int i = 0; i < 4; i++) {
			pair<int,int> nred = cur.red;
			pair<int,int> nblue = cur.blue;
			move(nred.first, nred.second, i); 
			move(nblue.first, nblue.second, i);

			if (nblue == hall) continue;

			if (nred == nblue) {
				switch (i) {
				case 0:
					cur.red.first < cur.blue.first ? nred.first-- : nblue.first--; break;
				case 1:
					cur.red.second < cur.blue.second ? nred.second-- : nblue.second--; break;
				case 2:
					cur.red.first < cur.blue.first ? nblue.first++ : nred.first++; break;
				case 3:
					cur.red.second < cur.blue.second ? nblue.second++ : nred.second++; break;
				}
			}

			if (!visit[nred.first][nred.second][nblue.first][nblue.second]) {
				ball next = { cur.dep + 1,{nred.first,nred.second},{nblue.first,nblue.second} };
				q.push(next);
				visit[nred.first][nred.second][nblue.first][nblue.second] = true;
			}
		}
	}
	cout << ans;
}
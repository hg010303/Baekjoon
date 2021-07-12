#include<iostream>
#include<algorithm>
#include<string>
#include<tuple>
#include<queue>

using namespace std;

int map[8][8];
int visit[9][8][8];

int n1[9] = { 1,1,1,-1,-1,-1,0,0,0 };
int n2[9] = { 1,-1,0,1,-1,0,1,-1,0 };

int main() {
	for (int i = 0; i < 8; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			if (str[j] == '.') map[i][j] = 0;
			if (str[j] == '#')map[i][j] = 1;
		}
	}
/*
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) cout << map[i][j];
		cout << endl;
	}
	*/
	queue<tuple<int, int, int> > q;
	q.push({ 0,7,0 });
	visit[0][7][0] = true;

	int ans = 0;
	while (!q.empty()) {
		int t,y,x;
		tie(t,y,x) = q.front();
		q.pop();

		if (y == 0 && x == 7) ans = 1;

		for (int i = 0; i < 9; i++) {
			int ny = y + n2[i];
			int nx = x + n1[i];

			int nt = min(t + 1, 8);

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) continue;

			if (ny - t >= 0 && map[ny - t][nx] == 1) continue;
			if (ny - t - 1 >= 0 && map[ny - t - 1][nx] == 1) continue;

			if (!visit[nt][ny][nx]) {
				visit[nt][ny][nx] = true;
				q.push({ nt,ny,nx });
			}
		}
	}
	
	if (ans) cout << 1;
	else cout << 0;
}
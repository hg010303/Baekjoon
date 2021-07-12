#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

struct node {
	int x, y;
	int dir, num;

	node(int x, int y, int dir, int num) :x(x), y(y), dir(dir), num(num) {};
};

int n, m;
int arr[110][110];
pair<int, int> start, fin;
bool flag = false;
int visit[101][101];

int n1[4] = { 0,0,-1,1 };
int n2[4] = { -1,1,0,0 };

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == 'C') {
				if (!flag) {
					start = { i,j };
					flag = true;
				}
				else fin = { i,j };
			}
		}
	}

	memset(visit, -1, sizeof(visit));
	queue<node> q;
	q.push({ start.first,start.second,0,0 });
	q.push({ start.first,start.second,1,0 });
	q.push({ start.first,start.second,2,0 });
	q.push({ start.first,start.second,3,0 });
	visit[start.first][start.second] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int num = q.front().num;
		q.pop();
	//	cout << x << " " << y << endl;
//		if (x == fin.first && y == fin.second) break;

		for (int i = 0; i < 4; i++) {
			int nx = x + n1[i];
			int ny = y + n2[i];
			int nnum = num;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == '*') continue;
			if (dir != i) nnum += 1;
			if (visit[nx][ny]==-1||visit[nx][ny] >= nnum) {
				visit[nx][ny] = nnum;
				q.push({ nx,ny,i,nnum });
			}
		}
	}
/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << visit[i][j];
		cout << endl;
	}
	*/

	cout << visit[fin.first][fin.second];
}
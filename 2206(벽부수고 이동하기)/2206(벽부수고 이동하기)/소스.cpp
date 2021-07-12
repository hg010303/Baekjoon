#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

struct node {
	int x, y;
	int dir;
	int bright;
	node(int x, int y, int dir,int bright) : x(x), y(y), dir(dir), bright(bright) {};
};

int n, m,k;
int arr[1010][1010];
int visit[1010][1010][11][2];

int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };

int main() {
	memset(visit, -1, sizeof(visit));
	cin >> n >> m>>k;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) arr[i][j] = str[j]-'0';
	}

	queue<node> q;
	visit[0][0][0][0] = 0;
	q.push({ 0,0,0,0 });

	
	
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int bright = q.front().bright;
		q.pop();

		if (x == n - 1 && y == m - 1) break;

		if (visit[x][y][dir][1 - bright] == -1) {
			visit[x][y][dir][1 - bright] = visit[x][y][dir][bright] + 1;
			q.push({ x,y,dir,1 - bright });
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + n1[i];
			int ny = y + n2[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;



			if (dir != k) {
				if (arr[nx][ny] == 0 && visit[nx][ny][dir][1-bright]==-1) {
					visit[nx][ny][dir][1-bright] = visit[x][y][dir][bright] + 1;
					q.push({ nx,ny,dir,1-bright });
				}
				if (arr[nx][ny] == 1 && visit[nx][ny][dir+1][1]==-1&&bright==0) {
					visit[nx][ny][dir+1][1] = visit[x][y][dir][0] + 1;
					q.push({ nx,ny,dir+1,1-bright });
				}
				
			}
			else if(dir==k) {
				if (arr[nx][ny] == 0&& visit[nx][ny][dir][1-bright]==-1) {
					visit[nx][ny][dir][1-bright] = visit[x][y][dir][bright]+1;
					q.push({ nx,ny,dir,1-bright });
				}
			}
		}
	}

	vector<int> ans;

	for (int i = 0; i <= k; i++) {
		if (visit[n - 1][m - 1][i][0] != -1) ans.push_back(visit[n - 1][m - 1][i][0]);
		if (visit[n - 1][m - 1][i][1] != -1) ans.push_back(visit[n - 1][m - 1][i][1]);
	}

	if (ans.empty()) cout << -1 << endl;
	else cout << *min_element(ans.begin(),ans.end())+1 << endl;
		
}
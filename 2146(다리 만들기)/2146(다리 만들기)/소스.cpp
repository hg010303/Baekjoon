#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int n;
int arr[110][110];
bool visit[110][110];
int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };


void dfs(int x, int y, int cnt) {
	visit[x][y] = true;
	arr[x][y] = cnt;

	for (int k = 0; k < 4; k++) {
		int nX = x + n1[k];
		int nY = y + n2[k];

		if (1 <= nX && nX <= n && 1 <= nY && nY <= n) {
			if (arr[nX][nY] && !visit[nX][nY]) dfs(nX, nY, cnt);
		}
	}
}

int bfs(int cnt) {
	queue<pair<int, int> > q;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (arr[i][j] == cnt) {
				visit[i][j] = true;
				q.push({ i,j });
			}

	int ans = 0;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nX = x + n1[k];
				int nY = y + n2[k];

				if (1 <= nX && nX <= n && 1 <= nY && nY <= n) {
					if (arr[nX][nY] && arr[nX][nY] != cnt) return ans;
					else if (!arr[nX][nY] && !visit[nX][nY]) {
						visit[nX][nY] = true;
						q.push({ nX,nY });
					}
				}
			}
		}
		ans++;
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}

	int cnt = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] && !visit[i][j])
				dfs(i, j, cnt++);

	int answer = 987654321;

	for (int i = 1; i < cnt; i++) {
		memset(visit, false, sizeof(visit));
		answer = min(answer, bfs(i));
	}

	cout << answer;
}
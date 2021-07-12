#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<deque>

using namespace std;

typedef pair<int, int> pii;

int arr[55][55];
int visit[55][55];

int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };

vector<pii> virus;
bool sel[11];
vector<pii> select_virus;


int ans = 987654321;
int n, m;

void bfs() {
	deque<pii> q;
	for (int i = 0; i < select_virus.size(); i++) {
		q.push_back(select_virus[i]);
		visit[select_virus[i].first][select_virus[i].second] = 1;
	}

	int tmp = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + n1[i];
			int ny = y + n2[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (arr[nx][ny] == 1 || visit[nx][ny] != 0) continue;

			

			visit[nx][ny] = visit[x][y] + 1;
			
			if(arr[nx][ny]==0)
				tmp = max(visit[nx][ny], tmp);

			q.push_back({ nx,ny });
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 && visit[i][j] == 0) {
				return;
			}
		}
	}

	ans = min(tmp, ans);

	
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		memset(visit, false, sizeof(visit));
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (sel[i]) continue;

		sel[i] = true;
		select_virus.push_back(virus[i]);
		dfs(i, cnt + 1);
		select_virus.pop_back();
		sel[i] = false;
	}
}

int main() {


	cin >> n >> m;

	memset(sel, false, sizeof(sel));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);

	

	
	if (ans == 987654321) cout << -1 << endl;
	else cout << ans - 1 << endl;
}
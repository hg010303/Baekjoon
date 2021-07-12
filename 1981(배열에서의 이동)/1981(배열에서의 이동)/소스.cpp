#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int n;
int arr[110][110];
int m1 = 0, m2 = 200;
bool visit[110][110];
int n1[4] = { 0,0,-1,1 };
int n2[4] = { -1,1,0,0 };

bool bfs(int low, int high) {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int> > q;

	if (arr[0][0] < low || arr[0][0]>high) return false;
	if (arr[n-1][n-1] < low || arr[n-1][n-1]>high) return false;
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n - 1 && y == n - 1) break;

		for (int i = 0; i < 4; i++) {
			int nx = x + n1[i];
			int ny = y + n2[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (!visit[nx][ny]) {
				if (arr[nx][ny] <= high && arr[nx][ny] >= low) {
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
	}
	return visit[n - 1][n - 1];
}

bool chk(int mid) {
	for (int i = 0; i + mid <= 200; i++) {
		if (bfs(i, i + mid)) return true;
	}
	return false;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			m1 = max(m1, arr[i][j]);
			m2 = min(m2, arr[i][j]);
		}

	int low = 0;
	int high = m1 - m2;
	int ans = 0;

	while (low <= high) {
		memset(visit, false, sizeof(visit));
		int mid = (low + high) / 2;

		if (chk(mid)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	
	cout << ans << endl;
}
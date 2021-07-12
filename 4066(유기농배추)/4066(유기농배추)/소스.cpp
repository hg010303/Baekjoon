#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int map[55][55] = {};
int visit[55][55] = {};
int ans = 1;

void dfs(int i, int j) {
	if (visit[i][j] || (!map[i][j])) return;

	visit[i][j] = ans;
	dfs(i + 1, j);
	dfs(i, j + 1);
	dfs(i - 1, j);
	dfs(i, j - 1);

}

int main() {
	int t;
	cin >> t;

	while (t--) {
		ans = 1;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		int m, n, k;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			map[a+1][b+1] = 1;
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visit[i][j] && (map[i][j])) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans-1 << endl;
	}
}
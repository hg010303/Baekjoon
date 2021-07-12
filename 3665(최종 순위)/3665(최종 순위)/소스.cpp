#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int v[510][510];
int indeg[510];
int n,m;
int order[510];

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(v, 0, sizeof(v));
		memset(indeg, 0, sizeof(indeg));
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> order[i];

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				v[order[i]][order[j]] = 1;
				indeg[order[j]]++;
			}
		}

		cin >> m;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			
			if (v[a][b]) {
				v[a][b] = 0;
				v[b][a] = 1;
				indeg[b]--;
				indeg[a]++;
			}
			else {
				v[a][b] = 1;
				v[b][a] = 0;
				indeg[b]++;
				indeg[a]--;
			}
		}
		
		queue<int> q;

		for (int i = 1; i <= n; i++)
			if (!indeg[i]) q.push(i);

		bool flag = true;
		vector<int> ans;

		while (!q.empty()) {
			if (q.size() > 1) {
				flag = false;
				break;
			}

			int now = q.front();
			q.pop();
			ans.push_back(now);

			for (int next = 1; next <= n; next++) {
				if (v[now][next]) {
					indeg[next]--;
					if (!indeg[next]) q.push(next);
				}
			}
		}

		if (!flag) cout << "?" << '\n';
		else if (ans.size() == n) {
			for (int i = 0; i < n; i++) cout << ans[i] << " ";
			cout << '\n';
		}
		else cout << "IMPOSSIBLE" << '\n';
		
	}
}
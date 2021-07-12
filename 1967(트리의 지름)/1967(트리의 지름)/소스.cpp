#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int n;
int visit[10010];
vector<pair<int, int> > node[10002];

int ans = 0;
int now = 0;

void dfs(int point, int length) {
	if (visit[point]) return;

	visit[point] = 1;
	if (ans < length) {
		ans = length;
		now = point;
	}

	for (int i = 0; i < node[point].size(); i++) {
		dfs(node[point][i].first, length + node[point][i].second);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}

	dfs(1, 0);
	memset(visit, 0, sizeof(visit));

	dfs(now, 0);
	cout << ans;
}
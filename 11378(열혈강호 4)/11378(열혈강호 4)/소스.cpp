#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 1030;

int n, m, k;
vector<int> v[MAX];
bool visit[MAX];
int b[MAX];

bool dfs(int now) {
	if (visit[now]) return false;
	visit[now] = true;

	for (auto next : v[now]) {
		if (!b[next] || dfs(b[next])) {
			b[next] = now;
			return true;
		}
	}
	return false;
}

int bmatch() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) ret++;
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		while (cnt<k&&dfs(i)) {
			ret++;
			cnt++;
			memset(visit, false, sizeof(visit));
		}

		if (cnt >= k) break;
	}

	return ret;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;

			v[i].push_back(b);
		}
	}

	cout << bmatch();
}
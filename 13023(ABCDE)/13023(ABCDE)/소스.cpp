#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

vector<int> v[2020];
bool visit[2020];
bool answer=false;

void dfs(int idx, int cnt) {
	if (cnt == 5) {
		answer = true;
		return;
	}
	visit[idx] = true;

	for (int i : v[idx]) {
		if (visit[i] == true) continue;
		dfs(i, cnt + 1);
		if (answer == true) return;
	}
	visit[idx] = false;
}

int main() {
	int n, m;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i, 1);
		if (answer == true) break;
	}
	if (answer == true) cout << 1 << endl;
	else cout << 0 << endl;
}
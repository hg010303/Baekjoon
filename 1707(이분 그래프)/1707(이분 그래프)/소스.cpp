#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int n, e;
vector<int> v[20200];
int visit[20200];
bool visit2[20200];
bool answer = true;

void dfs(int idx, int val) {
	if (visit[idx]) return;
	visit[idx] = val;

	for (int i : v[idx]) {
		if (visit[i] == 0) {
			dfs(i, 3 - val);
		}
	}
}
void dfs2(int idx) {
	if (visit2[idx]) return;
	visit2[idx] = true;

	for (int i : v[idx]) {
		if (visit[idx] == visit[i]) {
			answer = false;
			return;
		}
		if (visit2[i] == false) {
			dfs2(i);
			if (answer == false) return;
		}
	}
}

int main() {
	int N;
	cin >> N;

	while (N--) {
		answer = true;
		cin >> n >> e;
		memset(visit, 0, sizeof(visit));
		memset(visit2, false, sizeof(visit));
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= n; i++)
			if (visit[i] == 0) dfs(i, 1);
		for (int i = 1; i <= n; i++)
			if (visit2[i] == 0) dfs2(i);

		if (answer) cout << "YES"<<'\n';
		else cout << "NO" << '\n';
	}
}
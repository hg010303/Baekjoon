#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int n, m;
vector<int> v[1010];
bool visit[1010];

void dfs(int idx) {
	if (visit[idx] == true) return;

	visit[idx] = true;
	for (int i : v[idx]) {
		if (visit[i] == false) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int answer = 0;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	memset(visit, false, sizeof(visit));

	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			answer++;
			dfs(i);
		}
	}

	cout << answer;
}
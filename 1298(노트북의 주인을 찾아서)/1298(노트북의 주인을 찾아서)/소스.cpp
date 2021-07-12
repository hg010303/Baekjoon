#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 110;

int n, m;
vector<int> v[MAX];
bool visit[MAX];
int b[MAX];


bool dfs(int now) {
	if (visit[now]) return 0;
	visit[now] = 1;

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
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) ret++;
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}


	cout << bmatch() << endl;
	
}
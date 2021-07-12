#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 2010;

int n, m;
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

	for (int i = 1; i <= 2 * n; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) ret++;
	}
	return ret;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			v[i*2-1].push_back(b);
			v[i *2].push_back(b);
		}
	}

	cout << bmatch() << endl;


}
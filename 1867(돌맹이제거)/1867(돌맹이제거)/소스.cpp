#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 510;

int n, m;

vector<int> v[MAX];
bool visit[MAX];
int b[MAX];


bool dfs(int a) {
	if (visit[a]) return false;
	visit[a] = true;

	for (auto next : v[a]) {
		if (!b[next] || dfs(b[next])) {
			b[next] = a;
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
	return ret;
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
	}

	cout << bmatch() << endl;

}
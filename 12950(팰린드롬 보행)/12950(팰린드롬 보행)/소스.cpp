#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<int, char> pii;

int n, m;
vector<pii> v[21];
int memo[21][21];
bool visit[21][21];


int f(int start, int fin) {
	if (start == fin) return 0;
	int& ret = memo[start][fin];
	if (ret != -1) return memo[start][fin];
	if (visit[start][fin]) return -1;
	
	visit[start][fin] = true;

	for (auto i : v[start])
		if (i.first == fin)
			return ret = 1;

	for (auto i : v[start]) {
		for (auto j : v[fin]) {
			if (i.second == j.second) {
				int cnt = f(i.first, j.first);
				if (cnt == -1) continue;

				if (ret == -1) 
					ret = 2+cnt;
				else ret = min(ret, 2 +cnt);
			}
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	memset(memo, -1, sizeof(memo));
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	cout << f(0, 1) << endl;
}
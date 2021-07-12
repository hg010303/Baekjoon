#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 100000 + 100;
typedef pair<int, int> pii;

int n;
vector<pii> v[MAX];
int parent[MAX][20], maxi[MAX][21],mini[MAX][21];
int level[MAX];
bool visit[MAX];

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto i : v[now]) {
			int next = i.first;
			int dis = i.second;

			if (visit[next]) continue;

			visit[next] = true;
			level[next] = level[now] + 1;
			parent[next][0] = now;
			maxi[next][0] = dis;
			mini[next][0] = dis;
			q.push(next);
		}
	}
}

void find_parent() {
	for(int i=1;i<20;i++){
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			mini[j][i] = min(mini[j][i - 1], mini[parent[j][i - 1]][i - 1]);
			maxi[j][i] = max(maxi[j][i - 1], maxi[parent[j][i - 1]][i - 1]);
		}
	}
}

pair<int,int> lca(int a, int b) {
	int rmin = 987654321;
	int rmax = -987654321;
	if (level[a] < level[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int diff = level[a] - level[b];

	for (int i = 0; diff; i++) {
		if (diff & 1) {

			rmin = min(rmin, mini[a][i]);
			rmax = max(rmax, maxi[a][i]);
			a = parent[a][i];
		}
		diff >>= 1;
	}

	if (a == b) return { rmin, rmax };

	for (int i = 19; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			
			rmin = min(rmin, min(mini[a][i],mini[b][i]));
			rmax = max(rmax, max(maxi[a][i],maxi[b][i]));
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	rmin = min(rmin, min(mini[a][0], mini[b][0]));
	rmax = max(rmax, max(maxi[a][0], maxi[b][0]));
	return { rmin,rmax };
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	parent[1][0] = 1;
	level[1] = 1;


	bfs();
	find_parent();

	int k;
	cin >> k;

	while (k--) {
		int d, e;
		cin >> d >> e;

		auto parent = lca(d, e);
		cout << parent.first << " " << parent.second << '\n';

	}
}
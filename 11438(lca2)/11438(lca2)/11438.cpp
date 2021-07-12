#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> x[100001];
int parent[100001];
int depth[100001];
bool visit[100001];
int d[100001][100];

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int log = 1;
	for (log = 1; (1 << log) <= depth[a]; log++);
	log -= 1;
	for (int i = log; i >= 0; i--) {
		if (depth[a] >= (1 << i) + depth[b])
			a = d[a][i];
	}
	if (a == b) return a;
	else {
		for (int i = log; i >= 0; i--) {
			if (d[a][i] != 0 && d[a][i] != d[b][i]) {
				a =d[a][i];
				b = d[b][i];
			}
		}
		return parent[a];
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		x[a].push_back(b);
	}
	queue<int> q;
	q.push(1);
	parent[1] = 0;
	depth[1] = 0;

	while(!q.empty())
	{
		int a = q.front();
		visit[a] = true;
		q.pop();
		for (int i = 0; i < x[a].size(); i++) {
			if (!visit[a]) {
				visit[a] = true;
				q.push(x[a][i]);
				parent[x[a][i]] = a;
				depth[x[a][i]] = depth[a] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		d[i][0] = parent[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j - 1] != 0) {
				d[i][j] = d[d[i][j - 1]][j - 1];
			}
		}
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}
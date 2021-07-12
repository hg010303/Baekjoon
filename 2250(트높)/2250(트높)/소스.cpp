#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 987654321;

int n,nodeidx;
pair<int, int> tree[10100];
int node[10100];
int low[10100];
int high[10100];

void dfs(int idx, int cnt) {
	if (tree[idx].first > 0) dfs(tree[idx].first, cnt + 1);

	low[cnt] = min(low[cnt], nodeidx);
	high[cnt] = max(high[cnt], nodeidx++);

	if (tree[idx].second > 0) dfs(tree[idx].second, cnt + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < 10100; i++) low[i] = INF;

	for (int i = 1; i <= n; i++) {
		int a, b,c;
		cin >> a >> b>>c;
		tree[a] = { b,c };
		node[a]++;
		if (b != -1) node[b]++;
		if (c != -1) node[c]++;
	}

	int root;
	for (int i = 1; i <= n; i++)
		if (node[i] == 1) root = i;

	nodeidx = 1;
	dfs(root, 1);

	int result = high[1] - low[1] + 1;
	int level = 1;

	for (int i = 2; i <= n; i++) {
		int temp = high[i] - low[i] + 1;
		if (temp > result) {
			result = temp;
			level = i;
		}
	}
	cout << level << " " << result << '\n';
}
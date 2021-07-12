#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

const int MAX = 10100;

int n, m, cnt = 0,SCCtotal=0;
vector<int> adj[MAX];
int dfsn[MAX],finish[MAX],sn[MAX];
stack<int> s;
vector<vector<int> > scc;

int dfs(int now) {
	dfsn[now] = ++cnt;
	s.push(now);

	int result = dfsn[now];

	for (auto next : adj[now]) {
		if (dfsn[next] == 0) result = min(result, dfs(next));
		else if (!finish[next]) result = min(result, dfsn[next]);
	}

	if (dfsn[now] == result) {
		vector<int> curSCC;

		while (true) {
			int t = s.top();
			s.pop();
			curSCC.push_back(t);
			finish[t] = true;
			sn[t] = SCCtotal;
			if (t == now) break;
		}
		sort(curSCC.begin(), curSCC.end());
		scc.push_back(curSCC);
		SCCtotal++;

	}
	return result;

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (dfsn[i] == 0) dfs(i);
	}

	sort(scc.begin(), scc.end());

	cout << SCCtotal << endl;

	for (auto i : scc) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << -1 << endl;
	}
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 50100;

vector<int> v[MAX];
int n, m;
int parent[MAX];
int indeg[MAX];

int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a]=find(parent[a]);
}

void sum(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	parent[b] = a;
}

vector<pii> e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, c;
		char b;

		cin >> a >> b >> c;

		if (b == '=') {
			sum(a, c);
		}
		else {
			e.push_back({ a,c });
		}

	}

	for (auto i : e) {
		int a = i.first;
		int b = i.second;
		a = find(a);
		b = find(b);

		v[a].push_back(b);
		indeg[b]++;
	}
	
	queue<int> q;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (!indeg[i]) {
			q.push(i);
			cnt++;
		}
//	cout << cnt << endl;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (auto next : v[now]) {
			indeg[next]--;
			if (!indeg[next]) {
				q.push(next);
				cnt++;
			}
		}
	}
//	cout << cnt << endl;
	if (cnt == n) cout << "consistent";
	else cout << "inconsistent";

}
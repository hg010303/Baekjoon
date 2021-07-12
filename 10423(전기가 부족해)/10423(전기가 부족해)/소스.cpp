#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;

typedef struct node {
	int a;
	int b;
	int d;

	node(int a, int b, int d) : a(a), b(b), d(d) {};
};

int n,m,k;
vector<node> e;

int parent[1100];
bool engine[1100];

int find(int a) {
	if (parent[a] == a) return a;
	else {
		if (engine[a]) engine[parent[a]] = true;
		return parent[a] = find(parent[a]);
	}
}

bool cmp(const node& a, const node& b) {
	return a.d < b.d;
}

void sum(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (engine[b]) engine[a] = true;
	parent[b] = a;
}

int main() {
	cin >> n>>m>>k;

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		engine[a] = true;
	}

	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back(node(a, b, c));
	}

	sort(e.begin(), e.end(), cmp);

	int ans = 0;

	for (auto edge : e) {
		int a = find(edge.a);
		int b = find(edge.b);
		int dis = edge.d;

		if (a == b) continue;
		if (engine[a] && engine[b]) continue;
		sum(a, b);
		ans += dis;
	}

	cout << ans << endl;
}
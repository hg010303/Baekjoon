#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;

struct node {
	int a;
	int b;
	int d;
};


int n,m;
vector<node> e;

int parent[10010];

bool cmp(const node& a, const node& b) {
	return a.d < b.d;
}

int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

void sum(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}

int main() {
	cin >> n>>m;

	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		node nd;
		cin >> nd.a >> nd.b >> nd.d;

		e.push_back(nd);
	}

	sort(e.begin(),e.end(),cmp);

	int ans = 0;

	for (int i = 0; i < e.size(); i++) {
		int a = find(e[i].a);
		int b = find(e[i].b);
		int dis = e[i].d;

		if (a == b) continue;
		sum(a, b);

		ans += dis;
		
	}

	cout << ans;
}
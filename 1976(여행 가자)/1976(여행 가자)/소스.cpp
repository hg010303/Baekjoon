#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 210;

int parent[MAX];
int n, m;

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
	cin >> n >> m;

	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;

			int b = parent[i];
			int c = parent[j];

			if (b == c) continue;
			if (a) sum(b, c);
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		if (i == 0) ans = find(a);
		else if (ans == find(a)) continue;
		else {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
}
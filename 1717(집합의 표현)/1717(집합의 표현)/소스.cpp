#include<iostream>
#include<algorithm>

using namespace std;

int n, m;

int parent[1000100];

int find(int a) {
	if (parent[a] == a) return a;

	else return parent[a]=find(parent[a]);
}

void sum(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa < pb) parent[pb] = pa;
	else parent[pa] = pb;
}

bool chk(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	parent[a] = pa;
	parent[b] = pb;

	if (pa == pb) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i <= n; i++) parent[i] = i;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0) {
			sum(b,c);
		}
		else {
			if (chk(b,c)) {
				cout << "YES" << '\n';
			}
			else cout << "NO" << '\n';
		}
	}
}
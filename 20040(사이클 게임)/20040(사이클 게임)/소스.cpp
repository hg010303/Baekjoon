#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 500100;

int n, m;
int parent[MAX];

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;

		a = find(a);
		b = find(b);

		if (a == b) {
			cout << i << endl;
			return 0;
		}

		sum(a, b);
		
	}

	cout << 0 << endl;
}
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 101000;

int n, m;
int parent[MAX];
bool visit[MAX];

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void sum(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int ans = 0;
	bool flag = false;
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		a = find(a);
		if (flag) continue;
		bool f1 = false;
		if (a == 0) break;

		for (int j = a; j >= 1; j--) {
			if (!visit[j]) {
				ans++;
				parent[a] = j - 1;
				visit[j] = true;
				f1 = true;
				break;
			}
		}
		if (!f1) break;
	}
	cout << ans << '\n';
}
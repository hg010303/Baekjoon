#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

const int MAX = 200100;

struct node {
	int a, b, c;
	node(int a, int b, int c) :a(a), b(b), c(c) {};
};

int n, q;
int p[MAX];
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
	cin >> n >> q;

	stack<node> s;

	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		p[i] = a;
	}

	for (int i = 0; i < n - 1 + q; i++) {
		int a;
		cin >> a;

		if (a == 1) {
			int b, c;
			cin >> b >> c;
			s.push(node(a,b,c));
		}
		else {
			int b;
			cin >> b;
			s.push(node(a, b, 0));
		}
	}

	stack<int> ans;

	while (!s.empty()) {
		auto now = s.top();
		s.pop();

		if (now.a == 0) {
			sum(p[now.b], now.b);
		}

		if (now.a == 1) {
			int b = find(now.b);
			int c = find(now.c);

			if (b == c) ans.push(1);
			else ans.push(0);
		}

	}

	while (!ans.empty()) {
		if (ans.top()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		ans.pop();
	}
}
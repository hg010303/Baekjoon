#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct edge {
	int a;
	int b;
	int dis;

	edge(int a, int b, int dis) : a(a), b(b), dis(dis) {};
};



const int CON = 1e9;

int n, m;
int parent[100100];
int siz[100100];
long long all = 0;
vector<edge> v;

bool cmp(const edge& a, const edge& b) {
	return a.dis > b.dis;
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
	siz[a] += siz[b];
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		siz[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		all += c;
		v.push_back(edge(a, b, c));
	}

	sort(v.begin(), v.end(), cmp);

	long long ans = all;
	long long answer = 0;

	for (auto e : v) {
		int a = find(e.a);
		int b = find(e.b);
		int dis = e.dis;

		if (a == b) {
			ans -= dis;
			continue;
		}

		answer += ans * siz[a] * siz[b];
		answer %= CON;
		sum(a, b);
//		cout << answer<<" "<<siz[a]<<" "<<siz[b]<<" " << endl;
		ans -= dis;
	}

	cout << answer << endl;

}
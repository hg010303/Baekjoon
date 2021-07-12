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

typedef struct point {
	int idx, x, y, z;

	point(int idx, int x, int y, int z) : idx(idx),x(x), y(y), z(z) {};
};

int n;
vector<point> v;
vector<node> e;

int parent[100100];

int find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = find(parent[a]);
	}
}

bool cmp(const node& a, const node& b) {
	return a.d < b.d;
}

bool cmpx(const point& a, const point& b) {
	return a.x < b.x;
}

bool cmpy(const point& a, const point& b) {
	return a.y < b.y;
}

bool cmpz(const point& a, const point& b) {
	return a.z < b.z;
}

void sum(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(point(i,a, b, c));
	}

	sort(v.begin(), v.end(), cmpx);

	for (int i = 0; i < n - 1; i++) {
		e.push_back({ v[i].idx,v[i + 1].idx , abs(v[i].x - v[i + 1].x)	});
	}

	sort(v.begin(), v.end(), cmpy);

	for (int i = 0; i < n - 1; i++) {
		e.push_back({ v[i].idx,v[i + 1].idx , abs(v[i].y - v[i + 1].y) });
	}

	sort(v.begin(), v.end(), cmpz);

	for (int i = 0; i < n - 1; i++) {
		e.push_back({ v[i].idx,v[i + 1].idx , abs(v[i].z - v[i + 1].z) });
	}

	sort(e.begin(), e.end(), cmp);

	int ans = 0;

	for (auto edge : e) {
		int a = find(edge.a);
		int b = find(edge.b);
		int dis = edge.d;

		if (a == b) continue;
		sum(a, b);
		ans += dis;
	}

	cout << ans << endl;
}
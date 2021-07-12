#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> v;
int parent[53];
int ans[53];

bool cmp(const pii& a, const pii& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
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
	cin >> n >> m;

	if (m < n - 1) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == 'Y'&&i<j) {
				v.push_back({ i,j });
			}
		}
	}

	int cnt = 0;



	for (int i = 0; i < v.size(); i++) {
		int a = find(v[i].first);
		int b = find(v[i].second);

		if (a == b) {
			if (m - n + 1 > cnt) {
				cnt++;
				ans[v[i].first]++;
				ans[v[i].second]++;
			}
		}
		else {
			ans[v[i].first]++;
			ans[v[i].second]++;
			sum(a, b);
		}
	}

	if (m - n + 1 != cnt) {
		cout << -1 << endl;
		return 0;
	}

	int tmp = find(0);
	for (int i = 0; i < n; i++) {
		if (find(i) != tmp) {
			cout << -1 << endl;
			return 0;
		}
 	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

}
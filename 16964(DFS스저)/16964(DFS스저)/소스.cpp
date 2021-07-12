#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<vector<int> > a;
vector<int> cand;
vector<int> order;
bool visit[100010];

void dfs(int x, vector<int>& picked) {
	if (visit[x]) return;

	picked.push_back(x);
	visit[x] = true;

	for (int y : a[x])
		if (visit[y] == false) dfs(y, picked);
}

bool compare(int a, int b) {
	return order[a] < order[b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	a = vector<vector<int> >(n, vector<int>());
	cand = vector<int>(n);
	order = vector<int>(n);

	for (int i = 0; i < n - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		n1 -= 1;
		n2 -= 1;
		a[n1].push_back(n2);
		a[n2].push_back(n1);
	}

	for (int i = 0; i < n; i++) {
		cin >> cand[i];
		cand[i] -= 1;
		order[cand[i]] = i;
	}

	for (int i = 0; i < n; i++) sort(a[i].begin(), a[i].end(), compare);

	vector<int> picked;
	dfs(0, picked);

	for (int i = 0; i < picked.size(); i++) {
		if (picked[i] != cand[i]) {
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';
	return 0;
}
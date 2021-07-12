#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

int n;
bool visit[10];
vector<int> v;
void dfs();

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	dfs();
}

void dfs() {
	if (v.size() == n) {
		for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			v.push_back(i);
			dfs();
			visit[i] = 0;
			v.pop_back();
		}
	}
}
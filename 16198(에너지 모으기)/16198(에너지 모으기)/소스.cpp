#include<iostream>
#include<algorithm>

using namespace std;

int n, w[10];
bool visit[10];

int dfs() {
	int ret = 0;

	for (int i = 1; i < n - 1; i++) {
		if (visit[i]) continue;

		int left = i - 1;
		int right = i + 1;

		while (visit[left]) --left;
		while (visit[right]) ++right;
		visit[i] = true;
		ret = max(ret, dfs() + w[left] * w[right]);
		visit[i] = false;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) cin >> w[i];
	cout << dfs() << '\n';
}
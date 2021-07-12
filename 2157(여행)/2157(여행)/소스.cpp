#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int edge[310][310];
int n, m, k;
int dp[310][310];

int f(int idx, int cnt) {
	if (idx == 1) return 0;
	if (cnt == 0) return -1e9;

	int& ret = dp[idx][cnt];

	if (ret != -1) return ret;
	ret = -1e9;
	for (int i = 1; i < idx; i++) {
		if (edge[i][idx]) {
			int a = f(i, cnt - 1);
//			if (a == -1) continue;
			ret = max(ret, a + edge[i][idx]);
		}
	}
	return ret;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edge[a][b] = max(edge[a][b], c);
	}
	memset(dp, -1, sizeof(dp));
	cout << f(n, m-1) << endl;
}
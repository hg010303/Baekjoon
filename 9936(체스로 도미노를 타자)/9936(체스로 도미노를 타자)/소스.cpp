#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 1010;
const int INF = -987654321;

int n, m;
int arr[MAX][3];
int dp[3 * MAX][MAX][(1 << 3)];

int f(int idx, int cnt, int bin) {
	if (idx >= 3 * n) {
		if (cnt == 0) return 0;
		else return INF;
	}

	if (cnt == 0) return 0;

	int& ret = dp[idx][cnt][bin];
	if (ret != -1) return ret;
	ret = 0;

	ret = f(idx + 1, cnt, (bin >> 1));

	if ((bin & 1) == 0) {
		if (idx % 3 != 2 && (bin & 2) == 0) ret = max(ret, f(idx + 2, cnt - 1, (bin >> 2)) + arr[idx / 3][idx % 3] + arr[idx / 3][idx % 3 + 1]);
		if(idx/3!=n-1)ret = max(ret, f(idx + 1, cnt - 1, (bin >> 1) | 4) + arr[idx / 3][idx % 3] + arr[idx / 3 + 1][idx % 3]);
	}

	return ret;

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << f(0, m, 0);
}


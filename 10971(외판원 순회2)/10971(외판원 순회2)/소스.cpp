#include<iostream>
#include<algorithm>

using namespace std;

int arr[11][11];
int visit[11];
int ans = 987654321;
int n;
void dfs(int start, int now, int sum, int cnt) {
	if (cnt == n && start == now) {
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (arr[now][i] == 0) continue;
		if (!visit[now] && arr[now][i] > 0) {
			visit[now] = true;
			sum += arr[now][i];

			if (sum <= ans) dfs(start, i, sum, cnt + 1);

			visit[now] = false;
			sum -= arr[now][i];
		}
	}
}

int main() {
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) dfs(i, i, 0, 0);

	cout << ans;
}
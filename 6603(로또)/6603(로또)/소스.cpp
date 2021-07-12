#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[15];

int ans[6];

void dfs(int x,int now) {
	if (now > n) return;
	if (x == 6) {
		for (int i = 0; i < 6; i++) cout << ans[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = now; i < n; i++) {
		ans[x] = arr[i];
		dfs(x + 1, i + 1);
	}
}

int main() {
	while (true) {

		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr, arr + n);

		dfs(0, 0);
		cout << '\n';
	}
}
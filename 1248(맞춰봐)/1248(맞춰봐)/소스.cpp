#include<iostream>
#include<algorithm>

using namespace std;

char arr[10][10];
int n;
int ans[10];

bool check(int idx) {
	int sum = 0;
	for (int i = idx; i >= 0; i--) {
		sum = sum + ans[i];
		if (arr[i][idx] == '+' && sum <= 0) return false;
		if (arr[i][idx] == '-' && sum >= 0) return false;
		if (arr[i][idx] == '0' && sum != 0) return false;
	}
	return true;
}

void dfs(int idx) {
	if (idx == n) {
		for (int i = 0; i < n; i++) cout << ans[i] << " ";
		exit(0);
	}

	for (int i = -10; i <= 10; i++) {
		ans[idx] = i;
		if (check(idx)) dfs(idx + 1);
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) cin >> arr[i][j];

	dfs(0);

}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
int arr[25];
bool su[2010000];

void dfs(int idx, int s) {
	if (idx >= n) return;
//	cout << idx << " " << s << endl;
	su[s] = true;

	dfs(idx+1, s + arr[idx+1]);
	dfs(idx+1, s);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	dfs(-1, 0);
	int ans = 0;
	for (int i = 0; i < 2010000; i++) {
		if (su[i] == false) {
			ans = i;
			break;
		}
	}

	cout << ans;
}
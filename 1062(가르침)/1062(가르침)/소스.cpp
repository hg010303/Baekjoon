#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, k;
string str[52];
bool visit[26];
int answer = 0;

void dfs(int idx, int cnt) {
	if (idx >= 26) return;

	if (cnt == k) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			bool flag = true;
			for (int j = 0; j < str[i].length(); j++) {
				if (!visit[str[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag) ans++;
		}
		answer = max(ans, answer);
	}

	for (int i = idx; i < 26; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i, cnt + 1);
			visit[i] = false;
		}
	}








}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		str[i] = str[i].substr(4, str[i].length() - 8);
	}

	visit['a' - 'a'] = true;
	visit['n' - 'a'] = true;
	visit['t' - 'a'] = true;
	visit['i' - 'a'] = true;
	visit['c' - 'a'] = true;
	k -= 5;

	if (k < 0) {
		cout << 0 << endl;
		return 0;
	}

	if (k == 21) {
		cout << n << endl;
		return 0;
	}

//	for (int i = 0; i < n; i++) cout << str[i] << endl;


	dfs(0, 0);

	cout << answer;
}
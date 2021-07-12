#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int n, m;
int arr[11][11];
int memo[11][1024];
vector<int> v;

void dfs(int idx,  int bin) {
	if (idx == m) {
		v.push_back(bin);
		return;
	}

	dfs(idx+1, bin * 2);
	
	if (bin % 2 == 1) return;
	dfs(idx+1, bin * 2 + 1);
}

int f(int idx, int flag) {
	if (idx >= n) return 0;

	int& ret = memo[idx][flag];
	if (ret != -1) return ret;

	ret = 0;

//	cout << idx << " " << flag << endl;

	for (auto bin : v) {


		int count = 0;
		bool fl = false;

		for (int i = 0; i < m; i++) {
			if (arr[idx][i] == 0) {
				if (bin & (1 << (m - 1 - i))) {
					fl = true;
					break;
				}
			}
			if (bin & (1 << i)) count++;
		}
//		cout << bin << " " << count << endl;

		if (fl) continue;

		
		for (int i = 0; i < m; i++) {
			if (bin & (1 << m - 1 - i)) {
				if (i != m - 1) {
					if (flag & (1 << (m - 2 - i))) fl = true;
				}
				if (i != 0) {
					if (flag & (1 << (m - i))) fl = true;
				}
				if (fl) break;
			}
		}
		if (fl) continue;
//		cout << bin << endl;
		ret = max(ret, f(idx + 1, bin)+count);
	}
//	cout << idx << " " << flag << " " << ret << endl;
	return ret;

}


int main() {
	int T;
	cin >> T;
	while (T--) {
		v.clear();
		memset(memo, -1, sizeof(memo));
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			int tmp = 0;
			string str;

			cin >> str;
			for (int j = 0; j < m; j++) {

				if (str[j] == '.') {
					arr[i][j] = 1;
				}
				else arr[i][j] = 0;

				
			}
		}

		if (m == 1) {
			int cnt = 0;
			for (int i = 0; i < n; i++) if (arr[i][0]) cnt++;
			cout << cnt << endl;
			continue;
		}

		dfs(0, 0);
		cout << f(0, 0) << endl;


	}
}
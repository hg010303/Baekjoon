#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int arr[27][27];
bool visit[27][27];
int answer = 0;
vector<int> a;

int dfs(int i, int j) {
	if (visit[i][j] == true) return 0;
	if (arr[i][j] == 0) return 0;

	visit[i][j] = true;

	return dfs(i + 1, j)+ dfs(i - 1, j)+ dfs(i, j + 1) + dfs(i, j - 1)+1;
}

int main() {
	cin >> n;
	memset(visit, false, sizeof(visit));

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) arr[i][j] = s[j - 1] - '0';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j]==1&&visit[i][j] == false) {
				answer += 1;
				a.push_back(dfs(i, j));
			}
		}
	}

	cout << answer<<endl;
	sort(a.begin(), a.end());

	for (int i : a) cout << i << endl;
}
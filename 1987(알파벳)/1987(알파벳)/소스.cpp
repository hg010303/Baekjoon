#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;
char arr[23][23];
bool visit[26];
int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };
int answer = 0;


void dfs(int x, int y, int cnt) {
	if (visit[arr[x][y] - 'A'] == true) return;

	answer = max(answer, cnt);

	visit[arr[x][y] - 'A'] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + n1[i];
		int ny = y + n2[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		
		if (visit[arr[nx][ny] - 'A'] == false) dfs(nx, ny, cnt + 1);
	}
	visit[arr[x][y] - 'A'] = false;
}

int main() {
	cin >> n >> m;
	

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) arr[i][j] = str[j];
	}

	dfs(0, 0,1);

	cout << answer << endl;
}
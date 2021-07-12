#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
int n, m;
char arr[55][55];
int visit[55][55];

int n1[4] = { 1,-1,0,0 };
int n2[4] = { 0,0,1,-1 };

int answer = 0;

void dfs(int i, int j) {
	if (answer == 1) return;


	for (int k = 0; k < 4; k++) {
		int a = i + n1[k];
		int b = j + n2[k];
		if (arr[a][b] == 0) continue;

		if (arr[a][b] == arr[i][j] && visit[a][b]-visit[i][j]>=3) {
			answer = 1;
			return;
		}

		if (arr[a][b] == arr[i][j] && visit[a][b] == 0) {
			visit[a][b] = visit[i][j] + 1;
			dfs(a, b);
			if (answer == 1) return;
		}
	}
}


int main() {
	cin >> n >> m;
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> arr[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (answer == 1) break;
			if (visit[i][j] == 0) {
				visit[i][j] = 1;
				dfs(i, j);
			}
		}
		if (answer == 1) break;
	}
/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << visit[i][j] << " ";
		}
		cout << '\n';
	}
	*/
	if (answer == 1) cout << "Yes";
	else cout << "No";
}
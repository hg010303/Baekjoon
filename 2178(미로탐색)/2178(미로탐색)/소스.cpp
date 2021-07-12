#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int n, m;
int arr[110][110];
int visit[110][110];
int answer = 0;
int n1[4] = { 1,-1,0,0 };
int n2[4] = { 0,0,1,-1 };

void bfs(int a, int b) {
	queue<pair<int,int> > q;

	q.push({ a,b });
	visit[a][b] = 1;
	while (!q.empty()) {
		pair<int, int> point = q.front();
		int i = point.first;
		int j = point.second;
		q.pop();


		for (int k = 0; k < 4; k++) {

			if (arr[i+n1[k]][j+n2[k]] == 1 && visit[i + n1[k]][j + n2[k]] == 0) {
				visit[i + n1[k]][j + n2[k]] = visit[i][j] + 1;
				q.push({ i + n1[k],j + n2[k] });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	memset(visit, 0, sizeof(visit));
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) arr[i][j] = s[j - 1] - '0';
	}

	bfs(1, 1);

	cout << visit[n][m] << endl;
}
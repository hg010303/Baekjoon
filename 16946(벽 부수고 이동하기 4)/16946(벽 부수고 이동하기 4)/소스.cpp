#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<set>

using namespace std;

int n, m;
int arr[1010][1010];
int visit[1010][1010];
int cnt = 1;

int n1[4] = { -1,1,0,0 };
int n2[4] = { 0,0,-1,1 };

int a[500001];

int ans[1010][1010];

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	int answer = 1;
	q.push({ x,y });

	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();



		for (int i = 0; i < 4; i++) {
			int nx = x1 + n1[i];
			int ny = y1 + n2[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (arr[nx][ny] == 0 && visit[nx][ny] == 0) {
				visit[nx][ny] = cnt;
				q.push({ nx,ny });
				answer++;
			}

		}
	}
	a[cnt] = answer;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) arr[i][j] = str[j]-'0';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && visit[i][j] == 0) {
				visit[i][j] = cnt;
				bfs(i, j);
				cnt++;
			}
		}
	}
/*
	cout<<endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << visit[i][j];
		cout << endl;
	}
	cout<<endl;
	*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				set<int> v = set<int>();
				ans[i][j] += 1;
				for (int k = 0; k < 4; k++) {
					int nx = i + n1[k];
					int ny = j + n2[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (arr[nx][ny] == 1) continue;

					if (v.find(visit[nx][ny]) == v.end()) {
						ans[i][j] += a[visit[nx][ny]];
						v.insert(visit[nx][ny]);
					}
					
				}
				ans[i][j] %= 10;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << ans[i][j];
		cout << endl;
	}
}
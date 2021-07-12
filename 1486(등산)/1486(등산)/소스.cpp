#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int n1[4] = { 0,0,1,-1 };
int n2[4] = { 1,-1,0,0 };

const int INF = 987654321;

int n, m, t, d;
int arr[26][26];
int dist[26][26];
int dist1[26][26];
vector<pair<int, int> > v[26][26];
vector<pair<int, int>> v1[26][26];

int main() {
	cin >> n >> m >> t >> d;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] >= 'A' && str[j] <= 'Z') arr[i][j] = str[j] - 'A';
			else arr[i][j] = str[j] - 'a' + 26;
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
		cout << endl;
	}
	*/


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + n1[k];
				int ny = j + n2[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

				if (abs(arr[i][j] - arr[nx][ny]) > t) continue;

				
				if (arr[i][j] > arr[nx][ny]) {
					int x = (arr[i][j] - arr[nx][ny]);
					v1[i][j].push_back({ k,x * x });
					v[i][j].push_back({ k,1 });
				}
				else if (arr[i][j] == arr[nx][ny]) {
					v[i][j].push_back({ k,1 });
					v1[i][j].push_back({ k,1 });
				}
				else {
					int x = (arr[i][j] - arr[nx][ny]);
					v[i][j].push_back({ k,x * x });
					v1[i][j].push_back({ k,1 });
				}
			}
		}
	}

/*	for (auto i : v[0][0]) {
		cout << i.first << " " << i.second << endl;
	}
*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) dist[i][j] = INF;
	}

	dist[0][0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int now = q.top().second;
		int dir = q.top().first;
		q.pop();

		for (auto i : v[now / m][now % m]) {
			int next = i.first;
			int ndir = i.second;

			int nx = now / m + n1[next];
			int ny = now % m + n2[next];

//			cout << now << " " << nx << " " << ny << endl;

			if (dist[nx][ny] > dist[now / m][now % m] + ndir) {
				dist[nx][ny] = dist[now / m][now % m] + ndir;
				q.push({ dist[nx][ny],nx * m + ny });
			}
		}
	}
	
/*	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << dist[i][j] << " ";
		cout << endl;
	}
	*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) dist1[i][j] = INF;
	}

	dist1[0][0] = 0;

	q.push({ 0,0 });

	while (!q.empty()) {
		int now = q.top().second;
		int dir = q.top().first;
		q.pop();

		for (auto i : v1[now / m][now % m]) {
			int next = i.first;
			int ndir = i.second;

			int nx = now / m + n1[next];
			int ny = now % m + n2[next];

			//			cout << now << " " << nx << " " << ny << endl;

			if (dist1[nx][ny] > dist1[now / m][now % m] + ndir) {
				dist1[nx][ny] = dist1[now / m][now % m] + ndir;
				q.push({ dist1[nx][ny],nx * m + ny });
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] + dist1[i][j] <= d) ans = max(ans, arr[i][j]);
		}
	}
	cout << ans << endl;
}
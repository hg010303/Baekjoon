#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

struct node {
	int x, y, dist;

	node(int x, int y, int dist): x(x),y(y),dist(dist){}

	bool operator > (const node& n) const {
		return dist > n.dist;
	}
};

const int INF = 987654321;
int n, m;
int arr[110][110];
int ans[110][110];

int n1[4] = { 0,0,1,-1 };
int n2[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1]-'0';
			ans[i][j] = INF;
		}
	}

//	memset(ans, 987654321, sizeof(ans));
	priority_queue<node, vector<node>, greater<node> > pq;

	pq.push(node(1, 1, 0));
	ans[1][1] = 0;

	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int d = pq.top().dist;
		pq.pop();

		if (x == n && y == m) break;
		if (d > ans[x][y]) continue;

		for (int k = 0; k < 4; k++) {
			int nx = x + n1[k];
			int ny = y + n2[k];

			if (nx<1 || nx>n || ny<1 || ny>m) continue;

			if (ans[nx][ny] > ans[x][y] + arr[nx][ny]) {
				ans[nx][ny] = ans[x][y] + arr[nx][ny];
				pq.push(node(nx, ny, ans[nx][ny]));

			}
		}
	}

	/*	for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cout << ans[i][j] << " ";
			cout << endl;
		}
		*/
		cout << ans[n][m];



}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 410;
const int INF = 987654321;

int n, m;
int dist[MAX][MAX];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) dist[i][j] = INF;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int tmp = INF;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;

			if (dist[i][j] != INF && dist[j][i] != INF) {
				tmp = min(tmp, dist[i][j]+dist[j][i]);
			}
		}
	}
	if (tmp == INF) cout << -1;
	else cout << tmp;


}
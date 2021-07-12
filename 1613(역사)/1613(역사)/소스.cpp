#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 410;
const int INF = 987654321;

int n, k;
int dist[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) dist[i][j] = INF;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;

		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int s;
	cin >> s;

	while (s--) {
		int a, b;
		cin >> a >> b;

		if (dist[a][b] == INF && dist[b][a] == INF) cout << 0 << '\n';
		else if (dist[a][b] != INF) cout << -1 << '\n';
		else cout << 1 << '\n';
	}
}
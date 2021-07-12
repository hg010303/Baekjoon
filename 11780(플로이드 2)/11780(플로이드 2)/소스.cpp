#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 110;
const int INF = 987654321;

int n, m;
vector<int> v;
int dist[MAX][MAX];
int route[MAX][MAX];

void f(int start, int fin) {
	if (!route[start][fin]) {
		v.push_back(start);
		v.push_back(fin);
		return;
	}
	f(start, route[start][fin]);
	v.pop_back();
	f(route[start][fin], fin);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
			route[i][j] = 0;
		}


	

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		dist[a][b] = min(dist[a][b], c);
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;

				if (dist[i][j] > dist[i][k] + dist[k][j]) {

					dist[i][j] = dist[i][k] + dist[k][j];
					route[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << 0 << endl;
				continue;
			}

			v.clear();
			f(i, j);
			cout << v.size() << " ";
			for (auto k : v) cout << k << " ";
			cout << endl;
		}

	}

}
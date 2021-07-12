#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 110;
const int INF = 987654321;

int n, m;
int dist[MAX][MAX];
int maxi[MAX];
bool flag[MAX];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		dist[a][b] = 1;
		dist[b][a] = 1;
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

/*	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 1; i <= n; i++) {
		int tmp = 0;

		for (int j = 1; j <= n; j++) {
			if (dist[i][j]<INF && dist[i][j] > maxi[i]) {
				maxi[i] = dist[i][j];
			}
		}
	}

	vector<int> v;

	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			int t = i;
			for (int j = i; j <= n; j++) {
				if (dist[i][j] < INF) {
					flag[j] = true;
					if (maxi[t] > maxi[j])
						t = j;
				}
			}
			v.push_back(t);
		}
	}

	cout << v.size() << endl;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}
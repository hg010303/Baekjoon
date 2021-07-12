#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<queue>

using namespace std;

const int MAX = 20020;
const int INF = 987654321;

int n, m;
int arr[110][110];
int k=-1, h=-1;
int kx, ky;
int hx, hy;
vector<int> v[MAX];
map<pair<int, int>, int> cmap;
map<pair<int, int>, int> fmap;

int main() {
	cin >> n >> m;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;


		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];

			if (arr[i][j] == 'K') {
				k = cnt + 1;
				arr[i][j] = '.';
				kx = i;
				ky = j;
			}
			if (arr[i][j] == 'H') {
				h = cnt;
				arr[i][j] = '.';
				hx = i;
				hy = j;
			}
			cnt += 2;
		}
	}

	if (n == 1 && m == 1) {
		cout << -1;
		return 0;
	}
	if (abs(kx - hx) + abs(ky - hy) == 1 || k == -1 || h == -1) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n * m; i++) {
		cmap[{2 * i, 2 * i + 1}] = 1;
		v[2 * i].push_back(2 * i + 1);
		cmap[{2 * i+1, 2 * i}] = 0;
		v[2 * i+1].push_back(2 * i);
	}

	int from = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 1 < m && arr[i][j] != '#' && arr[i][j + 1] != '#') {
				int to = from + 2;
				cmap[{from + 1, to}] = INF;
				cmap[{to, from + 1}] = 0;
				v[from + 1].push_back(to);
				v[to].push_back(from+1);


				cmap[{to + 1, from}] = INF;
				cmap[{from, to + 1}] = 0;
				v[to + 1].push_back(from);
				v[from].push_back(to + 1);
			}

			if (i + 1 < n && arr[i][j] != '#' && arr[i+1][j] != '#') {
				int to = 2*m+from;
				cmap[{from + 1, to}] = INF;
				cmap[{to, from + 1}] = 0;
				v[from + 1].push_back(to);
				v[to].push_back(from + 1);


				cmap[{to + 1, from}] = INF;
				cmap[{from, to + 1}] = 0;
				v[to + 1].push_back(from);
				v[from].push_back(to + 1);
			}
			from += 2;
		}
	}

	int total = 0;

	while (true) {
		int prev[MAX];
		memset(prev, -1, sizeof(prev));

		queue<int> q;
		q.push(k);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (auto next : v[now]) {
				if (prev[next] != -1) continue;

				if (cmap[{now, next}] - fmap[{now, next}] > 0) {
					q.push(next);
					prev[next] = now;
					if (next == h) break;
				}
			}
		}

		if (prev[h] == -1) break;

		for (int i = h; i != k; i = prev[i]) {
			fmap[{prev[i], i}] += 1;
			fmap[{i, prev[i]}] -= 1;
		}
		total += 1;
	}

	cout << total;
}
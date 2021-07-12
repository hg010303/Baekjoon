#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 100100;
typedef pair<int, int> pii;

int n, m, c;
vector<pii> v[MAX];
int arr[MAX];
int indeg[MAX];
int ans[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> c;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 0; i < c; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		v[x].push_back({ y,z });
		indeg[y]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		ans[i] = arr[i];
		if (!indeg[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (auto i : v[now]) {
			int next = i.first;
			int weight = i.second;


			indeg[next]--;
			if (ans[now] + weight > m) continue;

			ans[next] = max(ans[next], ans[now] + weight);

			
			if (!indeg[next]) q.push(next);
 		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}
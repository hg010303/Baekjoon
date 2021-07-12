#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 800 + 10;
const int INF = 987654321;

int n, m;
int a, b;
vector<pii> v[MAX];
int arr[MAX];

int dijkstra(int a, int b) {
	fill(arr, arr + n+1, INF);

	priority_queue<pii> pq;
	pq.push({ 0,a });
	arr[a] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (arr[now] < dist) continue;

		for (auto i: v[now]) {
			int cost = dist + i.second;

			if (cost < arr[i.first]) {
				arr[i.first] = cost;
				pq.push({ -cost,i.first });
			}
		}
	}
	return arr[b];
	
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({ y,z });
		v[y].push_back({ x,z });
	}
	cin >> a >> b;

	int ab = dijkstra(a,b);
	if (ab == -1) {
		cout << -1 << endl;
		return 0;
	}

	int a1 = dijkstra(1, a);
	int b1 = dijkstra(1, b);
	int an = dijkstra(a, n);
	int bn = dijkstra(b, n);

	int ans = INF;
	if (a1 != INF && bn != INF) {
		ans = min(ans, a1 + ab + bn);
	}
	if (b1 != INF && an != INF) {
		ans = min(ans, b1 + ab + an);
	}

	if (ans == INF) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}
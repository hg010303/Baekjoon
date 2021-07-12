#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 1010;
const int INF = 987654321;

int n, m, x;
int dist[MAX];
int answer[MAX];
vector<pair<int, int> > v[MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int>,vector<pair<int,int> >, greater<pair<int,int> > > q;
	dist[start] = 0;
	q.push({ start,0 });

	while (!q.empty()) {
		int now = q.top().first;
		int dir = q.top().second;
		q.pop();

		for (auto i : v[now]) {
			int next = i.first;
			int cost = i.second;

			if (dist[next] > cost + dir) {
				dist[next] = cost + dir;
				q.push({ next,dist[next] });
			}
		}
	}
}

int main() {
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dist[j] = INF;
		dijkstra(i);
		answer[i] = dist[x];
	}
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dijkstra(x);
	for (int i = 1; i <= n; i++) answer[i] += dist[i];
	sort(answer+1, answer + n+1);
	cout << answer[n];
}
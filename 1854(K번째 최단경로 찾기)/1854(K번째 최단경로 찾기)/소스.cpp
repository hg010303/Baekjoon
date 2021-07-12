#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 1010;
typedef struct pair<int, int> pii;

int n, m, k;
vector<pii> v[MAX];
priority_queue<int> heap[MAX];

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({ 0,1 });
	heap[1].push(0);
	

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
//		cout << now << endl;
		for (auto i : v[now]) {
			int next = i.first;
			int dis = i.second + cost;

			if (heap[next].size() < k) {
				heap[next].push(dis);
				pq.push({ dis,next });
			}
			else if (heap[next].top() > dis) {
				heap[next].pop();
				heap[next].push(dis);
				pq.push({ dis,next });

			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}


	dijkstra();

	for (int i = 1; i <= n; i++) {
		if (heap[i].size() != k) cout << -1 << endl;
		else cout << heap[i].top() << endl;
	}
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

const int MAX = 1010;

int n, m;
vector<pair<int, int> > v[MAX];
int dis[MAX];
int indegree[MAX];
int parent[MAX];

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		indegree[b]++;
	}

	queue<int> q;
	q.push(1);

	while (indegree[1]) {
		auto now = q.front();
		q.pop();

		for (auto i : v[now]) {
			int next = i.first;
			int distance = i.second;

			if (dis[next] < dis[now] + distance) {
				parent[next] = now;
				dis[next] = dis[now] + distance;
			}

			indegree[next]--;

			if (indegree[next] == 0) q.push(next);
		}
	}

	stack<int> s;
	s.push(1);
	int cur = parent[1];
	while (cur != 1) {
		s.push(cur);
		cur = parent[cur];
	}
	s.push(1);


	cout << dis[1] << endl;

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}
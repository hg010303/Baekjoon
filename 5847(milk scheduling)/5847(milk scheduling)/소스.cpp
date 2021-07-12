#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 50100;

int n, m;
int arr[MAX];
int indegree[MAX];
vector<int> v[MAX];
int dis[MAX];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			dis[i] = arr[i];
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : v[now]) {
			dis[next] = max(dis[next], dis[now] + arr[next]);
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) answer = max(answer, dis[i]);

	cout << answer << endl;

}
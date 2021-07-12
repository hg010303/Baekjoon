#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, m;

vector<pair<int, int> > v[100100];
int maxi = 0;
bool visit[100100];
int start, fin;

bool bfs(int cost) {
	queue<int> q;

	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == fin) return true;

		for (auto i : v[now]) {
			int next = i.first;
			int cos = i.second;

			if (visit[next] == false && cost <= cos) {
				visit[next] = true;
				q.push(next);
			}
		}

		
	}
	return false;
	
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });

		maxi = max(maxi, c);
	}
	cin >> start >> fin;

	int low = 0;
	int high = maxi;
	int answer = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		memset(visit, false, sizeof(visit));
		if (bfs(mid)) {
			low = mid + 1;
			answer = mid;
		}
		else high = mid - 1;
	}

	cout << answer << endl;
}
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, k;
int visit[200100];
int parent[200100];




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visit[n] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == k) break;

		if (now + 1 <= k+1 && !visit[now + 1]) {

			q.push(now + 1);
			visit[now + 1] = visit[now] + 1;
			parent[now + 1] = now;
		}

		if (2 * now <= 2 * k+1 && !visit[2 * now]) {
			q.push(2 * now);
			visit[2 * now] = visit[now] + 1;
			parent[2*now] = now;
		}

		if (now - 1 >= 0 && !visit[now - 1]) {
			q.push(now - 1);
			visit[now - 1] = visit[now] + 1;
			parent[now - 1] = now;
		}
	}

	vector<int> ans;

	int idx = k;
	while (true) {
		if (idx == n) break;
		ans.push_back(idx);
		idx = parent[idx];
	}

	ans.push_back(n);

	reverse(ans.begin(), ans.end());

	cout << visit[k] - 1 << '\n';

	for (int i : ans) {
		cout << i << " ";
	}
}
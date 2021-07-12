#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int ladder[101];
int bam[101];
int visit[101];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a] = b;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		bam[a] = b;
	}

	queue<int> q;
	q.push(1);
	visit[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now > 100) continue;
		if (now == 100) break;

		for (int i = 1; i <= 6; i++) {
			int next = now + i;

			if (ladder[next]) next = ladder[next];
			if (bam[next]) next = bam[next];

			if (visit[next]) continue;

			visit[next] = visit[now] + 1;
			q.push(next);
		}
	}

	cout << visit[100] - 1;
}
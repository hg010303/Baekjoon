#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int visit[1000100];

int f, s, g, u, d;


int main() {
	cin >> f >> s >> g >> u >> d;

	queue<int> q;

	q.push(s);
	visit[s] = 1;

	int n[2] = { u,-d };

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == g) break;

		for (int i = 0; i < 2; i++) {
			int next = now + n[i];

			if (next <= 0 || next > f) continue;

			if (!visit[next]) {
				visit[next] = visit[now] + 1;
				q.push(next);
			}
		}
	}

	if (visit[g] == 0) cout << "use the stairs" << endl;
	else cout << visit[g] - 1 << endl;
}
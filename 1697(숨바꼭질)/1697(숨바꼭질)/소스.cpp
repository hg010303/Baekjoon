#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, k;
int visit[200100];



int main() {
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visit[n] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == k) break;

		if (now + 1 <= 2 * k && !visit[now + 1]) {
			
			q.push(now + 1);
			visit[now + 1] = visit[now] + 1;
		}

		if (2 * now <= 2 * k && !visit[2 * now]) {
			q.push(2 * now);
			visit[2 * now] = visit[now] + 1;
		}

		if (now - 1 >= 0 && !visit[now - 1]) {
			q.push(now - 1);
			visit[now - 1] = visit[now] + 1;
		}
	}

	cout << visit[k] - 1;
}
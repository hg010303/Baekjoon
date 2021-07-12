#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, k;
int visit[200100];



int main() {
	cin >> n >> k;

	queue<int> q;

	int n1 = n;

	while (n1 <= 2 * k&&n1!=0) {
		q.push(n1);
		visit[n1] = 1;
		n1 *= 2;
	}

	if (q.empty()) {
		q.push(n1);
		visit[n1] = 1;
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
//		cout << now << " " << visit[now] << '\n';

		if (now == k) break;

		if (now + 1 <= 2 * k && !visit[now + 1]) {
			int cnt = now+1;

			while (cnt <= 2 * k && !visit[cnt]) {
				q.push(cnt);
				visit[cnt] = visit[now] + 1;
				if (cnt == k) break;
				cnt *= 2;
			}
		}


		if (now - 1 >= 0 && !visit[now - 1]) {
			int cnt = now - 1;
			q.push(cnt);
			visit[cnt] = visit[now] + 1;
			cnt *= 2;
			while (cnt <= 2 * k && !visit[cnt]&&cnt!=0) {
				q.push(cnt);
				visit[cnt] = visit[now] + 1;
				if (cnt == k) break;
				cnt *= 2;
			}
			if (cnt == 0) {
				q.push(0);
				visit[cnt] = visit[now] + 1;
			}
		}
	}

	cout << visit[k] - 1;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>

using namespace std;

int start, fin;
int prime[10100];
int visit[10100];

int main() {

	for (int i = 1; i <= 10000; i++) {
		prime[i] = i;
	}
	for (int i = 2; i <= sqrt(10000); i++) {
		if (prime[i] == 0) continue;
		for (int j = i + i; j <= 10000; j += i)
			prime[j] = 0;
	}
	prime[1] = 0;

	int N;
	cin >> N;
	while (N--) {
		cin >> start >> fin;
		if (start == fin) {
			cout << 0<<endl;
			continue;
		}

		memset(visit, -1, sizeof(visit));

		queue<int> q=queue<int>();
		visit[start] = 0;
		q.push(start);

		while (!q.empty()) {
			int now = q.front();
			q.pop();
//			cout << now << " " << visit[now] << endl;
			if (now == fin) break;

			for (int i = 0; i <= 9; i++) {
				int n1 = i * 1000 + now % 1000;
				int n2 = (now / 1000) * 1000 + i * 100 + now % 100;
				int n3 = (now / 100) * 100 + i * 10 + now % 10;
				int n4 = (now / 10) * 10 + i;
//				cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;

				if (visit[n1] == -1 && i != 0 && prime[n1] != 0) {
					visit[n1] = visit[now] + 1;
					q.push(n1);
				}
				if (visit[n2] == -1 && prime[n2] != 0) {
					visit[n2] = visit[now] + 1;
					q.push(n2);
				}
				if (visit[n3] == -1 && prime[n3] != 0) {
					visit[n3] = visit[now] + 1;
					q.push(n3);
				}
				if (visit[n4] == -1 && prime[n4] != 0) {
					visit[n4] = visit[now] + 1;
					q.push(n4);
				}
			}
		}
		if (visit[fin] != -1)
			cout << visit[fin] << endl;
		else cout << "Impossible" << endl;
	}
}
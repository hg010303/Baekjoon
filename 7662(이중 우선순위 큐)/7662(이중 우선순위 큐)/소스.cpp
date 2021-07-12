#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;

bool visit[1000100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		priority_queue<pii, vector<pii>, less<pii> > maxq = priority_queue<pii, vector<pii>, less<pii>>();
		priority_queue<pii, vector<pii>, greater<pii> > minq = priority_queue<pii, vector<pii>, greater<pii>>();
		memset(visit, false, sizeof(visit));

		int n;
		cin >> n;

		int idx = 0;
		int cnt = 0;

		while (n--) {
			char a;
			int b;
			cin >> a >> b;
			

			if (a == 'I') {
				minq.push({ b,idx });
				maxq.push({ b,idx });

				visit[idx++] = true;
			}

			if (a == 'D') {
				if (b == 1) {
					while (!maxq.empty() && !visit[maxq.top().second]) maxq.pop();
					if (!maxq.empty()) {
						visit[maxq.top().second] = false;
						maxq.pop();
					}
				}

				if (b == -1) {
					while (!minq.empty() && !visit[minq.top().second]) minq.pop();
					if (!minq.empty()) {
						visit[minq.top().second] = false;
						minq.pop();
					}
				}
			}
		}
		while (!maxq.empty() && !visit[maxq.top().second]) maxq.pop();
		while (!minq.empty() && !visit[minq.top().second]) minq.pop();

		if (minq.empty() && maxq.empty()) cout << "EMPTY" << endl;
		else cout << maxq.top().first << " " << minq.top().first << endl;
	}
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;

int n, k;
vector<pii> v;
int dist[1010][1010];
bool visit[1010];

int calc(pii a, pii b) {
	double d = sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));

	int s = (int)d;

	if (d-(double)s==0) return s / 10;
	else return s / 10 + 1;
}

bool f(int mid) {
	memset(visit, false, sizeof(visit));
	queue<pii> q;

	q.push({ 0,0 });
	visit[0] = true;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		if (now.second > k) break;

		if (calc({ 10000,10000 }, v[now.first]) <= mid) {
			if (now.second <= k) return true;
		}

		for (int i = 1; i <= n; i++) {
			if (visit[i]) continue;
			if (dist[now.first][i] > mid) continue;

			visit[i] = true;
			q.push({ i,now.second + 1 });
		}
	}

	return false;
}

int main() {
	cin >> n >> k;

	v.push_back({ 0,0 });
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i != j) {
				dist[i][j] = calc(v[i], v[j]);
			}
		}
	}

/*	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/


	int low = 1;
	int high = 1500;
	int ans = high;

	while (low <= high) {
		int mid = low + high >> 1;

//		cout << mid << endl;

		if (f(mid)) {
			ans = min(ans, mid);
			high = mid - 1;
		}
		else low = mid + 1;
	}

	cout << ans << endl;
}
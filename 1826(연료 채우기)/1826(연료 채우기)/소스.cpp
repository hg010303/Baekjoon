#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> v;
int l, p;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	cin >> l >> p;

	sort(v.begin(), v.end());

	priority_queue<int> q;

	if (l <= p) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (v[i].first <= p) {
			q.push(v[i].second);
		}
		else {
			while (!q.empty() && v[i].first > p) {
				p += q.top();
				q.pop();
				ans++;
			}
			if (l <= p) break;
			if (q.empty()&&v[i].first>p) {
				cout << -1 << endl;
				return 0;
			}
			q.push(v[i].second);
		}
	}

	while (!q.empty() && l > p) {
		p += q.top();
		q.pop();
		ans++;
	}
	if (q.empty() && l > p) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;
}
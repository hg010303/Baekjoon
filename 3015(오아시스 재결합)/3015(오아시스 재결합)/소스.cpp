#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

int n;

int main() {
	cin >> n;

	stack<pair<int, int> > s;

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		while (!s.empty() && s.top().first < a) {
			ans += s.top().second;
			s.pop();
		}

		if (s.empty()) s.push({ a,1 });
		else {
			if (s.top().first == a) {
				auto cur = s.top();
				s.pop();

				ans += cur.second;

				if (!s.empty()) ans++;

				cur.second++;
				s.push(cur);
			}
			else {
				s.push({ a,1 });
				ans++;
			}
		}
	}

	cout << ans << endl;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 61;
const long long CON = 1000000007;
typedef unsigned long long ull;

int n;
long long arr[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		cin >> n;

		priority_queue<ull, vector<ull>, greater<ull> > q = priority_queue<ull, vector<ull>, greater<ull> >();

		for (int i = 0; i < n; i++) {
			ull a;
			cin >> a;
			q.push(a);
		}

		ull ans = 1;

		if (n == 1) {
			cout << ans << '\n';
			continue;
		}

		while (q.size() >= 2) {
			ull a = q.top();
			q.pop();
			ull b = q.top();
			q.pop();

			ull c = a * b;
			ull d = a * b;
			d%= CON;
			ans *= d;
			ans %= CON;

			q.push(c);
		}

		cout << ans << '\n';
	}
}
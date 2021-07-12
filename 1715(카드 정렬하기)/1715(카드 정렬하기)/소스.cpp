#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n;

int main() {
	cin >> n;

	priority_queue<int, vector<int>, greater<int> > q;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	int ans = 0;

	while (q.size() >= 2) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();

		ans += (a + b);

		q.push(a + b);
	}

	cout << ans << endl;
}
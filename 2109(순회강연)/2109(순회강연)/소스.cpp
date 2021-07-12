#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n;
pair<int, int> p[10010];

bool compare(pair<int, int>& p, pair<int, int>& q) {
	return p.first > q.first;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p[i] = { b,a };
	}

	priority_queue<int> pq;
	sort(p, p + n, compare);



	int idx = 0;
	long long result = 0;
	
	for (int i = 10000; i >0; i--) {
		while (idx < n && p[idx].first >= i) pq.push(p[idx++].second);
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;

}
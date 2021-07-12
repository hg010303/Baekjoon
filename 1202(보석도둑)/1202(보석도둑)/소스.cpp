#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, k;
pair<int, int> jw[300100];
int bag[300100];
priority_queue<int> pq;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		jw[i] = { a,b };
	}
	for (int i = 0; i < k; i++) cin >> bag[i];

	sort(jw, jw + n);
	sort(bag, bag + k);
	
	long long result = 0;
	int idx = 0;

	for (int i = 0; i < k; i++) {
		while (idx < n && jw[idx].first <= bag[i]) pq.push(jw[idx++].second);

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;



}
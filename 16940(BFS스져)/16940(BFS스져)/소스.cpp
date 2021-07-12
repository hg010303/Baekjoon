#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int arr[100010], visit[100010];
int idx = 1;
int n, x, y;

vector<int> v[100010];
queue<int> q;

int main() {
	cin >> n;

	for(int i=0;i<n-1;i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 0; i < n; i++) cin >> arr[i];

	if (arr[0]!=1) {
		cout << 0;
		return 0;
	}

	q.push(1);
	visit[1] = 1;
	set<int> s;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int sz = 0;
		for (int next : v[now]) {
			if (visit[next] == 0) {
				s.insert(next);
				visit[next] = 1;
				sz++;
			}
		}

		for (int i = idx; i < idx + sz; i++) {
			if (s.count(arr[i]) == 0) {
				cout << 0;
				return 0;
			}
			else q.push(arr[i]);
		}
		idx += sz;
	}
	cout << 1;
}
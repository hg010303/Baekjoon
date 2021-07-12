#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

const int CON = 10100;

int n;
vector<int> parent[CON];
vector<int> child[CON];
int num_parent[CON];
int arr[CON];
int maxi[CON];


int main() {
	cin >> n;
	memset(maxi, 0, sizeof(maxi));
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		maxi[i] = arr[i];
		int a;
		cin >> a;
		num_parent[i] = a;
		if (a == 0) q.push(i);

		for (int j = 0; j < a; j++) {
			int t;
			cin >> t;

			parent[i].push_back(t);
			child[t].push_back(i);
		}
	}
	int ans = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
//		cout << now << endl;
		for (int i = 0; i < child[now].size(); i++) {
			int next = child[now][i];
			
			maxi[next] = max(maxi[next], maxi[now] + arr[next]);

			num_parent[next]--;
			if (num_parent[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= n; i++) {
		ans=max(ans, maxi[i]);
	}

	cout << ans << endl;
}
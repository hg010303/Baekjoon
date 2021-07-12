#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<string>

using namespace std;

const int MAX = 10100;
typedef pair<int, int> pii;

int n, m;
vector<pii> v[MAX];
vector<pii> parent[MAX];
int start, finish;
int arr[MAX];
int num_parent[MAX];
bool visit[MAX];
int ans = 0;

int main() {
	memset(visit, false, sizeof(visit));
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		parent[b].push_back({ a,c });
		num_parent[b]++;

	}
	cin >> start >> finish;

	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto i : v[now]) {
			int to = i.first;
			int dis = i.second;

			if (arr[to] < arr[now] + dis) {
				arr[to] = arr[now] + dis;
			}
			
			num_parent[to]--;

			if (num_parent[to] == 0) q.push(to);
		}
	}

	queue<int> q1;
	set<string> s;
	q1.push(finish);

	while (!q1.empty()) {
		int now = q1.front();
		q1.pop();

		for (auto i : parent[now]) {
			int to = i.first;
			int dis = i.second;

			string str = to_string(now) + "/" + to_string(to) + "/" + to_string(dis);
			if (s.find(str)==s.end() && arr[to] == arr[now] - dis) {
				s.insert(str);
				q1.push(to);
				ans++;
			}
		}
	}


	cout << arr[finish] << endl;
	cout << ans << endl;
}
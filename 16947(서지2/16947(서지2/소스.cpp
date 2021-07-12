#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
int n;
vector<int> v[3030];
int visit[3030];
int answer[3030];

int go(int x, int p) {
	if (visit[x] == 1) return x;

	visit[x] = 1;

	for (int y : v[x]) {
		if (y == p) continue;

		int res = go(y, x);
		if (res == -2) return -2;
		if (res >= 0) {
			visit[x] = 2;
			if (x == res) return -2;
			else return res;
		}
	}
	return -1;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1;
		b -= 1;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	go(0, -1);
	
	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (visit[i] == 2) {
			answer[i] = 0;
			q.push(i);
		}
		else answer[i] = -1;
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int y : v[x]) {
			if (answer[y] == -1) {
				q.push(y);
				answer[y] = answer[x] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) cout << answer[i] << " ";

}

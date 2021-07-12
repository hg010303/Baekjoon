#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef struct {
	int a;
	int b;
	int c;
}node;

const int MAX = 60;

node arr[MAX];
vector<int> v[MAX * 2];
bool visit[MAX * 2];
int b[MAX * 2];


int n;

bool dfs(int now) {
	if (visit[now]) return 0;
	visit[now] = 1;

	for (auto next : v[now]) {
		if (!b[next] || dfs(b[next])) {
			b[next] = now;
			return true;
		}
	}
	return false;
}

int bmatch() {
	int ret = 0;
	for (int i = 1; i <= 2*n; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) ret++;
	}
	return ret;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i].a = a;
		arr[i].b = b;
		arr[i].c = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;

			if ((arr[i].a == arr[j].a) && (arr[i].b == arr[j].b) && (arr[i].c == arr[j].c)) {
				if (i > j) {
					v[i].push_back(j);
					v[i + n].push_back(j);
				}
			}

			else if ((arr[i].a >= arr[j].a) && (arr[i].b >= arr[j].b) && (arr[i].c >= arr[j].c)) {
				v[i].push_back(j);
				v[i + n].push_back(j);
			}
		}
	}

	cout << n-bmatch();
}
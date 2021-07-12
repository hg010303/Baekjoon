#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

#define MAX 987654321

using namespace std;

struct Line {
	int from;
	int to;
	int value;
};

Line line[6500];
int arr[550];
int visit[550];
int cnt[550];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> line[i].from >> line[i].to >> line[i].value;

	for (int i = 1; i <= n; i++) {
		arr[i] = MAX;
	}
	arr[1] = 0;

	queue<int> q;
	q.push(1);
	visit[1] = 1;


	while (!q.empty()) {
		int from = q.front();
		visit[from] = 0;
		q.pop();
		for (int j = 0; j < m; j++) {
			if (line[j].from != from) continue;
			int to = line[j].to;
			int value = line[j].value;
			if (arr[to] > arr[from] + value) {
				arr[to] = arr[from] + value;
				if (visit[to] == 0) {
					q.push(to);
					visit[to] = 1;
					cnt[to] += 1;
					if (cnt[to] >= n) {
						cout << "-1" << endl;
						return 0;
					}
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == MAX) {
			cout << "-1" << endl;
		}
		else {
			cout << arr[i] << endl;
		}
	}
}
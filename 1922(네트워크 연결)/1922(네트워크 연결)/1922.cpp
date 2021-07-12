#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int arr[1010][1010];
int ans[1010];
int answer = 0;

struct Custom {
	int node;
	int tmp;
	Custom(int node, int tmp) : node(node), tmp(tmp) {

	};
};

struct cmp {
	bool operator()(Custom a, Custom b) {
		return a.tmp > b.tmp;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b,c;
		cin >> a >> b>> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	priority_queue<Custom, vector<Custom>, cmp> q;

	q.push(Custom(1, 0));

	int size = 0;

	while (size<n) {
		int a = 0;
		if (ans[q.top().node] == 0) {
			a = q.top().node;
			answer += q.top().tmp;
			ans[q.top().node] = 1;
			q.pop();
			size += 1;
		}
		else {
			q.pop();
			continue;
		}

		for (int i = 1; i <= n; i++) {
			if (arr[a][i] !=0 && ans[i]==0) {
				q.push(Custom(i, arr[a][i]));
			}
		}
	}
	cout << answer << endl;
}
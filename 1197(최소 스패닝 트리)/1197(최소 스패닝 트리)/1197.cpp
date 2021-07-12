#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct Arr_ {
	int left;
	int right;
	int tmp;
};

Arr_ arr1[101000];


int visit[10100];
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
	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> arr1[i].left >> arr1[i].right >> arr1[i].tmp;

	}
	
	priority_queue<Custom, vector<Custom>, cmp> q;
	q.push(Custom(1,0));

	int size = 0;
	while (size < v) {
		int a = q.top().node;
		if (visit[a] == 0) {
			visit[a] = 1;
			answer += q.top().tmp;
			size += 1;
			q.pop();

		}
		else {
			q.pop();
			continue;
		}
		for (int i = 0; i < e; i++) {
			if (arr1[i].left==a && visit[arr1[i].right] == 0) {
				q.push(Custom(arr1[i].right,arr1[i].tmp ));
			}
			if (arr1[i].right == a && visit[arr1[i].left] == 0) {
				q.push(Custom(arr1[i].left, arr1[i].tmp));
			}
		}
	}
	cout << answer << endl;
}
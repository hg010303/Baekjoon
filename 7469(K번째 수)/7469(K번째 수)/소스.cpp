#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100010
using namespace std;

int arr[MAX];
vector<int> tree[MAX * 4];
int n, m;

void update(int bucket,int node, int start, int end, int k) {
	if (bucket<start || bucket>end) return;
	tree[node].push_back(k);
	if (start == end) return;
	
	int mid = (start + end) / 2;

	update(bucket,node * 2, start, mid, k);
	update(bucket,node * 2 + 1, mid + 1, end, k);

}

int find(int node, int start, int end, int left, int right, int k) {
	if (end < left || right < start) return 0;
	if (start >= left && right >= end) return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	return find(node * 2, start, (start + end) / 2, left, right, k) + find(node * 2 + 1, (start + end) / 2 + 1, end, left, right, k);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, 1, 1, n, arr[i]);
	}

	for (int i = 0; i < MAX * 4; i++) sort(tree[i].begin(), tree[i].end());

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		int l = -1e9, r = 1e9;
		int mid = (l + r) / 2;

		while (l <= r) {
			mid = (l + r) / 2;
			if (find(1,1,n,a,b,mid)<c) l = mid + 1;
			else r = mid - 1;
		}
		cout << l << endl;

	}
}
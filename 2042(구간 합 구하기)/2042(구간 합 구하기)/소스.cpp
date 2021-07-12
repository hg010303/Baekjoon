#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

ll init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2+1, (start + end) / 2 + 1, end);
}

ll query(vector<ll>& arr, vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	return query(arr, tree, node * 2, start, (start + end) / 2, left, right) + query(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

}

void update(vector<ll>& arr, vector<ll>& tree, int node, int start, int end, int index, ll diff) {
	if (index<start || index>end) return;
	tree[node] = tree[node] + diff;

	if (start != end) {
		update(arr, tree, node * 2, start, (start + end) / 2, index, diff);
		update(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));

	vector<ll> arr(n + 1);
	vector<ll> tree(tree_size);

	for (int i = 1; i <= n; i++) cin >> arr[i];

	init(arr, tree, 1, 1, n);

	for (int i = 0; i < m + k; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(arr, tree, 1, 1, n, b, c-arr[b]);
			arr[b] = c;
		}
		else {
			cout << query(arr, tree, 1, 1, n, b, c)<<'\n';
		}
	}
}
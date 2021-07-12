#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int MAX = 100100;



int n, m;

void init(vector<int>& arr, vector<int>& tree, int node, int start, int end) {
	if (start == end) tree[node] = start;
	else {
		init(arr, tree, node * 2, start, (start + end) / 2);
		init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);

		if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]]) {
			tree[node] = tree[node * 2];
		}
		else tree[node] = tree[node * 2 + 1];
	}

}

int query(vector<int>& arr, vector<int>& tree, int node, int start, int end, int left, int right) {
	if (start>right || left>end) return -1;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	int m1 = query(arr, tree, node * 2, start, mid, left, right);
	int m2 = query(arr, tree, node * 2 + 1, mid + 1, end, left, right);

	if (m1 == -1) return m2;
	if (m2 == -1) return m1;

	if (arr[m1] <= arr[m2]) return m1;
	else return m2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr(MAX);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));

	vector<int> tree(tree_size);

	init(arr, tree, 1, 1, n);
//	cout << arr[tree[1]] << endl;

	while (m--) {
		int a, b;
		cin >> a >> b;

		int m = query(arr, tree, 1, 1, n, a, b);
//		cout << m << endl;
		cout << arr[m] << '\n';
	}
	
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;


void init(vector<int>& arr, vector<int>& tree, int node, int start, int end) {
	if (start == end) tree[node] = start;

	else {
		init(arr, tree, node * 2, start, (start + end) / 2);
		init(arr, tree, node * 2+1, (start + end) / 2+1, end);

		if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else tree[node] = tree[node * 2 + 1];
	}
}

int query(vector<int>& arr, vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	int m1 = query(arr, tree, node * 2, start, mid, left, right);
	int m2 = query(arr, tree, node * 2 + 1, mid+1,end, left, right);

	if (m1 == -1) return m2;
	if (m2 == -1) return m1;

	if (arr[m1] <= arr[m2]) return m1;
	else return m2;
}

long long get(vector<int> &arr, vector<int> &tree,int start, int end){
	int m = query(arr, tree, 1, 0, arr.size() - 1, start, end);
	long long ans = (long long)(end - start + 1) * (long long)arr[m];

//	cout << m << endl;

	if (start <= m - 1) {
		long long tmp = get(arr, tree, start, m - 1);
		ans = max(ans, tmp);
	}
	if (m + 1 <= end) {
		long long tmp = get(arr, tree, m + 1, end);
		ans = max(ans, tmp);
	}
	return ans;
}

int main() {
	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;

		vector<int> arr(n);

		for (int i = 0; i < n; i++) cin >> arr[i];

		int h = (int)(ceil(log2(n) + 1e-9));
		int tree_size = (1 << (h + 1));

		vector<int> tree(tree_size);

		init(arr, tree, 1, 0, n - 1);

		cout << get(arr, tree, 0, n - 1)<<endl;
	}
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

void maxinit(vector<int>& arr, vector<int> &tree, int node, int start, int end) {
	if (start == end) tree[node] = start;
	else {
		maxinit(arr, tree, node * 2, start, (start + end) / 2);
		maxinit(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);

		if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]]) tree[node] = tree[node * 2 + 1];
		else tree[node] = tree[node * 2];
	}
}

void mininit(vector<int>& arr, vector<int> &tree, int node, int start, int end) {
	if (start == end) tree[node] = start;
	else {
		mininit(arr, tree, node * 2, start, (start + end) / 2);
		mininit(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);

		if (arr[tree[node * 2]] > arr[tree[node * 2 + 1]]) tree[node] = tree[node * 2 + 1];
		else tree[node] = tree[node * 2];
	}
}

int maxquery(vector<int>& arr, vector<int> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return tree[node];
	int m1 = maxquery(arr, tree, node * 2, start, (start + end) / 2,left,right);
	int m2 = maxquery(arr, tree, node * 2+1, (start + end) / 2+1,end, left, right);

	if (m1 == -1) return m2;
	if (m2 == -1) return m1;

	if (arr[m1] > arr[m2]) return m1;
	else return m2;
}

int minquery(vector<int> &arr, vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return tree[node];
	int m1 = minquery(arr, tree, node * 2, start, (start + end) / 2, left, right);
	int m2 = minquery(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

	if (m1 == -1) return m2;
	if (m2 == -1) return m1;

	if (arr[m1] < arr[m2]) return m1;
	else return m2;
}

long long maxsum(vector<int>& arr, vector<int> &tree, int start, int end) {
	int m = maxquery(arr, tree,1, 0, arr.size() - 1, start, end);

	long long tmp = (long long)arr[m] * (m - start + 1) * (end-m+ 1);
	
	if (start < m) tmp += maxsum(arr, tree, start, m - 1);
	if (m < end) tmp += maxsum(arr, tree, m + 1, end);
	return tmp;
}

long long minsum(vector<int>& arr, vector<int> &tree, int start, int end) {
	int m = minquery(arr, tree, 1, 0, arr.size() - 1, start, end);

	long long tmp = (long long)arr[m] * (m - start + 1) * (end - m + 1);

	if (start < m) tmp += minsum(arr, tree, start, m - 1);
	if (m < end) tmp += minsum(arr, tree, m + 1, end);
//	cout << start << " " << end << " " << tmp << " "<<m<<endl;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	int h = (int)(ceil(log2(n)) + 1e-9);
	int tree_size = (1 << (h+1));
	vector<int> mintree(tree_size), maxtree(tree_size);
	maxinit(arr, maxtree, 1, 0, n - 1);
	mininit(arr, mintree, 1, 0, n - 1);
	/*
	for (int i = 0; i < mintree.size(); i++) cout << mintree[i] << " ";
		cout << endl;
		*/

//	cout << minsum(arr, mintree, 0, n - 1) << endl;
	cout << maxsum(arr, maxtree, 0, n - 1) - minsum(arr, mintree, 0, n - 1);
}
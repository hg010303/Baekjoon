#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int first;
	int second;
	int tmp;

	node(int first, int second, int tmp) :first(first), second(second), tmp(tmp) {};
};

int n;
vector<node> v;

bool cmp(const node& a, const node& b) {
	return a.second*b.first>b.second*a.first;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back(node(a,b,i+1));
	}

	stable_sort(v.begin(), v.end(), cmp);

	int ans[1010];

	for (int i = 0; i < n; i++) {
		cout << v[i].tmp<<" ";
	}
}
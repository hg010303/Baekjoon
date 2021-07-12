#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int x;
	int y;
	int camera;

	node(int x, int y, int c) :x(x), y(y), camera(c) {};
};

int n, m;
int arr[9][9];

vector<node> v;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			v.push_back()
		}
	}


}
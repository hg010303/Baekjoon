#include<iostream>
#include<algorithm>

using namespace std;

int arr[550][550];

pair<int, int> n1[] = { {1,0},{1,0},{0,1},{0,1},{1,0} ,{1,0},{1,0},{0,1} ,{1,0},{1,0},{0,1},{1,0} ,{1,0},{0,1},{-1,1},{1,0},{1,-1},{-1,1},{0,-1} };
pair<int, int> n2[] = { {1,1},{2,0},{0,2},{0,2},{2,0} ,{1,1},{2,0},{0,2} ,{2,0},{0,1},{1,1},{1,-1},{1,1},{1,1},{0,1} ,{2,0},{1,0} ,{0,1} ,{1,0} };
pair<int, int> n3[] = { {0,1},{3,0},{0,3},{1,2},{2,-1},{1,2},{0,1},{-1,2},{2,1},{0,2},{2,1},{0,1} ,{2,1},{1,2},{1,0} ,{1,1},{1,1} ,{1,1} ,{0,1} };

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 19; k++) {
				int a = arr[i + n1[k].first][j + n1[k].second] + arr[i + n2[k].first][j + n2[k].second] + arr[i + n3[k].first][j + n3[k].second];
				a += arr[i][j];
				ans = max(a, ans);
			}
		}
	}
	cout << ans;
}
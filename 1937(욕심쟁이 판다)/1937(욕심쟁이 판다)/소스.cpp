#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int arr[510][510];
int memo[510][510];
int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };

int f(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return 0;

	int& ret = memo[x][y];
	if (ret!=-1) return ret;
	ret = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + n1[i];
		int ny = y + n2[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (arr[nx][ny] <= arr[x][y]) continue;

		ret=max(ret, f(nx, ny));
	}
	ret++;
	return ret;
}


int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(memo, -1, sizeof(memo));
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for(int j=0;j<n;j++){
			ans = max(ans, f(i, j));
		}
	}

	cout << ans;
}
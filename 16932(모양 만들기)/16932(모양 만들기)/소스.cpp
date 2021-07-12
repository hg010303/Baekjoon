#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct node {
	int x, y, dir;

	node(int x, int y, int dir) :x(x), y(y), dir(dir) {};
};

int n, m;
int arr[1010][1010];
int arr1[1010][1010];
bool visit[1010][1010];
int cnt = 1;
int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };
int a[1000 * 1000 + 100];
int check[4];
int ans = 0;

void dfs(int i, int j) {

	for (int k = 0; k < 4; k++) {
		int nx = i + n1[k];
		int ny = j + n2[k];

		if (arr1[nx][ny]) continue;
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (arr[nx][ny] == 0) continue;
		arr1[nx][ny] = cnt;
		a[cnt]++;
		dfs(nx, ny);
	}

}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1&&arr1[i][j]==0) {
				arr1[i][j] = cnt;
				a[cnt]++;
				dfs(i, j);
				ans = max(a[cnt],ans);
				cnt++;
			}
		}
	}
/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr1[i][j];
		}
		cout << endl;
	}
	*/


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
//			cout << i << " " << j << endl;
			if (arr[i][j] == 0) {
				int tmp = 1;
				
				for (int k = 0; k < 4; k++) check[k] = 0;
				for (int k = 0; k < 4; k++) {
					bool flag = false;
					int nx = i + n1[k];
					int ny = j + n2[k];
					
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (arr[nx][ny] == 0) continue;

					for (int l = 0; l < k; l++) {
						if (arr1[nx][ny] == check[l]) flag = true;
					}
					check[k] = arr1[nx][ny];
					if(flag==false)
						tmp += a[arr1[nx][ny]];
				}
				ans = max(tmp, ans);
			}
		}
	}

	cout << ans << endl;
}



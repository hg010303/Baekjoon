#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int n;
int arr[3];

int dp[65][65];
int visit[65][65][65];

int n1[6] = { 9,9,3,3,1,1 };
int n2[6] = { 3,1,9,1,9,3 };
int n3[6] = { 1,3,1,9,3,9 };

struct node {
	int a, b, c;
	node(int a, int b, int c) : a(a), b(b), c(c) {}

};

void f2(int a, int b) {
	queue<pair<int, int> > q;
	q.push({ a,b });
	dp[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
//		cout << x << " " << y << " " << dp[x][y] << endl;
		if (x == 0 && y == 0) break;

		int nx, ny;

		nx = x >= 9 ? x - 9 : 0;
		ny = y >= 3 ? y - 3 : 0;

		if (!dp[nx][ny]) {
			dp[nx][ny] = dp[x][y] + 1;
			q.push({ nx,ny });
		}


		nx = x >= 3 ? x - 3 : 0;
		ny = y >= 9 ? y - 9 : 0;

		if (!dp[nx][ny]) {
			dp[nx][ny] = dp[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	cout << dp[0][0]-1;
}

void f3(int a, int b,int c) {
	queue<node > q;
	q.push(node(a,b,c));
	visit[a][b][c] = 1;

	while (!q.empty()) {
		int x = q.front().a;
		int y = q.front().b;
		int z = q.front().c;
		q.pop();
//		cout << x << " " << y << " " <<" "<<z<<" "<< visit[x][y][z] << endl;
		if (x == 0 && y == 0&&z==0) break;


		for (int i = 0; i < 6; i++) {
			int nx = x >= n1[i] ? x - n1[i] : 0;
			int ny = y >= n2[i] ? y - n2[i] : 0;
			int nz = z >= n3[i] ? z - n3[i] : 0;

			if (!visit[nx][ny][nz]) {
				visit[nx][ny][nz] = visit[x][y][z] + 1;
				q.push(node(nx,ny,nz));
			}
		}
	}

	cout << visit[0][0][0] - 1;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	if (n == 1) {
		cout << (arr[0] - 1) / 9 + 1;
		return 0;
	}

	if (n == 2) {
		f2(arr[0], arr[1]);
	}
	if (n == 3) {
		f3(arr[0], arr[1], arr[2]);
	}
}
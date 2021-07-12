#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m;
int arr[1010][1010];
int memo[1010][1010][3];

//cnt==1 오른쪽x, cnt==2 왼쪽x, cnt==0 둘다 ㅇㅋ
int f(int x, int y, int cnt) {
	if (x <= 0 || y <= 0 || x > n || y > m) return -987654321;
	if (x == 1 && y == 1) return arr[1][1];
//	cout << x << " " << y << endl;
	int& ret = memo[x][y][cnt];

	if (ret != -1) return ret;

	ret = arr[x][y];
	if (cnt == 1) {
		ret += max(f(x, y-1, 1), f(x-1, y, 0));
	}
	else if (cnt == 2) {
		ret += max(f(x, y+1, 2), f(x-1, y, 0));
	}
	else {
		ret += max(f(x, y-1, 1),max(f(x, y+1, 2), f(x-1, y, 0)));
	}

	return ret;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	memset(memo, -1, sizeof(memo));

	cout << f(n, m, 1)<<endl;
/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout<< max(memo[i][j][0],max(memo[i][j][1],memo[i][j][2]))<<" ";
		}
		cout << endl;
	}
	*/
}
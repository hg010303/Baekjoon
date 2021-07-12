#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 987654321;
//0일경우 가로 1일경우 세로

int memo[10 * 10 + 10][1024];
int n, m;
char arr[11][11];

int f(int idx, int bin) {
	if (idx >= n * m) {
		return 0;
	}

	int& ret = memo[idx][bin];
	if (ret != -1) return ret;
	ret = MAX;

	int x = idx / m;
	int y = idx % m;

	if (arr[x][y] == '#') return ret = f(idx + 1, bin >> 1);

	//세로로 놓을 경우
	if (x == 0) {
		ret = min(ret,f(idx + 1, (bin >> 1) | (1 << (m - 1)))+1);
	}
	if (x > 0) {
		if (arr[x - 1][y] == '#' || ((bin & 1) == 0)) ret = min(ret, f(idx + 1, (bin >> 1) | (1 << (m - 1))) + 1);
		else ret = min(ret, f(idx + 1, (bin >> 1) | (1 << (m - 1))));
	}
	//가로로 놓을 경우
	if (y == 0) {
		ret = min(ret, f(idx + 1, bin >> 1) + 1);
	}
	if (y > 0) {
		if (arr[x][y-1] == '#' || ((bin & (1<<(m-1))))) ret = min(ret, f(idx + 1, (bin >> 1)) + 1);
		else ret = min(ret, f(idx + 1, (bin >> 1)));
	}
	return ret;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
		}
	}

	memset(memo, -1, sizeof(memo));

	cout << f(0, 0);
}
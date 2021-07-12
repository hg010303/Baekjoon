#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;


int n, m;
char arr[26][11];
int memo[11*26][2050];


int f(int idx, int bin) {
	if (idx >= n * m) {
		if (bin == 0) return 0;
		else return -1;
	}

	int& ret = memo[idx][bin];
	if (ret != -1) return ret;
	ret = 0;

	int x = idx % m;
	int y = idx / m;

	if (bin & 1) return ret = f(idx + 1, bin >> 1);
	if (arr[y][x] == '1') return ret = f(idx + 1, bin >> 1)+1;

	ret = max(ret, f(idx + 1, bin>>1) + 1);

	if (x != m - 1 && y != n - 1) {
		if (((bin & 2) == 0) && arr[y][x+1]=='.'&& arr[y + 1][x] == '.' && arr[y + 1][x + 1] == '.') ret = max(ret, 16+ f(idx + 2, (bin >> 2) | (1 << m - 1) | (1 << (m - 2))));
	}

	return ret;
}


int main() {
	cin >> m >> n;

	memset(memo, -1, sizeof(memo));

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) arr[j][i] = str[j];
	}


	cout << f(0, 0);

	
}

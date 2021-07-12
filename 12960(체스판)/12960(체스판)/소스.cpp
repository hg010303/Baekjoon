#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int n, m;

char arr[50][5];
int memo[50 * 5][33];

int f(int idx, int bin) {
	if (idx >= n * m) if (bin == 0) return 0;
	else return -1;

	int& ret = memo[idx][bin];
	if (ret != -1) return ret;
	ret = 0;
	int x = idx / m;
	int y = idx % m;

	if (bin & 1) return ret = f(idx + 1, bin >> 1);
	if (arr[x][y] == 'X') return ret = f(idx + 1, bin >> 1);

	ret = max(ret, f(idx + 1, bin >> 1));

	if (x < n - 1) {
		if ((x + y) % 2 == 0) {
			if (y < m - 1 && arr[x][y + 1] == '.' && arr[x + 1][y] == '.' && ((bin & 2) == 0) && ((bin & (1 << m)) == 0)) ret = max(ret, f(idx + 2, (bin >> 2) | (1 << (m - 2))) + 1);
		}
		else {
			if (y < m - 1 && arr[x][y + 1] == '.' && arr[x + 1][y + 1] == '.' && ((bin & 2) == 0)) ret = max(ret, f(idx + 2, (bin >> 2) | (1 << (m - 1))) + 1);
			if (y < m - 1 && arr[x + 1][y] == '.' && arr[x + 1][y + 1] == '.' && ((bin & (1 << m)) == 0)) ret = max(ret, f(idx + 1, (bin >> 1) | (1 << (m - 1)) | (1 << m)) + 1);
			if (y > 0 && arr[x + 1][y] == '.' && arr[x + 1][y - 1] == '.' && ((bin & (1 << m)) == 0) && (bin & (1 << (m - 1))) == 0) ret = max(ret, f(idx + 1, (bin >> 1) | (1 << (m - 1)) | (1 << (m - 2))) + 1);
		}
	}
//	cout << idx << " " << bin << " "<<ret<<endl;

	return ret;
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < n; j++) arr[j][i] = str[j];
	}

	memset(memo, -1, sizeof(memo));

	if (m == 1) {
		cout << 0 << endl;
		return 0;
	}
	

	cout << f(0, 0) << endl;
}
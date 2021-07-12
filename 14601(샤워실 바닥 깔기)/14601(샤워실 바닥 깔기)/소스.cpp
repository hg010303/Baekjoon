#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int x, y;

int arr[300][300];
int cnt = 0;

bool empty(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] != 0) return false;
		}
	}
	return true;
}

void f(int x, int y, int n) {
	cnt++;
	if (empty(x, y, n / 2)) arr[x + n / 2-1][y + n / 2-1] = cnt;
	if (empty(x, y+n/2, n / 2)) arr[x + n / 2-1][y + n / 2] = cnt;
	if (empty(x+n/2, y, n / 2)) arr[x + n / 2][y + n / 2-1] = cnt;
	if (empty(x+n/2, y+n/2, n / 2)) arr[x + n / 2][y + n / 2] = cnt;

	if (n == 2) return;

	f(x, y, n / 2);
	f(x, y + n / 2, n / 2);
	f(x + n / 2, y, n / 2);
	f(x + n / 2, y + n / 2, n / 2);

}

int main() {
	cin >> n;
	cin >> x >> y;

	arr[y][x] = -1;

	f(1, 1, 1 << n);

	for (int i = (1 << n); i > 0; i--) {
		for(int j=1;j<=(1<<n);j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}
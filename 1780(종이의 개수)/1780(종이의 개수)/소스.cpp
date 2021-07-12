#include<iostream>
#include<algorithm>

using namespace std;

int arr[2200][2200];
int n;
int result[3];

void f(int n, int x, int y) {
	if (n == 1) {
		result[arr[x][y] + 1]++;
		return;
	}

	bool minus = true, zero = true, plus = true;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] == -1) {
				zero = false;
				plus = false;
			}
			if (arr[i][j] == 0) {
				minus = false;
				plus = false;
			}
			if (arr[i][j] == 1) {
				zero = false;
				minus = false;
			}
		}
	}

	if (minus) result[0]++;
	else if (zero) result[1]++;
	else if (plus) result[2]++;
	else {
		int div = n / 3;

		f(div, x,y);
		f(div, x + div, y);
		f(div, x + 2 * div, y);

		f(div, x, y+div);
		f(div, x + div, y + div);
		f(div, x + 2 * div, y + div);

		f(div, x, y+2*div);
		f(div, x + div, y + 2 * div);
		f(div, x + 2 * div, y + 2 * div);

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	f(n, 0, 0);
	for (int i = 0; i < 3; i++) {
		cout << result[i] << endl;
	}
}

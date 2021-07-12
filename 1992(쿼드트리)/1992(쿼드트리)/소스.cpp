#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;
int arr[100][100];

void f(int x, int y, int n) {
	if (n == 1) {
		cout << arr[x][y];
		return;
	}

	bool zero = true;
	bool one = true;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] == 0) one = false;
			if (arr[i][j] == 1) zero = false;
			if (zero == false && one == false) break;
		}
		if (zero == false && one == false) break;
	}

	if (one) {
		cout << 1;
		return;
	}
	else if (zero) {
		cout << 0;
		return;
	}
	else {
		cout << "(";
		f(x, y, n / 2);
		f(x, y+n/2, n / 2);
		f(x+n/2, y, n / 2);
		f(x + n / 2, y + n / 2, n / 2);
		cout << ")";
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	f(0, 0, n);
}
#include<iostream>

using namespace std;

char arr[][6] = { "  *  ",
			   " * * ",
			   "*****" };

int map[3500][6500];

void star(int y, int x, int n) {
	if (n == 1) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++)
				map[y + i][x + j] = arr[i][j];
		return;
	}
	star(y, x + 3 * n / 2, n/2);
	star( y+3*n/2, x, n / 2);
	star(y + 3 * n / 2, x + 3 * n, n / 2);
}

int main() {
	int n;
	cin >> n;
	star(0, 0,n/3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n-1; j++) {
			printf("%c", map[i][j] == '*' ? '*' : ' ');
		}
		cout << endl;
	}
}
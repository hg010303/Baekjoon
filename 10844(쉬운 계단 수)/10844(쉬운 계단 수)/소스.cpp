#include<iostream>
#define CON 1000000000

using namespace std;

long long arr[110][10];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) arr[1][i] = 1;

	for (int i = 2; i <= 100; i++) {
		arr[i][0] = arr[i - 1][1]%CON;
		for (int j = 1; j <= 8; j++) arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1])%CON;
		arr[i][9] = arr[i - 1][8] % CON;;
	}

	long long ans = 0;

	for (int i = 0; i <= 9; i++) {
		ans += arr[n][i];
		ans %= CON;
	}

	cout << ans;
}
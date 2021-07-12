#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int arr[10];
int ans = 0;

bool check(int n) {
	if (n == 0 & arr[0]) return false;
	while (n != 0) {
		int a = n % 10;
		if (arr[a]) return false;
		n /= 10;
	}

	return true;
}

int check2(int n) {
	if (n == 0) return 1;
 	int a = 0;
	while (n != 0) {
		n /= 10;
		a++;
	}
	return a;
}
int main() {
	int n;
	cin >> n;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		arr[a] = 1;
	}

	ans = abs(n - 100);

	int tmp = 0;

	while (tmp<=abs(n-100)) {
		if (check(n + tmp)) ans = min(ans, tmp + check2(n + tmp));
		if (n - tmp >= 0) {
			if (check(n - tmp)) ans = min(ans, tmp + check2(n - tmp));
		}
		tmp++;
	}
	cout << ans;
}
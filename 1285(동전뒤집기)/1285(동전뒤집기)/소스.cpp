#include<iostream>

using namespace std;

int n;
int coin[21];
int ans = 401;

void output(int a) {
	if (a == n + 1) {
		int total = 0;
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
			int cnt = 0;
			for (int j = 1; j <= n; j++)
				if (coin[j] & i) cnt++;
			if (cnt < n - cnt) total += cnt;
			else total += n - cnt;
		}
		if (ans > total) ans = total;
	}

	else {
		coin[a] = ~coin[a];
		output(a + 1);
		coin[a] = ~coin[a];
		output(a + 1);
	}
}

int main() {
	cin >> n;
	char c;
	for (int i = 1; i <= n; i++) {
		int x = 1 << n - 1;
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c == 'T')coin[i] += x;
			x /= 2;
		}
	}

	output(1);


	cout << ans;
}
#include<iostream>
#include<algorithm>

using namespace std;

int l, c;
char arr[16];
char ans[16];

void dfs(int now, int x,int a,int b) {
	if (now > c) return;
	if (x == l&&a>=1&&b>=2) {
		for (int i = 0; i < l; i++) cout << ans[i];
		cout << '\n';
	}
	for (int i = now; i < c; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'i') {
			a += 1;
			ans[x] = arr[i];
			dfs(i + 1, x + 1, a, b);
			a -= 1;
		}
		else {
			b += 1;
			ans[x] = arr[i];
			dfs(i + 1, x + 1, a, b);
			b -= 1;
		}
	}
}

int main() {
	cin >> l >> c;

	for (int i = 0; i < c; i++) cin >> arr[i];

	sort(arr, arr + c);

	dfs(0, 0, 0, 0);
}
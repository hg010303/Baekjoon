#include<iostream>
#include<algorithm>
#include<cstring>

const int MAX = 10100;
const int INF = 987654321;

using namespace std;

int n, w;
int arr[MAX][2];
int a[MAX];
int b[MAX];
int c[MAX];

void solve() {
	for (int i = 0; i < n; i++) {
		a[i] = b[i] = c[i] = INF;
	}

	if (arr[0][0] + arr[0][1] <= w) a[0] = 1;
	else a[0] = 2;
	b[0] = 1;
	c[0] = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i][0] + arr[i][1] <= w) a[i] = min(a[i], a[i - 1] + 1);
		if (arr[i][0] + arr[i - 1][0] <= w) {
			if (arr[i][1] + arr[i - 1][1] <= w) {
				if (i >= 2) a[i] = min(a[i], a[i - 2] + 2);
				else a[i] = min(a[i], 2);
			}
		}
		if(arr[i][0] + arr[i - 1][0] <= w)b[i] = min(b[i], c[i - 1] + 1);
		if(arr[i][1] + arr[i - 1][1] <= w)c[i] = min(c[i], b[i - 1] + 1);
		a[i] = min(a[i], a[i - 1] + 2);
		b[i] = min(b[i], a[i - 1] + 1);
		c[i] = min(c[i], a[i - 1] + 1);
		a[i] = min(a[i], b[i] + 1);
		a[i] = min(a[i], c[i] + 1);
	}
}

void print() {
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i < n; i++) cout << b[i] << " ";
	cout << endl;
	for (int i = 0; i < n; i++) cout << c[i] << " ";
	cout << endl;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> n >> w;

		for (int i = 0; i < n; i++) {
			cin >> arr[i][0];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i][1];
		}

		solve();
		int ans =  a[n - 1];


		if (n >= 2) {
			if (arr[0][0] + arr[n - 1][0] <= w) {
				int tmp = arr[0][0];
				int tmp1 = arr[n - 1][0];
				arr[0][0] = arr[n-1][0] = w;
				solve();

				ans = min(ans, c[n - 1]);
//				cout << ans << endl;
				arr[0][0] = tmp;
				arr[n - 1][0] = tmp1;
			}
			if (arr[0][1] + arr[n - 1][1] <= w) {
				int tmp = arr[0][1];
				int tmp1 = arr[n - 1][1];
				arr[0][1] = arr[n - 1][1] = w;
				solve();


				ans = min(ans, b[n - 1]);
//				cout << ans << endl;
				arr[0][1] = tmp;
				arr[n - 1][1] = tmp1;
			}
			if (arr[0][1] + arr[n - 1][1] <= w&& arr[0][0] + arr[n - 1][0] <= w) {
				int tmp = arr[0][0];
				int tmp1 = arr[n - 1][0];
				int tmp2 = arr[0][1];
				int tmp3 = arr[n - 1][1];
				arr[0][0] = arr[n - 1][0] = arr[0][1] = arr[n - 1][1] = w;
				solve();

				ans = min(ans, a[n-2]);
//				cout << ans << endl;
				arr[0][0] = tmp;
				arr[n - 1][0] = tmp1;
				arr[0][1] = tmp2;
				arr[n - 1][1] = tmp3;
			}
		}

		cout << ans << endl;
	}
}
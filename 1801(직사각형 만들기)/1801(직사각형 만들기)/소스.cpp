#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = -987654;

int n;
int arr[20];
int ans = 0;
int su = 0;
bool visit[16][70][70][70][70];

void f(int idx, int a, int b,int c, int d) {
	if (idx == n) {
		if (a == b && c == d) ans = max(ans, b * c);
		return;
	}
	if (a > 70 || b > 70 || c > 70 || d > 70) return;

	if (a == b && c == d) ans = max(ans, b * c);

	if (a < b) swap(a, b);
	if (c < d) swap(c, d);

	if (visit[idx][a][b][c][d]) return;
	visit[idx][a][b][c][d] = true;

	if (c <= a && 4 * c >= su) return;
	if (d <= a && 4 * d >= su) return;
	if (a <= c && 4 * a >= su) return;
	if (b <= c && 4 * b >= su) return;

	if (c <= a && 2 * c+2*a >= su) return;
	if (d <= a && 2 * d+2*a >= su) return;
	if (a <= c && 2* a+2*c >= su) return;
	if (b <= c && 2* b+2*c >= su) return;

	f(idx + 1, a, b, c, d);
	f(idx + 1, a + arr[idx], b, c, d);
	f(idx + 1, a, b + arr[idx], c, d);
	f(idx + 1, a, b, c + arr[idx], d);
	f(idx + 1, a, b, c, d + arr[idx]);

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		su += arr[i];
	}

	f(0, 0, 0, 0, 0);
	if (ans) cout << ans << endl;
	else cout << -1 << endl;
}
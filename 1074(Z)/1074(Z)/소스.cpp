#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, r, c;
int ans;

void f(int size, int x, int y) {
	if (size == 2) {
		if (x == r && y == c) {
			cout << ans << endl;
			return;
		}
		ans++;
		
		if (x == r && y+1 == c) {
			cout << ans << endl;
			return;
		}
		ans++;
		if (x + 1 == r && y == c) {
			cout << ans << endl;
			return;
		}
		ans++;
		if (x+1 == r && y+1 == c) {
			cout << ans << endl;
			return;
		}
		ans++;
		return;
	}
	if (x <= r && r < x + size / 2 && y <= c && c < y + size / 2)
		f(size / 2, x, y);
	ans += (size * size) / 4;

	if (x <= r && r < x + size / 2 && y + size / 2 <= c && c < y + size)
		f(size / 2, x, y + size / 2);
	ans += (size * size) / 4;

	if (x + size / 2 <= r && r < x + size && y <= c && c < y + size / 2)
		f(size / 2, x+size/2, y);
	ans += (size * size) / 4;
	
	if (x+size/2 <= r && r < x + size && y + size / 2 <= c && c < y + size)
		f(size / 2, x+ size / 2, y+ size / 2);
	ans += (size * size) / 4;
}

int main() {
	cin >> n >> r >> c;

	f(1<<n, 0, 0);
}
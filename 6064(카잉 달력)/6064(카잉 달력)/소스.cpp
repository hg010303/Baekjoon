#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int firstb = (x-1) % n+1;
		int a = x, b = (x-1)%n+1;
		int ans = x;
		bool flag = true;

		while(true){
			if (a == x && b == y) break;

			b+=m;
			b = (b - 1) % n + 1;

			if (b == firstb) {
				flag = false;
				break;
			}
			ans+=m;
		}

		if (!flag) cout << -1 << endl;
		else cout << ans << endl;

	}
}
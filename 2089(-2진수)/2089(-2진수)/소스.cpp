#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}
	string ans;
	while (n) {
		if (n % 2 == 0) {
			ans += "0";
			n = -(n / 2);
		}
		else {
			if (n > 0) n = -(n / 2);
			else n = (-n + 1) / 2;

			ans += "1";
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}
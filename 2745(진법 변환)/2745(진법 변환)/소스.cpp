#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string a;
	int b;
	int ans = 0;
	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) {
		ans *= b;

		if (a[i] >= '0' && a[i] <= '9') ans += a[i] - '0';
		else ans += a[i] + 10 - 'A';
	}

	cout << ans;

}
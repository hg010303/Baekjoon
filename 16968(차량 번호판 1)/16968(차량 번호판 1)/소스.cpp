#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int ans = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (i == 0) {
			if (str[i] == 'd') ans += 10;
			else ans += 26;
			continue;
		}

		if (str[i] == str[i - 1]) {
			if (str[i] == 'd') ans *= 9;
			else ans *= 25;
		}
		else {
			if (str[i] == 'd') ans *= 10;
			else ans *= 26;
		}
	}
	cout << ans << endl;
}
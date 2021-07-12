#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool flag;
string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;

	while (true) {
		if (s.length() == t.length()) {
			if (s == t) {
				flag = true;
			}
			break;
		}
		char c = t[t.length() - 1];
		t.pop_back();
		if (c == 'B') reverse(t.begin(), t.end());
	}
	cout << flag;
}
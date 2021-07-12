#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int MAX = 1000000 + 1;

string s, b;
char result[MAX];

int main() {
	cin >> s >> b;

	int idx = 0;

	for (int i = 0; i < s.length(); i++) {
		result[idx++] = s[i];

		if (result[idx - 1] == b[b.length() - 1]) {
			if (idx - b.length() < 0) continue;

			bool flag = true;

			for (int j = 0; j < b.length(); j++) {
				if (result[idx - j - 1] != b[b.length() - j - 1]) {
					flag = false;
					break;
				}
			}

			if (flag) idx -= b.length();
		}
	}

	if (!idx) cout << "FRULA";
	else {
		for (int i = 0; i < idx; i++) cout << result[i];
	}
}
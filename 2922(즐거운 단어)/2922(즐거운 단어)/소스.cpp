#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

string s;

long long f(int idx) {
	while (true) {
		if (s[idx] == '\0') {
			int a = 0, b = 0;
			bool flag = false;
			for (int i = 0; i < idx; i++) {
				if (s[i] == 'B' || s[i] == 'L') {
					b++;
					a = 0;
					if (s[i] == 'L') flag = true;
				}
				else if (s[i] == 'A') {
					a++;
					b = 0;
				}
				if (a >= 3 || b >= 3) return 0;
			}
			if (flag == true) return 1;
			else return 0;
		}

		if (s[idx] == '_') {
			long long ret = 0;
			s[idx] = 'A';
			ret += 5 * f(idx + 1);
			s[idx] = 'B';
			ret += 20 * f(idx + 1);
			s[idx] = 'L';
			ret += f(idx + 1);
			s[idx] = '_';
			return ret;
		}
		idx++;
	}
}

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') s[i] = 'A';
		else if (s[i] != '_' && s[i] != 'L') s[i] = 'B';
	}

	cout << f(0);
}


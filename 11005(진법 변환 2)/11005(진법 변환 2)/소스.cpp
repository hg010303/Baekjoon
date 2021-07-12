#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int a, b;

	cin >> a>> b;

	if (a == 0) {
		cout << 0;
		return 0;
	}

	string str;

	while (a != 0) {
		int c = a % b;
		a /= b;

		if (c >= 0 && c <= 9) str.push_back((c + '0'));
		else str.push_back((c + 'A' - 10));
	}

	reverse(str.begin(), str.end());

	
	cout << str;
}
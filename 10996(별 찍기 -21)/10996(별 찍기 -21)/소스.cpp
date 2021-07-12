#include<iostream>
#include<string>

using namespace std;

int main() {
	string str1 = "", str2 = "";

	int n;
	cin >> n;

	if (n == 1) {
		cout << "*";
		return 0;
	}

	for (int i = 0; i < (n + 1) / 2; i++) str1 += "* ";
	for (int i = 0; i < n / 2; i++) str2 += " *";

	for (int i = 0; i < 2*n; i++) {
		if (i % 2 == 0) cout << str1;
		else cout << str2;
		cout << endl;
	}
}
#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;

	string str = "";
	for (int i = 0; i < n - 1; i++) str += "* ";
	str += "*";

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) cout << str;
		else {
			cout << " " << str;
		}
		cout << endl;
	}
}
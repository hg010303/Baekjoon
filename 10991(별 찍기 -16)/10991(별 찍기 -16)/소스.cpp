#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			for (int j = 0; j < n - 1; j++)
				cout << " ";
			cout << "*";
		}
		else {
			string str = "";
			for (int j = 0; j < i; j++) str += "* ";
			str += "*";
			for (int j = 0; j < n - i - 1; j++) cout << " ";
			cout << str;
		}
		cout << endl;
	}
}
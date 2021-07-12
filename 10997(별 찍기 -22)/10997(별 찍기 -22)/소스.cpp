#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int j = 0; j < 4 * n - 3; j++) cout << "*";
	cout << endl;

	int cnt = 0;

	for (int i = 2; i <= 2 * n - 1; i++) {
		if (i == 2) {
			cout << "*" << endl;
			continue;
		}
		for (int j = 0; j <= cnt; j++)
			cout << "* ";
		if (i % 2 == 1)
			for (int j = 0; j < (n - i + cnt + 1) * 4 + 3; j++) cout << "*";
		else if (i % 2 == 0) {
			for (int j = 0; j < (n - i + cnt) * 4 + 3; j++) cout << " ";
		}
		for (int j = 0; j < cnt; j++) cout << " *";
		if (i % 2 == 1) cnt++;
		cout << endl;
	}
	if (n != 1) {
		string str = "";
		for (int i = 0; i < 2 * n - 2; i++) str += "* ";
		str += '*';
		cout << str << endl << str << endl;;


	}
	cnt--;
	for (int i = 2 * n - 2; i >= 2; i--) {
		for (int j = 0; j <= cnt; j++)
			cout << "* ";
		if (i % 2 == 1)
			for (int j = 0; j < (n - i + cnt + 1) * 4 + 1; j++) cout << "*";
		else if (i % 2 == 0) {
			for (int j = 0; j < (n - i + cnt) * 4 + 1; j++) cout << " ";
		}
		for (int j = 0; j <= cnt; j++) cout << " *";
		if (i % 2 == 0) cnt--;
		cout << endl;
	}
	if (n != 1) {
		for (int j = 0; j < 4 * n - 3; j++) cout << "*";
		cout << endl;
	}
}
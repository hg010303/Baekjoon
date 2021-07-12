#include<iostream>
#include<string>

using namespace std;

int n;

int main() {
	cin >> n;
	string str1, str2;

	for (int i = 0; i < n; i++) {
		str1 += "*";
		if (i == 0 || i == n - 1) str2 += "*";
		else str2 += " ";
	}

	cout << str1;
	for (int i = 0; i < 2 * n - 3; i++) cout << " ";
	cout << str1 << endl;

	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j < i; j++) cout << " ";
		cout << str2;
		for (int j = 0; j < 2 * (n - i) - 3; j++) cout << " ";
		cout << str2;
		cout << endl;
	}

	for (int i = 0; i < n - 1; i++) cout << " ";
	cout << '*';
	for (int i = 1; i < n - 1; i++) cout << " ";
	cout << "*";
	for (int i = 1; i < n - 1; i++) cout << " ";
	cout << "*";
	cout << endl;

	for (int i = n-2; i >- 0; i--) {
		for (int j = 0; j < i; j++) cout << " ";
		cout << str2;
		for (int j = 0; j < 2 * (n - i) - 3; j++) cout << " ";
		cout << str2;
		cout << endl;
	}

	cout << str1;
	for (int i = 0; i < 2 * n - 3; i++) cout << " ";
	cout << str1 << endl;
}
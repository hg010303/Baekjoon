#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 666; i <= 9999666; i++) {
		int a = i;
		int a1 = a / 10000;
		a %= 1000000;
		int a2 = a / 1000;
		a %= 100000;
		int a3 = a / 100;
		a %= 10000;
		int a4 = a / 10;
		a %= 1000;
		int a5 = a;

		if (a1 == 666 || a2 == 666 || a3 == 666 || a4 == 666 || a5 == 666) n--;
		if (n == 0) {
			cout << i;
			break;
		}
	}
}
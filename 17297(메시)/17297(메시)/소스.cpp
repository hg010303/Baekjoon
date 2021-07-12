#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int  m;
int f[50] = { 0,5,13 };
string s = "Messi Gimossi";

int main() {
	cin >> m;
	m -= 1;

	for (int i = 3; i <= 40; i++) {
		f[i] = f[i - 1] + f[i - 2] + 1;
	}

	for (int i = 40; i >= 2; i--) {
		if (m >= f[i]) m -= (f[i] + 1);
	}

	if (m == 5 || m == -1) cout << "Messi Messi Gimossi";
	else cout << s[m];
}
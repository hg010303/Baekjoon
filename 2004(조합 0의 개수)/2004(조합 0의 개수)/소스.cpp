#include<iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int nans = 0;
	int nans1 = 0;
	int mans = 0;
	int mans1 = 0;
	int l = n - m;
	int lans = 0;
	int lans1 = 0;
	int n1 = n, m1 = m, l1 = l;

	while (n != 0) {
		nans += n / 5;
		n /= 5;
	}

	while (n1 != 0) {
		nans1 += n1 / 2;
		n1 /= 2;
	}

	while (m != 0) {
		mans += m / 5;
		m /= 5;
	}

	while (m1 != 0) {
		mans1 += m1 / 2;
		m1 /= 2;
	}

	while (l != 0) {
		lans += l / 5;
		l /= 5;
	}

	while (l1 != 0) {
		lans1 += l1 / 2;
		l1 /= 2;
	}

	cout << min(nans - mans - lans,nans1-mans1-lans1);


}
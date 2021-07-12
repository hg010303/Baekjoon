#include<iostream>

using namespace std;

int go(long long a, long long b, long long c) {
	if (b == 0) return 1LL;
	if (b % 2 == 0) {
		long long tmp = go(a, b / 2, c)%c;
		return (tmp * tmp) % c;
	}
	if (b % 2 == 1) {
		return (a*go(a, b - 1, c))%c;
	}
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	cout<<go(a%c, b, c)<<endl;
}
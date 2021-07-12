#include<iostream>
#include<algorithm>

using namespace std;

const int CON = 1000000000;

long long memo[1000100];
int n;

long long f(int idx) {
	if (idx == 1) return 0;
	if (idx == 2) return 1;

	long long& ret = memo[idx];

	if (ret) return ret;

	ret = f(idx - 1) + f(idx - 2);
	ret %= CON;
	ret *= (idx - 1);
	ret %= CON;

	return ret;
}

int main() {
	cin >> n;

	cout << f(n);
}

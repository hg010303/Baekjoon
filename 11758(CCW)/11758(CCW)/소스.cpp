#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int a, b;
	int c, d;
	int e, f;

	cin >> a >> b;
	cin >> c >> d;
	cin >> e >> f;

	int s = (c - a) * (f - b) - (d - b) * (e - a);

	if (s > 0) cout << 1;
	if (s == 0) cout << 0;
	if (s < 0) cout << -1;
}
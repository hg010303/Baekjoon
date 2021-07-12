#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct pair<int, int> pii;

vector<pii> p;

long long ccw(pii a, pii b, pii c) {
	return ((long long)b.first - a.first) * (c.second - a.second) - ((long long)b.second - a.second) * (c.first - a.first);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		p.push_back({ a,b });
	}
	long long ans = 0;
	for (int i = 2; i < n; i++) {
		ans += ccw(p[0], p[i - 1], p[i]);
	}
	if (ans < 0) ans *= -1;

	printf("%lld.", ans / 2);

	if (ans % 2 == 0) printf("0");
	else printf("5");
}
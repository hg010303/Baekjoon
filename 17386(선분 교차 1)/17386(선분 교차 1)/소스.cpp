#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

int ccw(pii a, pii b, pii c) {
	long long s =((long long)b.first - a.first) * ((long long)c.second - a.second) - ((long long)b.second - a.second) * ((long long)c.first - a.first);
	if (s > 0) return 1;
	if (s == 0) return 0;
	if (s < 0) return -1;
}

int main() {
	pair<int, int> p1, p2, q1, q2;

	cin >> p1.first >> p1.second >> p2.first >> p2.second;
	cin >> q1.first >> q1.second >> q2.first >> q2.second;

	
	if (ccw(p1, p2, q1)* ccw(p1, p2, q2) == 0&& ccw(q1, q2, p1) * ccw(q1, q2, p2)==0) {
		if (p1 > p2) swap(p1, p2);
		if (q1 > q2) swap(q1, q2);

		if (p1 <= q2 && q1 <= p2) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else if (ccw(p1, p2, q1) * ccw(p1, p2, q2) <= 0 && ccw(q1, q2, p1) * ccw(q1, q2, p2) <= 0) cout << 1 << endl;
	else cout << 0 << endl;
}
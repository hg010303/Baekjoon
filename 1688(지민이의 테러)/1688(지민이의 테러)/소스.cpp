#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct pair<int, int> pii;
const int CON = 1000000000 + 1;

int n;
vector<pii> v;
pii p[3];

int ccw(pii a, pii b, pii c) {
	long long s = ((long long)b.first - a.first) * ((long long)c.second - a.second) - ((long long)b.second - a.second) * ((long long)c.first - a.first);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

bool cross_line(pii a, pii b, pii c, pii d) {
	int abc = ccw(a, b, c);
	int abd = ccw(a, b, d);
	int cda = ccw(c, d, a);
	int cdb = ccw(c, d, b);

	if (abc * abd == 0 && cda * cdb == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		return c <= b && a <= d;
	}
	return abc * abd <= 0 && cda * cdb <= 0;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		p[i] = { a,b };
	}


	if (n <= 2) {
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		return 0;
	}


	int ans = 0;
	bool flag = 0;

	for (int i = 0; i < 3; i++) {
		pii start = p[i];

		pii end = { CON,p[i].second + 1 };
		ans = 0;
		flag = false;

		for (int j = 0; j < v.size(); j++) {
			pii first = v[j];
			pii second;
			
			if (j == v.size() - 1) {
				second = v[0];
			}
			else second = v[j + 1];

			if (start == first || start == second) flag = true;
			if (ccw(start, first, second) == 0&&first<start&&start<second) flag = true;
			if (ccw(start, first, second) == 0 && second < start && start < first) flag = true;

			if (flag) {
				cout << 1 << endl;
				break;
			}
			
			if (cross_line(start, end, first,second)) ans++;

			

		}
		if (flag) continue;
		if (ans % 2 == 0) cout << 0 << endl;
		else cout << 1 << endl;
	}
}
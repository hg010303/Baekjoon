#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

struct point {
	int x, y;
	int p, q;

	point(int x, int y): x(x),y(y),p(1),q(0){}
};

bool cmp(point a, point b) {
	if ((long long)a.q * b.p != (long long)a.p * b.q) return (long long)a.q * b.p < (long long)a.p* b.q;

	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int ccw(point a, point b, point c) {
	long long s = ((long long)b.x - a.x) * ((long long)c.y - a.y) - ((long long)b.y - a.y) * ((long long)c.x - a.x);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

vector<point> v;
int n;
stack<int> s;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(point(a, b));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i < n; i++) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}
	
	sort(v.begin(), v.end(), cmp);

	s.push(0);
	s.push(1);

	int next = 2;

	while (next < n) {
		while (s.size() >= 2) {
			int first, second;
			second = s.top();
			s.pop();
			first = s.top();

			if (ccw(v[first], v[second], v[next]) > 0) {
				s.push(second);
				break;
			}
		}
		s.push(next++);
	}

	cout << s.size() << endl;
}
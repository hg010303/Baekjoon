#include<iostream>
#include<algorithm>
#define MAX 100000+1

using namespace std;

struct linear {
	long long a, b;
	double s;
	linear() : linear(1, 0) {}
	linear(long long a1, long long b1) : a(a1), b(b1), s(0) {}
};


int a[MAX];
int b[MAX];
int n;
long long dp[MAX] = { 0, };
linear f[MAX];


inline double cross(linear& f, linear& g) {
	return(g.b - f.b) / (f.a - g.a);
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];


	int top = 0,fpos=0;

	for (int i = 1; i < n; i++) {
		linear g(b[i - 1], dp[i - 1]);

		while (top > 0) {
			g.s = cross(f[top - 1], g);
			if (f[top - 1].s < g.s) break;

			if (--top == fpos)--fpos;
		}
		f[top++] = g;

		long long x = a[i];

		while (fpos + 1 < top && f[fpos + 1].s < x) ++fpos;
		if (fpos >= 0) {
			dp[i] = f[fpos].a * x + f[fpos].b;
		}
	}

	if (n >= 0) {
		cout << dp[n - 1];
	}
}
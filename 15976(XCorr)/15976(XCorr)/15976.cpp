#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long x[300100];
long long y[300100];
vector<int> xi, yi;
long long s[300100];
long long ans = 0;

int main() {
	int n,m;
	cin >> n;
	xi.resize(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		x[i] = b;
		xi[i] = a;
	}
	cin >> m;
	yi.resize(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		y[i] = b;
		yi[i] = a;
		s[i + 1] = s[i] + b;
	}
	int a, b;
	cin >> a >> b;
	
	for (int i = 0; i < n; i++) {
		int r = lower_bound(yi.begin(), yi.end(), xi[i] + a) - yi.begin();
		int e = lower_bound(yi.begin(), yi.end(), xi[i] + b + 1) - yi.begin();
		ans += x[i] * (s[e] - s[r]);
	}
	cout << ans << endl;
}
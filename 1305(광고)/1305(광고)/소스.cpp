#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string str, a;

vector<int> getPi(string& p) {
	int m = p.size(), j = 0;
	vector<int> pi(m);

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cin >> str;

	auto ans = getPi(str);

	cout << n - ans[n - 1];
}
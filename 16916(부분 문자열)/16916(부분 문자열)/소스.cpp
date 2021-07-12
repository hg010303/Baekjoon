#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string str, a;

vector<int> getPi(string &p) {
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

bool kmp(string &s, string &p) {
	vector<int> ans;

	vector<int> pi = getPi(p);

	int n = s.size(), m = p.size(), j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				return true;
			}
			else {
				j++;
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str >> a;

	cout << kmp(str, a);
}
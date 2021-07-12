#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<int> getpi(const string& p) {
	int n = p.size(), j = 0;

	vector<int> pi(n,0);

	for (int i = 1; i < n; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];

		if (p[i] == p[j]) pi[i] = ++j;
	}

	return pi;
}

bool kmp(const string& s,const string& p) {
	int n = s.size(), m = p.size(), j = 0;

	auto pi = getpi(p);

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];

		if (s[i] == p[j]) {
			if (j == m - 1) return true;
			else j++;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string ans = "-1";
	bool flag = false;
	auto pi = getpi(str);
	int idx = str.size();
	while (true) {
		idx = pi[idx-1];
		if (idx == 0) break;

		string tmp = str.substr(0, idx);
//		cout << tmp << endl;

		if (kmp(str.substr(1, str.size() - 2), tmp)) {
			ans = tmp;
			flag = true;
			break;
		}
	}
	if (flag)
		cout << ans << endl;
	else cout << -1 << endl;
}
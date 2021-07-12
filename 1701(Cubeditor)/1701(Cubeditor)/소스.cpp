#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<int> getpi(string& s) {
	int n = s.length(), j = 0;

	vector<int> pi(n, 0);

	for (int i = 1; i < n; i++) {
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) pi[i] = ++j;
	}
	return pi;
}

int answer = 0;

int main() {
	string str;
	cin >> str;

	int n = str.size();

	for (int i = 0; i < n; i++) {
		auto ans = getpi(str);
		for (int j = 0; j < ans.size(); j++) answer = max(answer, ans[j]);
		str = str.substr(1);
	}

	cout << answer << endl;
}
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

bool flag;
string s, t;

bool bfs(string f) {
	if (f.length() < s.length()) return false;
	if (f.length() == s.length()) return (s == f);
	bool flag = false;

	char s = f[0], e = f.back();
	int len = f.length();

	if (s == 'A') {
		if (e == 'A') flag |= bfs(f.substr(0, len - 1));
		else return false;
	}
	else {
		if(e=='A') flag |= bfs(f.substr(0, len - 1));
		reverse(f.begin(), f.end());
		f.pop_back();
		flag |= bfs(f);
	}
	return flag;
}

int main() {
	cin >> s >> t;
	printf("%d\n", bfs(t));
}
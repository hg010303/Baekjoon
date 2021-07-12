#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

string s;
string str[2];

int memo[110][21][2];

int f(int idx, int cnt, int flag) {
	if (cnt == s.size()) return 1;
	if (idx == str[0].size()) return 0;

	int& ret = memo[idx][cnt][flag];

	if (ret != -1) return ret;

	ret = f(idx + 1, cnt, flag);

	if (str[flag][idx] == s[cnt]) {
		ret += f(idx + 1, cnt + 1, 1 - flag);
	}

	return ret;
}

int main() {
	cin >> s;
	cin >> str[0] >> str[1];

	memset(memo, -1, sizeof(memo));

	cout << f(0, 0, 0) + f(0, 0, 1);
}
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string str;
vector<int> v;
bool zero = false;
bool three = false;

int ans = 0;


int main() {
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0') zero = true;
		ans += str[i] - '0';
		ans %= 3;
		v.push_back(str[i] - '0');
	}

	if (ans == 0) three = true;

	sort(v.begin(), v.end(), greater<int>());

	if (three == false || zero == false) cout << -1 << endl;
	else {
		for (int i = 0; i < str.size(); i++) cout << v[i];
	}
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


string s;
vector<string> str;

int main() {
	cin >> s;
	int a = s.size();

	for (int i = 0; i < a; i++) {
		str.push_back(s);
		s = s.substr(1);
	}

	sort(str.begin(), str.end());

	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << endl;
	}

}

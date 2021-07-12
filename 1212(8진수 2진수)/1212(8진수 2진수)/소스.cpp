#include<iostream>
#include<string>

using namespace std;


int main() {
	string str;
	string ans="";

	cin >> str;

	switch (str[0]) {
	case '1':
		ans += "1";
		break;
	case '2':
		ans += "10";
		break;
	case '3':
		ans += "11";
		break;
	case '4':
		ans += "100";
		break;
	case '5':
		ans += "101";
		break;
	case '6':
		ans += "110";
		break;
	case '7':
		ans += "111";
		break;
	}

	for (int i = 1; i < str.size(); i++) {
		switch (str[i]) {
		case '0':
			ans += "000";
			break;
		case '1':
			ans += "001";
			break;
		case '2':
			ans += "010";
			break;
		case '3':
			ans += "011";
			break;
		case '4':
			ans += "100";
			break;
		case '5':
			ans += "101";
			break;
		case '6':
			ans += "110";
			break;
		case '7':
			ans += "111";
			break;
		}
	}
	if (str == "0") cout << 0;
	else
		cout << ans;
}
#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	string ans;
	cin >> str;

	if (str.size() % 3 == 1) {
		if(str[0]=='1')
			ans.push_back(str[0]);
		for (int i = 1; i < str.size(); i += 3) {
			int a=0;
			if (str[i]=='1') a = 4;
			if (str[i + 1]=='1') a += 2;
			if (str[i + 2]=='1') a += 1;
			ans.push_back(a + '0');
		}
	}

	else if (str.size() % 3 == 2) {
		int a = 0;
		if (str[0]=='1') a += 2;
		if (str[1]=='1') a += 1;
		ans.push_back(a+'0');

		for (int i = 2; i < str.size(); i += 3) {
			int a=0;
			if (str[i]=='1') a = 4;
			if (str[i + 1]=='1') a += 2;
			if (str[i + 2]=='1') a += 1;
			ans.push_back(a + '0');
		}
	}
	else {
		for (int i = 0; i < str.size(); i += 3) {
			int a=0;
			if (str[i] == '1') a = 4;
			if (str[i + 1] == '1') a += 2;
			if (str[i + 2] == '1') a += 1;
			ans.push_back(a + '0');
		}
	}
	if (str == "0") cout << 0;
	else
		cout << ans;


}
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string str;
bool flag = false;
int result = 0;

int main() {
	cin >> str;
	string temp = "";
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (flag) result -= stoi(temp);
			else result += stoi(temp);
			temp = "";

			if (str[i] == '-') flag = true;
			continue;
		}
		temp += str[i];
	}
	cout<< result;
}
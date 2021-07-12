#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		if ((str[i] <= 'z' && str[i] >= 'a')) {

			str[i] += 13;
			if (!(str[i] <= 'z' && str[i] >= 'a')) str[i] -= 26;
		}
		if((str[i] <= 'Z' && str[i] >= 'A')){


			str[i] += 13;
			if (!((str[i] <= 'Z' && str[i] >= 'A'))) str[i] -= 26;
		}
	}
	cout << str;
}


#include<iostream>
#include<string>
#include<stack>

using namespace std;


int main() {
	string str;
	string listExp;
	cin >> str;

	stack<int> s;

	int cnt = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			listExp.push_back(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-') {
			if (s.empty()) {
				s.push(str[i]);
				continue;
			}
			char tmp = s.top();
			if (tmp == '(') s.push(str[i]);
			else {
				while (!s.empty() && tmp != '(') {
					s.pop();
					listExp.push_back(tmp);
					if (s.empty()) break;
					tmp = s.top();
				}
				s.push(str[i]);
			}

		}
		else if (str[i] == '*' || str[i] == '/') {
			if (s.empty()) {
				s.push(str[i]);
				continue;
			}
			char tmp = s.top();
			if (tmp == '(' || tmp == '+' || tmp == '-') s.push(str[i]);
			else {
				while (!s.empty() && (tmp =='*'||tmp=='/')) {
					s.pop();
					listExp.push_back(tmp);
					if (s.empty()) break;
					tmp = s.top();
				}
				s.push(str[i]);
			}

		}
		else if (str[i] == '(') s.push(str[i]);
		else if (str[i] == ')') {
			char tmp = s.top();
			s.pop();
			while (tmp != '(') {
				listExp.push_back(tmp);
				tmp = s.top();
				s.pop();
			}

		}

	}

	while (!s.empty()) {
		listExp.push_back(s.top());
		s.pop();
	}

	cout << listExp;


}
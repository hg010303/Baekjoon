#include<iostream>
#include<stack>
#include<string>
#include<cstdio>

using namespace std;

int arr[27];

int main() {
	int n;
	string str;
	stack<double> s;

	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();

			s.push(a + b);

		}
		else if (str[i] == '-') {
			double b = s.top();
			s.pop();
			double a = s.top();
			s.pop();

			s.push(a - b);
		}
		else if (str[i] == '*') {
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();

			s.push(a * b);
		}
		else if (str[i] == '/') {
			double b = s.top();
			s.pop();
			double a = s.top();
			s.pop();

			s.push(a / b);
		}
		else {
			s.push((double)arr[str[i] - 'A']);
		}
	}

	printf("%.2f", s.top());
}
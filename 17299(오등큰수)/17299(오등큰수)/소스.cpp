#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>

using namespace std;

int arr[1000100];
int f[1000100];
stack<int> s;
int ans[1000100];

int main() {
	int n;
	cin >> n;

	memset(ans, -1, sizeof(ans));

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		f[a] += 1;
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() && f[arr[s.top()]] < f[arr[i]]) {
			ans[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++) cout << ans[i] << " ";

}
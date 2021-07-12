#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
string str;
int ans = -987654321;

int cal(int a, int b, char oper) {
	int result = a;

	switch (oper) {
	case '+':
		result += b;
		break;
	case '-':
		result -= b;
		break;
	case '*':
		result *= b;
		break;
	}
	return result;
}

void dfs(int idx, int sum) {
	if(idx>n-1){
		ans = max(ans, sum);
		return;
	}

	if (idx == 0) {
		dfs(2, str[idx] - '0');
		return;
	}

	if (idx + 2 < n) {
		int now = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		dfs(idx + 4, cal(sum, now, str[idx - 1]));
	}
	dfs(idx + 2, cal(sum, str[idx] - '0', str[idx-1]));
}

int main() {
	cin >> n;
	cin >> str;

	dfs(0, 0);

	cout << ans << endl;
}
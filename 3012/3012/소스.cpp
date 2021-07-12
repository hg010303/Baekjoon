#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

const int CON = 100000;
const int MAX = 210;

int n;
string str;
int dp[MAX][110][110][110];
int ans = 0;

int f(int idx, int a, int b, int c) {
	if (idx == n) {
		if (a == 0 && b == 0 && c == 0) {
			return 1;
		}
		return 0;
	}

	if (a < 0 || b < 0 || c < 0) return 0;
	if (a > 100 || b > 100 || c > 100) return 0;


	int& ret = dp[idx][a][b][c];

	if (ret != -1) return ret;

	if (str[idx] == '(') return ret=f(idx+1, a + 1, b, c);
	if (str[idx] == '{') return ret=f(idx + 1, a, b + 1, c);
	if (str[idx] == '[') return ret=f(idx + 1, a, b, c + 1);
	if (str[idx] == ')') return ret=f(idx + 1, a - 1, b, c);
	if (str[idx] == '}') return ret=f(idx + 1, a, b - 1, c);
	if (str[idx] == ']') return ret=f(idx + 1, a, b, c - 1);



	if (str[idx] == '?') {
		int tmp = f(idx + 1, a, b, c - 1);
		tmp+= f(idx + 1, a, b - 1, c);
		tmp += f(idx + 1, a - 1, b, c);
		tmp+= f(idx + 1, a, b, c + 1);
		tmp+= f(idx + 1, a, b + 1, c);
		tmp+= f(idx + 1, a + 1, b, c);
		tmp %= CON;
		cout << idx << " " << a << " " << b << " " << c << " " << tmp << endl;
		return ret = tmp;

	}
	return 0;
}

int main() {
	cin >> n;
	cin >> str;
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0, 0, 0);
	
}
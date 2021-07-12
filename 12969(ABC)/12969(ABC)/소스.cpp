#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, k;
bool cache[31][31][31][450];

string ans="";

bool f(int N,int a, int b, int value, string str) {
	if (N == n) {
		if (value == k) {
			ans = str;
			return true;
		}
		else return false;
	}

	if (cache[N][a][b][value]) return false;
	cache[N][a][b][value] = true;
//	cout << str << endl;
	if (f(N + 1, a + 1, b, value, str + "A")) return true;
	if (f(N + 1, a, b + 1, value + a, str + "B")) return true;
	if (f(N + 1, a, b, value + a + b, str + "C")) return true;

	return false;
}

int main() {
	cin >> n >> k;

	f(0,0,0,0,"");

	if (ans == "") cout << -1;
	else cout << ans;
}
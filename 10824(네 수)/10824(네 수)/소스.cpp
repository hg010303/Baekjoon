#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;

	a += b;
	c += d;
	
	long long ans = atol(a.c_str()) + atol(c.c_str());

	cout << ans;

}
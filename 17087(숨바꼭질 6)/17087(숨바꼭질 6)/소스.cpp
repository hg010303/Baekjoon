#include<iostream>
#include<cmath>

using namespace std;

int arr[100100];

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int n, s;

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = abs(a-s);
	}

	int ans = arr[0];

	for (int i = 1; i < n; i++) {
		ans = gcd(ans, arr[i]);
	}

	cout << ans;



}
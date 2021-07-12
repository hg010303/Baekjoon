#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	long long arr[110];
	long long ans = 0;


	cin >> n;
	
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;

		ans ^= a;
	}

	if (ans == 0) cout << "cubelover";
	else cout << "koosaga";
}
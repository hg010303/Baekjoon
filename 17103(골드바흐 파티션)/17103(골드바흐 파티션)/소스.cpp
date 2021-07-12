#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int arr[1000001];
vector<int> prime;

int main() {
	
	for (int i = 1; i <= 1000000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= 1000000; i++) {
		if (arr[i] != i) continue;
		if (arr[i] == i) prime.push_back(i);
		int tmp = i;
		

		for (int j = 2; tmp * j <= 1000000; j++) {
			arr[tmp * j] = tmp;
		}
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int ans = 0;

		for (int i = 0; i < prime.size() && prime[i] < a; i++) {
			int b = a - prime[i];

			if (a - prime[i] < prime[i]) break;

			if (arr[a - prime[i]] == a - prime[i]) ans += 1;
		}
		cout << ans << endl;
	}
}
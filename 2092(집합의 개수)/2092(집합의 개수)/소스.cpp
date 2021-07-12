#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int CON = 1000000;

int t, a, s, b;
int arr[210];
int memo[210][4010];



int main() {
	cin >> t >> a >> s >> b;

	for (int i = 0; i < a; i++) {
		int k;
		cin >> k;

		arr[k]++;
	}

	for (int i = 1; i <= t; i++) {
		for (int j = 0; j <= arr[i]; j++) {
			memo[i][j]++;
		}
		for (int j = 1; j <= a; j++) {
			dp[i][j]
		}
	}

	sort(arr, arr + a);


}
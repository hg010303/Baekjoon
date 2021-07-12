#include<iostream>
#include<algorithm>

using namespace std;

int arr[1010];
int dp[1010];

int f(int n) {

	if (n == 0) return 0;
	if (dp[n]) return dp[n];
	int maxi = 987654321;

	for (int i = 1; i <= n; i++) {
		maxi = min(maxi, f(n - i) + arr[i]);
	}
	return dp[n]= maxi;
}


int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	cout<<f(n)<<endl;
	
}
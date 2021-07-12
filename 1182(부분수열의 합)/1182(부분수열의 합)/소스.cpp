#include<iostream>
#include<algorithm>

using namespace std;

int bit = 0;
int arr[30];
int answer = 0;
int n, s;

void dfs(int a,int sum) {
	if (a == n) return;

	if (sum + arr[a] == s) answer++;

	dfs(a + 1, sum);
	dfs(a + 1, sum + arr[a]);
}

int main() {


	cin >> n >> s;

	for (int i = 0; i < n; i++) cin >> arr[i];

	dfs(0, 0);

	cout << answer;
}
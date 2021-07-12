#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int n;
int arr[2100];
int cache[2100][2100];

int f(int s, int e) {
	if (s >= e) return 1;

	int& ret = cache[s][e];
	if (ret != -1) return ret;

	if (arr[s] == arr[e]) return ret = f(s + 1, e - 1);

	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	memset(cache, -1, sizeof(cache));

	int m;
	cin >> m;

	while (m--) {
		int s, e;
		cin >> s >> e;

		cout << f(s, e) << '\n';
	}
}
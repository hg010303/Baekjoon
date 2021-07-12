#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = -987654321;

int n;
int arr[51];
int memo[51][500100];
int ans = 0;


int f(int idx, int diff) {
	if (diff>500000) return INF;
	if (idx == n && diff) return INF;

	if (idx == n && diff == 0) return 0;

	int& ret = memo[idx][diff];
	if (ret != -1) return ret;

	ret = INF;
	ret = max(ret, f(idx + 1, diff));
	ret = max(ret, f(idx + 1, diff + arr[idx]));

	if (arr[idx] > diff) ret = max(ret, diff + f(idx + 1, arr[idx] - diff));
	else ret = max(ret, arr[idx] + f(idx + 1, diff - arr[idx]));
	
	return ret;
}

int main() {
	cin >> n;
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = f(0, 0);

	if (ans) cout << ans << endl;
	else cout << -1 << endl;
}
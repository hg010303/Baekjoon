#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int dp[4 * 1000][(1 << 4)];

int f(int now, int bin) {
	if (now >= 4 * n) {
		if (bin == 0) return 1;
		else return 0;
	}

	int& ret = dp[now][bin];
	if (ret != -1) return ret;
	ret = 0;

	int x = now / 4;
	int y = now % 4;

	if ((bin & 1) == 1) ret = f(now + 1, (bin >> 1));
	else {
		if (y != 3 && ((bin & 2) == 0)) ret += f(now + 2, bin >> 2);
		ret += f(now + 1, (bin >> 1) | 8);
	}

	return ret;
}

int main() {
	int T;
	cin >> T;

	

	while (T--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		cout << f(0,0)<<endl;
	}
}